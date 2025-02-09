%{
#include "global.h"

int errorno = 0;
int tempCountAddress = 0;
std::vector<int> listID;

bool isType(int);
int yylex();
void yyerror(const char* s);
%}

%token PROGRAM ID INT VAR NUM LABEL PROC NONE BEG END ASSIGN ADDOP MULOP WRITE READ

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
        emit_mov("mov.i", $3, $1);
    }
    | WRITE '(' variable ')' { 
        emit_write("write.i", $3);
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
        tempCountAddress += 4;

        if ($2 == ADD)
            $$ = emit_op("add.i", $1, $3, tempVar);
        else if ($2 == SUB)
            $$ = emit_op("sub.i", $1, $3, tempVar);
    }
    ;

term:
    factor { $$ = $1; }
    | term MULOP factor {
        int tempVar = tempCountAddress;
        tempCountAddress += 4;

        if ($2 == MUL)
            $$ = emit_op("mul.i", $1, $3, tempVar);
        else if ($2 == DIV)
            $$ = emit_op("div.i", $1, $3, tempVar);
        else if ($2 == MOD)
            $$ = emit_op("mod.i", $1, $3, tempVar);

    }

factor:
    variable { $$ = $1; }
    | NUM { $$ = $1; }
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
