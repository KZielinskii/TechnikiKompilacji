#include "global.h"
#include <fstream>
#include <vector>
#include <sstream>

std::vector<std::string> asmCode;

std::string machineOperand(int op) {   
    if (op >= (int)symtable.size()) {
        std::cout << "Błąd index" << std::to_string(op) << "!\n"; 
        return std::to_string(-1);
    }
    symbol_t sym = symtable.at(op);
    
    if(sym.token==VAR) {
        return std::to_string(sym.address);
    }
    return ("#" + sym.name);
}


std::string symbolicOperand(int op) {
    if (op >= (int)symtable.size()) {
        return std::to_string(-1);
    }
    symbol_t sym = symtable.at(op);

    if(sym.token==VAR) {
        return sym.name;
    }
    
    return sym.name;
}

void gencode(std::string m, int index1, int index2, int index3) { // index = -1 jeżeli nie ma być wypisany
    std::ostringstream oss;
    oss << "\t" << m << "\t" << machineOperand(index1); 
    if(index2!=-1)
    oss << "," << machineOperand(index2); 
    if(index3!=-1)
    oss << "," << machineOperand(index3);


    oss << "\t ; " << m << " " << symbolicOperand(index1);
    if(index2!=-1)
    oss << "," << symbolicOperand(index2);
    if(index3!=-1)
    oss << "," << symbolicOperand(index3);
    asmCode.push_back(oss.str());
}

void gencode_label(int index) {
    std::ostringstream oss;
    oss << symtable[index].name << ":";
    asmCode.push_back(oss.str());
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

    gencode("trealtoint.r", index1, index2, -1);
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

    int indexLabel = newLabel();
    gencode(opType, index1, index2, indexLabel);

    return indexLabel;
}

// index label stworzonego w relop
int gencode_if(int index1) {
    int newTempIndex = newTemp(INT); //int bo ma przechować 0 lub 1 jeśli jest prawdziwe
    int newNumberIndex = newNumber(0);

    gencode("mov.i", newNumberIndex, newTempIndex,-1);

    int newLabelIndex = newLabel();
    gencode("jump.i", newLabelIndex, -1, -1);
    gencode_label(index1);

    newNumberIndex = newNumber(1);
    gencode("mov.i", newNumberIndex, newTempIndex,-1);
    gencode_label(newLabelIndex);

    return newTempIndex;
}

// index temp sworzonego w if
int gencode_then(int index1) {
    int newNumberIndex = newNumber(0);
    int newLabelIndex = newLabel();

    gencode("je.i", index1, newNumberIndex, newLabelIndex);

    return newLabelIndex;
}

//index label sworzonego w then
int gencode_else(int index1) {
    int newLabelIndex = newLabel();
    gencode("jump.i", newLabelIndex, -1, -1);

    gencode_label(index1);
    return newLabelIndex;
}

void gencode_endif(){};


void saveAsmCode(std::string filename) {
    std::ofstream outFile(filename);
    
    outFile << "\tjump.i #lab0\t ;jump.i  lab0\n";
    outFile << "lab0:\n";

    for (const auto& line : asmCode) {
        outFile << line << "\n";
    }

    outFile << "\texit\t;exit\n";

    outFile.close();
}

//todo not factor w factor