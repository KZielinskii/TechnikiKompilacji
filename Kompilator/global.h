#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string.h>
#include "tokens.h"
#include "symbol.h"
#include "parser.hpp"

extern std::vector<symbol_t> symtable;

extern int lineno;
extern int errorno;

int yylex_destroy();

int insert(std::string name, int token, int type);
int lookup(std::string name);

void initSymtable();
int getAddress(std::string name);
int tempSymbol(int);
int newNum(std::string, int);
int yyparse();
void yyerror(char const *);
const char *token_name(int);
int getOperationToken(std::string);
void printSymtable();

std::string format(symbol_t s);
void writeCode(std::string line, std::string addInfo);
void writeLabel(std::string label);


int realToInt(symbol_t from, symbol_t to);
int intToReal(symbol_t from, symbol_t to);
int appendMulOP(symbol_t, int, symbol_t);
int appendAddOP(symbol_t, int, symbol_t);
void appendAssign(symbol_t left_side, symbol_t right_side);
void appendWrite(symbol_t symbolToWrite);
void appendRead(symbol_t symbolToRead);

void saveAsmCode(std::string);