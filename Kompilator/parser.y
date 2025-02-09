%{
#include "global.h"

int errorno = 0;
int tempCountAddress = 0;
std::vector<int> listID;

bool isType(int);
int yylex();
void yyerror(const char* s);
%}

%token PROGRAM ID INT REAL VAR NUM LABEL PROC NONE BEG END ASSIGN ADDOP MULOP WRITE READ

%%

program:
    PROGRAM ID '(' identifier_list ')' ';'
    declarations 
    compound_statement 
    '.'
    ;

identifier_list:
    ID { listID.push_back($1); }
    | identifier_list ',' ID { listID.push_back($3); }
    ;

declarations:
    declarations VAR identifier_list ':' type ';' { 
        int size = ($5 == INT) ? 4 : 8;
        for (int id : listID) {
            symtable[id].type = $5;
            symtable[id].token = VAR;
            symtable[id].address = tempCountAddress;
            tempCountAddress += size;
        }
        listID.clear();
    }
    | /* empty */
    ;

type:
    INT
    | REAL
    ;

compound_statement:
    BEG statement_list END
    ;

statement_list:
    statement
    | statement_list ';' statement
    ;

statement:
    variable ASSIGN expression { 
        std::string movType = (symtable[$1].type == REAL || symtable[$3].type == REAL) ? "mov.r" : "mov.i";
        emit_mov(movType, $3, $1);
    }
    | WRITE '(' variable ')' { 
        std::string writeType = (symtable[$3].type == REAL) ? "write.r" : "write.i";
        emit_write(writeType, $3);
    }
    ;

variable:
    ID
    ;

expression:
    simple_expression
    ;

simple_expression:
    term { $$ = $1; }
    | simple_expression ADDOP term { 
        int tempVar = tempCountAddress;
        tempCountAddress += (isReal($1) || isReal($3)) ? 8 : 4;

        if ($2 == ADD) {
            if (isReal($1) || isReal($3)) {
                $$ = emit_op("add.r", $1, $3, tempVar);
            } else {
                $$ = emit_op("add.i", $1, $3, tempVar);
            }
        }
        else if ($2 == SUB) {
            if (isReal($1) || isReal($3)) {
                $$ = emit_op("sub.r", $1, $3, tempVar);
            } else {
                $$ = emit_op("sub.i", $1, $3, tempVar);
            }
        }
    }
    ;

term:
    factor { $$ = $1; }
    | term MULOP factor {
        int tempVar = tempCountAddress;
        tempCountAddress += (isReal($1) || isReal($3)) ? 8 : 4;

        if ($2 == MUL) {
            if (isReal($1) || isReal($3)) {
                $$ = emit_op("mul.r", $1, $3, tempVar);
            } else {
                $$ = emit_op("mul.i", $1, $3, tempVar);
            }
        }
        else if ($2 == DIV) {
            if (isReal($1) || isReal($3)) {
                $$ = emit_op("div.r", $1, $3, tempVar);
            } else {
                $$ = emit_op("div.i", $1, $3, tempVar);
            }
        }
        else if ($2 == MOD) {
            if (isReal($1) || isReal($3)) {
                $$ = emit_op("mod.r", $1, $3, tempVar);
            } else {
                $$ = emit_op("mod.i", $1, $3, tempVar);
            }
        }
    }

factor:
    variable { $$ = $1; }
    | NUM { $$ = $1; }
    | '(' expression ')'  { $$ = $2; }
    ;

%%

void yyerror(const char* s) {
    printf("\n\nBłąd \"%s\" w linii %d\n", s, lineno);
    errorno++;
}

const char *token_name(int token) {
    return yytname[YYTRANSLATE(token)];
}
