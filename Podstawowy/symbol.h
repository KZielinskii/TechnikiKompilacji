#ifndef SYMBOL_H_
#define SYMBOL_H_

#include <string>

struct symbol_t
{
  std::string name;
  int token;
  int type;
  int address;
};

#endif