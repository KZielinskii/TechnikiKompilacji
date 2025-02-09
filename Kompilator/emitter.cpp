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
    
    if(sym.token==NUM) {
        return ("#" + sym.name);
    }
    if(sym.token==VAR) {
        return std::to_string(sym.address);
    }
    return std::to_string(-1);
}


std::string symbolicOperand(int op) {
    if (op >= (int)symtable.size()) {
        return std::to_string(-1);
    }
    symbol_t sym = symtable.at(op);
    if(sym.token==NUM) {
        return sym.name;
    }
    if(sym.token==VAR) {
        return sym.name;
    }
    
    return std::to_string(-1);
}

void gencode_mov(int index1, int index2) {
    std::ostringstream oss;

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
    oss << "\t" << movType << "\t" << machineOperand(index1) << "," << machineOperand(index2);
    oss << "\t ; " << movType << " " << symbolicOperand(index1) << "," << symbolicOperand(index2);
    asmCode.push_back(oss.str());
}

void gencode_write(int index) {
    std::ostringstream oss;
    std::string writeType = (symtable[index].type == REAL) ? "write.r" : "write.i";

    oss << "\t" << writeType << "\t" << machineOperand(index);
    oss << "\t ; " << writeType << " " << symbolicOperand(index);
    asmCode.push_back(oss.str());
}

int gencode_op(std::string op, int index1, int index2) {
    std::ostringstream oss;
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
    
    oss << "\t" << op << "\t" << machineOperand(index1) << "," << machineOperand(index2) << "," << machineOperand(index3);
    oss << "\t ; " << op << " " << symbolicOperand(index1) << "," << symbolicOperand(index2) << "," << symbolicOperand(index3);
    asmCode.push_back(oss.str());
    
    return index3;
}

void gencode_intToReal(int index1, int index2) {
    std::ostringstream oss;
    oss << "\tinttoreal.i\t" << machineOperand(index1) << "," << machineOperand(index2);
    oss << "\t ; inttoreal.i " << symbolicOperand(index1) << "," << symbolicOperand(index2);
    asmCode.push_back(oss.str());
}

void gencode_realToInt(int index1, int index2) {
    std::ostringstream oss;
    oss << "\trealtoint.r\t" << machineOperand(index1) << "," << machineOperand(index2);
    oss << "\t ; realtoint.r " << symbolicOperand(index1) << "," << symbolicOperand(index2);
    asmCode.push_back(oss.str());
}



void saveAsmCode(std::string filename) {
    std::ofstream outFile(filename);
    
    outFile << "jump.i #lab0\t ;jump.i  lab0\n";
    outFile << "lab0:\n";

    for (const auto& line : asmCode) {
        outFile << line << "\n";
    }

    outFile << "\texit\t;exit\n";

    outFile.close();
}
