#ifndef SYMBOL_H_
#define SYMBOL_H_

#include <string>

struct symbol_t
{
  std::string name;
  int type;
  int token;
  int address;
  bool isGlobal = true;
  bool isReference = false;
  std::vector<symbol_t> arguments;

};

#endif