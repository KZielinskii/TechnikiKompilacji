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

int lookup(const std::string name)
{
  for (int p = symtable.size() - 1; p > 0; p--) {
    if (symtable[p].name == name) return p;
  }
  return -1;
}

int insertSymbol(symbol_t symbol)
{
  symtable.push_back(symbol);
  return symtable.size() - 1;
}

int insert(std::string name, int token, int type)
{
  int look = lookup(name);
  if (look >= 0) return look;
  symbol_t symbol;
  symbol.name = name;
  symbol.token = token;
  symbol.type = type;
  return insertSymbol(symbol);
}

int tempSymbol(int type)
{
  symbol_t t;
  t.name = "$t" + std::to_string(tempCount);
  t.type = type;
  t.token = VAR;
  t.address = 0;
  int index = insertSymbol(t);
  symtable[index].address = getAddress(t.name);
  tempCount++;
  return index;
}

int newNum(std::string name, int type)
{
  return insert(name, VAL, type);
}

int getSymbolSize(symbol_t symbol)
{
  if (symbol.token != VAR) return 0;
  if (symbol.type == INT) return 4;
  return 0;
}

int getAddress(std::string name)
{
  int address = 0;
  for (auto symbol : symtable) {
    if (symbol.name != name) {
      address += getSymbolSize(symbol);
    }
  }
  return address;
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
