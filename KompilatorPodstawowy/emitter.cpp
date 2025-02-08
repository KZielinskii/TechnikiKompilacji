#include "global.h"
#include <fstream>
#include <vector>
#include <sstream>

std::vector<std::string> asmCode;

std::string machineOperand(int op) {    
    for (const auto &sym : symtable) {
        if (sym.address == op && sym.token == VAL) {
            return "#" + sym.name;
        }
        if (sym.address == op && sym.token == VAR && sym.type == INT) {
            return std::to_string(sym.address);
        }
    }
    
    return std::to_string(-1);
}


std::string symbolicOperand(int op) {
    
    for (const auto &sym : symtable) {
        if (sym.address == op && sym.token == VAL)
            return sym.name;
        if (sym.address == op && sym.token == ID && sym.type == INT)
            return sym.name;
    }
    
    return "$t" + std::to_string(-1);
}



void emit_mov(std::string op, int address1, int address2) {
    std::ostringstream oss;
    oss << "\t" << op << "\t" << machineOperand(address1) << "," << machineOperand(address2);
    oss << "\t ; " << op << " " << symbolicOperand(address1) << "," << symbolicOperand(address2);
    asmCode.push_back(oss.str());
}

void emit_write(std::string op, int address) {
    std::ostringstream oss;
    oss << "\t" << op << "\t" << machineOperand(address);
    oss << "\t ; " << op << " " << symbolicOperand(address);
    asmCode.push_back(oss.str());
}

void emit_op(std::string op, int address1, int address2, int address3) {
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

    outFile << "\texit\n";

    outFile.close();
}
