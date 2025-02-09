#include "global.h"
#include <fstream>
#include <vector>
#include <sstream>

std::vector<std::string> asmCode;

std::string machineOperand(int op) {   
    if (op >= (int)symtable.size()) {
        std::cout << "Błąd index" << std::to_string(op) << "!!!!!!!!!!\n"; 
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



void emit_mov(std::string op, int index1, int index2) {
    std::ostringstream oss;
    
    oss << "\t" << op << "\t" << machineOperand(index1) << "," << machineOperand(index2);
    oss << "\t ; " << op << " " << symbolicOperand(index1) << "," << symbolicOperand(index2);
    asmCode.push_back(oss.str());
}

void emit_write(std::string op, int address) {
    std::ostringstream oss;
    oss << "\t" << op << "\t" << machineOperand(address);
    oss << "\t ; " << op << " " << symbolicOperand(address);
    asmCode.push_back(oss.str());
}

void emit_op(std::string op, int address1, int address2, int address3) {
    newTemp(INT, address3);
    std::ostringstream oss;
    oss << "\t" << op << "\t" << machineOperand(address1) << "," << machineOperand(address2) << "," << machineOperand(address3);
    oss << "\t ; " << op << " " << symbolicOperand(address1) << "," << symbolicOperand(address2) << "," << symbolicOperand(address3);
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
