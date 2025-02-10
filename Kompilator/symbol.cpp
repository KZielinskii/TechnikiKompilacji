#include "global.h"

std::vector<symbol_t> symtable;
int tempCounter = 0;
int labelCounter = 1;

void initSymtable()
{
  symbol_t read;
  read.name = "read";
  read.token = PROC;
  read.type = NONE;

  symbol_t write;
  write.name = "write";
  write.token = PROC;
  write.type = NONE;

  symtable.push_back(read);
  symtable.push_back(write);
}

int insert(std::string name, int token, int type) {
    for (size_t i = 0; i < symtable.size(); i++) {
        if (symtable[i].name == name) {
            return i;  // Symbol już istnieje, zwracamy jego indeks
        }
    }

    symbol_t newSymbol;
    newSymbol.name = name;
    newSymbol.token = token;
    newSymbol.type = type;
    newSymbol.address = 0;

    symtable.push_back(newSymbol);
    return symtable.size() - 1;  // Zwracamy indeks nowego symbolu
}

int newTemp(int type) {
    symbol_t newSymbol;
    newSymbol.name = "t"+ std::to_string(tempCounter);
    newSymbol.token = VAR;
    newSymbol.type = type;
    newSymbol.address = getTempAddress((type == INT) ? 4 : 8);
    tempCounter++;

    symtable.push_back(newSymbol);
    return symtable.size() - 1;
}

int newLabel() { 
  symbol_t newSymbol;
  newSymbol.name = "lab"+ std::to_string(labelCounter);
  newSymbol.token = LABEL;
  labelCounter++;

  symtable.push_back(newSymbol);
  return symtable.size() - 1;
}

bool isReal(int index) {
  return symtable[index].type == REAL;
}


void printSymtable()
{
  std::cout << "\n\n" << "Tabela symboli: " << "\n";
  int i = 0;
  for (auto symbol : symtable)
  {
    std::cout
        << i++ << " " << token_name(symbol.token) << "\t" << symbol.name << "\t" << ((symbol.token == VAR) ? ((symbol.type == INT) ? "INT" : "REAL") : "") << "\t"
        << ((symbol.token == VAR) ? "\t" + std::to_string(symbol.address) : "")<< std::endl;
  }
}
