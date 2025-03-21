#include "global.h"
#include <fstream>
#include <vector>
#include <sstream>

std::vector<std::string> asmCode;

bool inFunctionMode = false;
std::vector<std::string> functionBuffer;

std::string machineOperand(int index) {   
    if (index >= (int)symtable.size()) {
        std::cout << "Błąd index" << std::to_string(index) << "!\n"; 
        return std::to_string(-1);
    }
    symbol_t sym = symtable.at(index);
    if (sym.token != VAR && sym.token != FUNCTION && !sym.isReference) {
        return ("#" + sym.name);
    }
    std::string ret = "";
    
    if(sym.isReference || sym.token == FUNCTION) {
        ret += "*";
    }
    if(!sym.isGlobal || sym.token == FUNCTION) {
        ret += "BP";
        ret += (sym.address>=0 ? "+": "");
    }
    
    ret += std::to_string(sym.address);
    return ret;
}


std::string symbolicOperand(int index) {
    if (index >= (int)symtable.size()) {
        return std::to_string(-1);
    }
    symbol_t sym = symtable.at(index);

    if(sym.token==VAR) {
        return sym.name;
    }
    
    return sym.name;
}

void addCodeLine(const std::string &line) {
    if (inFunctionMode)
        functionBuffer.push_back(line);
    else
        asmCode.push_back(line);
}

void gencode(std::string m, int index1, int index2, int index3) { // index = -1 jeżeli nie ma być wypisany
    std::ostringstream oss;

    oss << "\t" << m << "\t";
    if(index1!=-1)
    oss << machineOperand(index1); 
    if(index2!=-1)
    oss << "," << machineOperand(index2); 
    if(index3!=-1)
    oss << "," << machineOperand(index3);

    oss << "\t\t\t ; " << m << " ";
    if(index1!=-1)
    oss << symbolicOperand(index1);
    if(index2!=-1)
    oss << "," << symbolicOperand(index2);
    if(index3!=-1)
    oss << "," << symbolicOperand(index3);
    addCodeLine(oss.str());
}

void gencode_ref(std::string m, int index1, int index2) { // index = -1 jeżeli nie ma być wypisany
    std::ostringstream oss;
    oss << "\t" << m << "\t";
    if(index1!=-1)
    oss << ((symtable[index1].token == VAR)? "#" : "") << machineOperand(index1); 
    if(index2!=-1)
    oss << "," << machineOperand(index2); 

    oss << "\t\t\t ; " << m << " ";
    if(index1!=-1)
    oss << "&" << symbolicOperand(index1);
    if(index2!=-1)
    oss << "," << symbolicOperand(index2);

    std::string codeLine = oss.str();
    size_t pos;
    while ((pos = codeLine.find("#*")) != std::string::npos) {
        codeLine.replace(pos, 2, " ");
    }

    addCodeLine(codeLine);
}

void gencode_label(int index) {
    std::ostringstream oss;
    oss << symtable[index].name << ":";
    addCodeLine(oss.str());
}

void gencode_mov(int index1, int index2) {
    if(symtable[index1].type != symtable[index2].type) {
        int tempIndex = newTemp(symtable[index2].type);
        if(symtable[index2].type == INT) {
            gencode_realToInt(index1, tempIndex);
        } else {
            gencode_intToReal(index1, tempIndex);
        }
        index1 = tempIndex;
    }

    std::string movType = (symtable[index2].type == REAL) ? "mov.r" : "mov.i";
    
    gencode(movType, index1, index2, -1);
}

void gencode_write(int index) {
    std::string writeType = (symtable[index].type == REAL) ? "write.r" : "write.i";

    gencode(writeType, index, -1, -1);
}

void gencode_read(int index) {
    std::string writeType = (symtable[index].type == REAL) ? "read.r" : "read.i";
    gencode(writeType, index, -1, -1);
}

int gencode_op(std::string op, int index1, int index2) {
    bool isReal = (symtable[index1].type == REAL || symtable[index2].type == REAL);
    
    if (symtable[index1].type != symtable[index2].type) {
        int tempIndex = newTemp(REAL);
        if (symtable[index1].type == INT) {
            gencode_intToReal(index1, tempIndex);
            index1 = tempIndex;
        } else {
            gencode_intToReal(index2, tempIndex);
            index2 = tempIndex;
        }
    }
    
    int index3 = newTemp(isReal ? REAL : INT);
    op += (isReal ? ".r" : ".i");

    gencode(op, index1, index2, index3);
    return index3;
}

void gencode_intToReal(int index1, int index2) {
   
    gencode("inttoreal.i", index1, index2, -1);
}

void gencode_realToInt(int index1, int index2) {

    gencode("realtoint.r", index1, index2, -1);
}

