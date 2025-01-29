#include "global.h"
#include <sstream>
#include <iostream>
#include <fstream>

std::stringstream outputStream;

std::string addop(int op)
{
  if(op == ADD) return "add.";
  if(op == SUB) return "sub.";
  return "ERROR";
}

std::string mulop(int op)
{
  if(op == MUL) return "mul.";
  if(op == DIV) return "div.";
  if(op == MOD) return "mod.";
  return "ERROR";
}

std::string sign(int a)
{
  return a < 0 ? "-" : "+";
}

std::string format(symbol_t symbol)
{
  if (symbol.token == LABEL || symbol.token == VAL) {
    return "#" + symbol.name;
  }
  else if (symbol.token == VAR) {
    return std::to_string(abs(symbol.address));
  }
  return "";
}

void writeCode(std::string line, std::string addInfo)
{
  outputStream << "\t" << line << "\t|\t" << addInfo << std::endl;
}

void writeLabel(std::string label)
{
  outputStream << label + ":" << std::endl;
}

std::string typeInAsm(int type)
{
  return "i";  // Zamiast r - tylko int
}

void appendAssign(symbol_t left, symbol_t right)
{
  if (left.type != right.type) {
    yyerror(("Error typing: " + std::string(token_name(left.type)) + " with " + std::string(token_name(right.type))).c_str());
  }

  writeCode("mov.i\t\t" + format(right) + "," + format(left) + "\t", "mov.i\t\t" + (right.name) + "," + (left.name));
}

symbol_t willChange(symbol_t left, symbol_t right)
{
  if (left.type != right.type) {
    yyerror(("Error typing: " + std::string(token_name(left.type)) + " with " + std::string(token_name(right.type))).c_str());
  }
  return right;
}

int appendAddOP(symbol_t left, int operacja, symbol_t right)
{
  symbol_t new_left = willChange(right, left);

  int result = tempSymbol(new_left.type);
  writeCode(addop(operacja) + typeInAsm(new_left.type) + "\t\t" + format(new_left) + "," + format(right) + "," + format(symtable[result]) + "\t", addop(operacja) + typeInAsm(new_left.type) + "\t\t" + new_left.name + "," + right.name + "," + (symtable[result].name));

  return result;
}

int appendMulOP(symbol_t left, int operacja, symbol_t right)
{
  symbol_t new_left = willChange(right, left);

  int result = tempSymbol(new_left.type);
  writeCode(mulop(operacja) + typeInAsm(new_left.type) + "\t\t" + format(new_left) + "," + format(right) + "," + format(symtable[result]) + "\t", mulop(operacja) + typeInAsm(new_left.type) + "\t\t" + new_left.name + "," + right.name + "," + (symtable[result].name));

  return result;
}

std::string formatRef(symbol_t symbol)
{
  if (symbol.token == VAL || symbol.token == LABEL) {
    return "#" + symbol.name;
  }
  else if (symbol.token == VAR) {
    return std::to_string(abs(symbol.address));
  }
  return "";
}

void appendWrite(symbol_t symbol)
{
  writeCode("write." + typeInAsm(symbol.type) + "\t\t" + format(symbol) + "\t", "write." + typeInAsm(symbol.type) + "\t\t" + (symbol.name));
}

void appendRead(symbol_t symbol)
{
  writeCode("read." + typeInAsm(symbol.type) + "\t\t" + format(symbol) + "\t", "read." + typeInAsm(symbol.type) + "\t\t" + (symbol.name));
}

void saveAsmCode(std::string fname)
{
  std::ofstream outFile(fname);
  outFile << outputStream.str();
  outFile.close();
  std::cout << outputStream.str() << std::endl;
}
