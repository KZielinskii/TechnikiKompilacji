#include "global.h"

std::vector<symbol_t> symtable;
int tempCounter = 0;
int labelCounter = 0;

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
    int size = (type == INT) ? 4 : 8;
    if (contextGlobal) {
        newSymbol.address = getTempAddress(size);
    } else {
        newSymbol.address = getLocalAddress(size);
    }
    newSymbol.isGlobal = contextGlobal;
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

int newNumber(int number) {
    symbol_t newSymbol;
    newSymbol.name = std::to_string(number);
    newSymbol.token = NUM;
    newSymbol.type = INT;
    newSymbol.isGlobal = contextGlobal;

    symtable.push_back(newSymbol);
    return symtable.size() - 1;
}

symbol_t newArgument(int type)
{
  symbol_t newSymbol;
  newSymbol.name = "arg";
  newSymbol.type = type;
  newSymbol.token = NONE;
  newSymbol.isGlobal = contextGlobal;

  newSymbol.address = 0xFFFF;
  return newSymbol;
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
        << i++ << " " << token_name(symbol.token) << "\t" << symbol.name << "\t" << ((symbol.token == VAR || symbol.token == FUNCTION) ? ((symbol.type == INT) ? "INT" : "REAL") : "") << "\t"
        << ((symbol.token == VAR) ? "\t" + std::to_string(symbol.address) : "")<< " " <<(symbol.isGlobal ? "GLOBAL" : "LOCAL") <<std::endl;
  }
}