int gencode_relop(int op, int index1, int index2) {

    bool isReal = (symtable[index1].type == REAL);
    std::string endType = (isReal ? "r" : "i");

    std::string opType;
    switch(op) {
        case E: opType = "je." + endType; break;
        case NE: opType = "jne." + endType; break;
        case LE: opType = "jle." + endType; break;
        case GE: opType = "jge." + endType; break;
        case G: opType = "jg." + endType; break;
        case L: opType = "jl." + endType; break;
        default:
            std::cout << "Nieznany operator relacyjny!\n";
            return -1;
    }

    int trueConditionLabel = newLabel();
    gencode(opType, index1, index2, trueConditionLabel);
    
    int resultTempIndex = newTemp(INT); //int bo ma przechować 0 lub 1 jeśli jest prawdziwe
    int newNumberIndex = newNumber(0);
    int exitLabel = newLabel();

    gencode("mov.i", newNumberIndex, resultTempIndex,-1);
    gencode("jump.i", exitLabel, -1, -1);
    gencode_label(trueConditionLabel);
    newNumberIndex = newNumber(1);
    gencode("mov.i", newNumberIndex, resultTempIndex,-1);
    gencode_label(exitLabel);

    return resultTempIndex;

}

int gencode_then(int index1) {
    int newNumberIndex = newNumber(0);
    int elseLabel = newLabel();
    gencode("je.i", index1, newNumberIndex, elseLabel);

    return elseLabel;
}

int gencode_else(int index1) {
    int exitLabel = newLabel();
    gencode("jump.i", exitLabel, -1, -1);
    gencode_label(index1);

    return exitLabel;
}

int gencode_while() {
    int loopStartLabel = newLabel();
    gencode_label(loopStartLabel);
    return loopStartLabel;
}

//index1 label stworzonego w relop, index2 label do którego skok z while
void gencode_while_do(int index1, int index2) {
    int newNumberIndex = newNumber(0);
    gencode("je.i", index1, newNumberIndex, index2);
}

// index1 label do którego skok kiedy niespełnion index2 label spełniono
void gencode_end_while(int index1, int index2) {
    gencode("jump.i", index2, -1, -1);
    gencode_label(index1);
}

// index operanda do not'owania
int gencode_not(int index) {
    int indexToNot = index;
    if(symtable[index].type == REAL) {
        int newIndexTemp = newTemp(INT);
        gencode_realToInt(index, newIndexTemp);
        indexToNot = newIndexTemp;
    }
    int notConditionLabel = newLabel();
    symtable[notConditionLabel].type = INT;
    int newIndexNumber = newNumber(0);
    gencode("je.i", indexToNot, newIndexNumber, notConditionLabel);
    return notConditionLabel;
}

//index operanda przed którym jest -
int gencode_sign(int index) {
    int newIndexTemp = newTemp(symtable[index].type);
    int newIndexNumber = newNumber(0);
    std::string type = (symtable[index].type == REAL ? "sub.r" : "sub.i");
    gencode(type, newIndexNumber, index, newIndexTemp);
    return newIndexTemp;
}

void gencode_startFunc() {
    inFunctionMode = true;
    functionBuffer.clear();
}

void gencode_push(int index, symbol_t expected) {
    symbol_t arg = symtable[index];
    int pushIndex = index;
    //tworzymy nową zmienną dla liczby
    if(arg.token == NUM) {
        int newIndexTemp = newTemp(expected.type);
        gencode_mov(index, newIndexTemp);
        pushIndex = newIndexTemp;
    } else {
        if (symtable[index].type != expected.type) {
            if (symtable[index].type == INT && expected.type == REAL) {
                int tempIndex = newTemp(REAL);
                gencode_intToReal(index, tempIndex);
                pushIndex = tempIndex;
            } 
            else if(symtable[index].type == REAL && expected.type == INT) {
                int tempIndex = newTemp(INT);
                gencode_realToInt(index, tempIndex);
                pushIndex = tempIndex;
            } else {
                yyerror("Typy argumentów funkcji się nie zgadzają!");
            }
        }
    }

    gencode_ref("push.i", pushIndex, -1);
}

void gencode_call(int index) {
    std::ostringstream oss;

    symbol_t sym = symtable[index];
    oss << "\t" << "call.i" << "\t" << "#" << sym.name << "\t";
    oss << "; " << "call.i" << " " << "&" << sym.name;
    addCodeLine(oss.str());
}

void gencode_incsp(int incsp) {
    gencode("incsp.i", incsp, -1, -1);
}

//index offset
void gencode_endFunc(int index)
{
    inFunctionMode = false;
    gencode("enter.i", index, -1, -1);
    for (auto &line : functionBuffer) {
        asmCode.push_back(line);
    }
    functionBuffer.clear();
    gencode("leave", -1, -1, -1);
    gencode("return", -1, -1, -1);
}

int gencode_logic(std::string op, int index1, int index2) {
    int index3 = newTemp(INT);
    gencode(op + ".i", index1, index2, index3);
    return index3;
}


void saveAsmCode(std::string filename) {
    std::ofstream outFile(filename);
    
    outFile << "\tjump.i #lab0\t ;jump.i  lab0\n";

    for (const auto& line : asmCode) {
        outFile << line << "\n";
    }

    outFile << "\texit\t;exit\n";

    outFile.close();
}

