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
    PROGRAM ID '(' identifier_list ')' ';'
    declarations compound_statement '.'
    ;

identifier_list:
    ID { listID.push_back($1); }
    | identifier_list ',' ID { listID.push_back($3); }
    ;

declarations:
    declarations VAR identifier_list ':' INT ';' { 
        for (int id : listID) {
            symtable[id].type = INT;
            symtable[id].address = tempCountAddress;  // Przypisanie adresu w pamięci
            tempCountAddress += 4;  // Przesunięcie adresu (np. o 4 bajty dla int)
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
        emit("mov.i", $3, symtable[$1].address);
    }
    | WRITE '(' variable ')' { 
        emit("write.i", symtable[$3].address);
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
        int temp = getTemp();
        emit("add.i", symtable[$1].address, symtable[$3].address, temp);
        $$ = temp;
    }
    ;

term:
    factor { $$ = $1; }
    | term MULOP factor {
        int temp = getTemp();
        if ($2 == MUL)
            emit("mul.i", symtable[$1].address, symtable[$3].address, temp);
        else if ($2 == DIV)
            emit("div.i", symtable[$1].address, symtable[$3].address, temp);
        else if ($2 == MOD)
            emit("mod.i", symtable[$1].address, symtable[$3].address, temp);
        $$ = temp;
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