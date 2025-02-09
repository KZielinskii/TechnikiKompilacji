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
int getTempAddress(int size);

int insert(std::string name, int token, int type);
int newTemp(int type);
bool isReal(int index);

void initSymtable();
void printSymtable();
void saveAsmCode(std::string);
int getOperationToken(std::string);
const char *token_name(int);

void gencode_mov(int index1, int index2);
void gencode_write(int index);
int gencode_op(std::string op, int index1, int index2);
void gencode_intToReal(int index1, int index2);
void gencode_realToInt(int index1, int index2);

