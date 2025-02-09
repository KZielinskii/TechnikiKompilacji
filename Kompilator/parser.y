%{
#include "global.h"

int errorno = 0;
int tempCountAddress = 0;
int labelCounter = 1;
std::vector<int> listID;

bool isType(int);
int yylex();
void yyerror(const char* s);
%}

%token PROGRAM ID INT REAL VAR NUM LABEL PROC NONE BEG END ASSIGN ADDOP MULOP WRITE READ IF THEN ELSE WHILE DO RELOP

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
        gencode_mov($3, $1);
    }
    | procedure_statement
    | compound_statement
    | IF expression THEN statement ELSE statement {
        int thenLabel = newLabel();
        int elseLabel = newLabel();
        int endLabel = newLabel();
        
        gencode_if($2, thenLabel, elseLabel);  // Warunek i THEN
        $$ = thenLabel;  // THEN blok
        gencode_else(elseLabel, endLabel);  // ELSE blok
        $$ = endLabel;
        gencode_end_if(endLabel);  // Zakończenie
    }

    | WHILE expression DO statement
    | WRITE '(' variable ')' { 
        gencode_write($3);
    }
    ;

variable:
    ID
    ;

procedure_statement:
    ID
    ;

expression:
    simple_expression
    | simple_expression RELOP simple_expression {
    $$ = gencode_relop($2, $1, $3, newTemp(INT));
    }
    ;

simple_expression:
    term { $$ = $1; }
    | simple_expression ADDOP term { 
        if ($2 == ADD) {
            $$ = gencode_op("add", $1, $3);
        }
        else if ($2 == SUB) {
            $$ = gencode_op("sub", $1, $3);
        }
    }
    ;

term:
    factor { $$ = $1; }
    | term MULOP factor {
        if ($2 == MUL) {
            $$ = gencode_op("mul", $1, $3);
        }
        else if ($2 == DIV) {
            $$ = gencode_op("div", $1, $3);
        }
        else if ($2 == MOD) {
            $$ = gencode_op("mod", $1, $3);
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

int getTempAddress(int size) {
    int temp = tempCountAddress;
    tempCountAddress+=size;
    return temp;
}

int newLabel() {
    return labelCounter++;
}

