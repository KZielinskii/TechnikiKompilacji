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
extern int tempCountAddress;

int yylex_destroy();

int insert(std::string name, int token, int type);
int newTemp(int type, int address);
bool isReal(int index);

void initSymtable();
void printSymtable();
void saveAsmCode(std::string);
int getOperationToken(std::string);
const char *token_name(int);

void emit_mov(std::string op, int src, int dest);
void emit_write(std::string op, int dest);
int emit_op(std::string op, int src1, int src2, int dest);
