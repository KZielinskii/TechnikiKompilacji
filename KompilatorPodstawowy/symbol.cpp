#include "global.h"

std::vector<symbol_t> symtable;
int tempCount = 0;

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
    newSymbol.address = symtable.size() * 4;  // Przykładowe przypisanie adresu

    symtable.push_back(newSymbol);
    return symtable.size() - 1;  // Zwracamy indeks nowego symbolu
}


void printSymtable()
{
  int name = 0, token = 0, type = 0;
  for (auto symbol : symtable)
  {
    if (name < (int)symbol.name.length()) {
      name = symbol.name.length();
    } 

    std::string tok = std::string(token_name(symbol.token));

    if (token < (int)tok.length()) {
      token = tok.length();
    }

    std::string type = std::string(token_name(symbol.type));

    if (token < (int)type.length()) {
      token = type.length();
    } 
  }

  std::cout << "\n\n" << "Tabela symboli: " << "\n";
  int i = 0;
  for (auto symbol : symtable)
  {
    std::cout
        << std::setw(std::to_string(symtable.size()).length()) << i++ << " "
        << std::setw(token + 2) << token_name(symbol.token) << " "
        << std::setw(name + 2) << symbol.name << " "
        << std::setw(type + 2) << token_name(symbol.type)
        << ((symbol.type == INT) ? " " : "")
        << ((symbol.token == VAR) ? "\t" + std::to_string(symbol.address) : "")
        << std::endl;
  }
}
