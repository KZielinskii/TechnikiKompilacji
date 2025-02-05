#include "global.h"
#include <fstream>
#include <vector>
#include <sstream>

std::vector<std::string> asmCode;

int tempRegCounter = 12;  // Rejestry tymczasowe zaczynają się od 12

int getTemp() {
    return tempRegCounter++;
}

// Funkcja zwracająca operand dla maszyny (czyli taki, jaki ma trafić do wygenerowanego kodu)
std::string machineOperand(int op) {
    // Jeżeli op jest indeksem w tabeli symboli i odpowiada literałowi
    if (op < (int)symtable.size()) {
        const symbol_t &sym = symtable[op];
        if (sym.token == VAL) {
            return "#" + sym.name;  // np. "#1"
        }
    }
    // Jeśli istnieje zmienna (token ID) o adresie równym op, zwracamy adres numerycznie
    for (const auto &sym : symtable) {
        if (sym.token == ID && sym.address == op) {
            return std::to_string(op);  // np. "0" lub "4"
        }
    }
    // W przeciwnym razie traktujemy op jako numer rejestru tymczasowego.
    int tempBase = 8;  // ustaliliśmy, że getTemp() zaczyna od 8
    int regIndex = op - tempBase;
    return "$t" + std::to_string(regIndex);
}

// Funkcja zwracająca operand symboliczny (do komentarza)
std::string symbolicOperand(int op) {
    if (op < (int)symtable.size()) {
        const symbol_t &sym = symtable[op];
        if (sym.token == VAL) {
            return sym.name;  // np. "1"
        }
    }
    for (const auto &sym : symtable) {
        if (sym.token == ID && sym.address == op) {
            return sym.name;  // np. "a" lub "b"
        }
    }
    int tempBase = 8;
    int regIndex = op - tempBase;
    return "$t" + std::to_string(regIndex);
}


void emit(std::string op, int src, int dest) {
    std::ostringstream oss;
    oss << "\t" << op << "\t" << machineOperand(src) << "," << machineOperand(dest);
    oss << "\t ; " << op << " " << symbolicOperand(src) << "," << symbolicOperand(dest);
    asmCode.push_back(oss.str());
}

void emit(std::string op, int dest) {
    std::ostringstream oss;
    oss << "\t" << op << "\t" << machineOperand(dest);
    oss << "\t ; " << op << " " << symbolicOperand(dest);
    asmCode.push_back(oss.str());
}

void emit(std::string op, int src1, int src2, int dest) {
    std::ostringstream oss;
    oss << "\t" << op << "\t" << machineOperand(src1) << "," << machineOperand(src2) << "," << machineOperand(dest);
    oss << "\t ; " << op << " " << symbolicOperand(src1) << "," << symbolicOperand(src2) << "," << symbolicOperand(dest);
    asmCode.push_back(oss.str());
}



void saveAsmCode(std::string filename) {
    std::ofstream outFile(filename);
    
    outFile << "jump.i #lab0\n";
    outFile << "lab0:\n";

    for (const auto& line : asmCode) {
        outFile << line << "\n";
    }

    outFile << "\texit\n";

    outFile.close();
}
