%{
#include "global.h"

int errorno = 0;
int tempCountAddress = 0;
std::vector<int> listID;

bool isType(int);
int yylex();
void yyerror(const char* s);
%}

%token PROGRAM ID INT VAR VAL LABEL PROC NONE BEG END ASSIGN ADDOP MULOP NUM WRITE READ

%%

program:
    PROGRAM ID '(' program_arguments ')' ';'
    declarations compound_statement '.'
    ;

program_arguments:
    ID 
    | program_arguments ',' ID;

identifier_list:
    ID { listID.push_back($1); }
    | identifier_list ',' ID { listID.push_back($3); }
    ;

declarations:
    declarations VAR identifier_list ':' INT ';' { 
        for (int id : listID) {
            symtable[id].type = INT;
            symtable[id].token = VAR;
            symtable[id].address = tempCountAddress;
            tempCountAddress += 4;
        }
        listID.clear();
    }
    | /* empty */
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
        emit_mov("mov.i", symtable[$3].address, symtable[$1].address);
    }
    | WRITE '(' variable ')' { 
        emit_write("write.i", symtable[$3].address);
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
        emit_op("add.i", symtable[$1].address, symtable[$3].address, tempCountAddress);
        $$ = tempCountAddress;
        tempCountAddress+=4;
    }
    ;

term:
    factor { $$ = $1; }
    | term MULOP factor {
        if ($2 == MUL)
            emit_op("mul.i", symtable[$1].address, symtable[$3].address, tempCountAddress);
        else if ($2 == DIV)
            emit_op("div.i", symtable[$1].address, symtable[$3].address, tempCountAddress);
        else if ($2 == MOD)
            emit_op("mod.i", symtable[$1].address, symtable[$3].address, tempCountAddress);
        $$ = tempCountAddress;
        tempCountAddress+=4;
    }

factor:
    variable
    | VAL { $$ = $1; }
    | '(' expression ')'
    ;

%%

void yyerror(const char* s) {
    printf("\n\nBłąd \"%s\" w linii %d\n", s, lineno);
    errorno++;
}

const char *token_name(int token) {
    return yytname[YYTRANSLATE(token)];
}