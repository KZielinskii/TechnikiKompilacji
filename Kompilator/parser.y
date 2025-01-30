%{
#include "global.h"

int errorno = 0;
std::vector<int> listID;

bool isType(int);
int yylex();

%}

%token-table

%token PROGRAM
%token BEG
%token END
%token WRITE
%token READ
%token ASSIGN
%token ADDOP
%token MULOP
%token INT
%token REAL
%token VAL
%token VAR
%token ID
%token LABEL
%token NONE
%token DONE
%token PROC

%%

program: 
    PROGRAM ID 
    {
        symtable[$2].token = PROC;
        writeCode("jump.i\t\t#program", "jump.i\t\tprogram");
    } 
    '(' program_arguments ')' ';'
    vars
    {
        writeLabel("program");
    }
    BEG function_body END
    '.' DONE
    {
        writeCode("exit\t\t\t", "exit");
        return 0;
    }
    ;

program_arguments: 
    ID 
    | program_arguments ',' ID
    ;

vars:
    vars VAR var_list ':' type ';'
    {
        if (isType($5)) YYERROR;

        for (auto &symTabIdx : listID) {
            symbol_t* sym = &symtable[symTabIdx];
            sym->type = $5;       
            sym->token = VAR;
            sym->address = getAddress(sym->name);
        }
        listID.clear();
    }
    | 
    ;

var_list: 
    ID 
    {
        listID.push_back($1);
    }
    | var_list ',' ID
    {
        listID.push_back($3);
    }
    ;


type: 
    INT 
    | REAL
    ;


function_body:
    statements 
    | 
    ;

statements:
    statements ';' statement 
    | statement 
    ;

statement:
    ID ASSIGN expression
    {
        appendAssign(symtable[$1], symtable[$3]);
    }
    | read
    | write
    ;

expression: 
    term 
    | ADDOP term
    {
        if ($1 == SUB) {
            int zero = newNum("0", symtable[$2].type);
            $$ = appendAddOP(symtable[zero], SUB, symtable[$2]);
        } else {
            $$ = $2;
        }
    }
    | expression ADDOP term
    {
        $$ = appendAddOP(symtable[$1], $2, symtable[$3]);
    }
    ;

term: 
    factor 
    | term MULOP factor
    {
        $$ = appendMulOP(symtable[$1], $2, symtable[$3]);
    }
    ;

factor: 
    ID 
    | VAL 
    | '(' expression ')'
    {
        $$ = $2;
    }
    ;

expression_list:
    expression_list ',' expression
    {
        listID.push_back($3);
    }
    | expression
    {
        listID.push_back($1);
    }
    ;

read:
    READ '(' expression_list ')'
    {
        for (auto id : listID) {
            appendRead(symtable[id]);
        }
        listID.clear();
    }
    ;

write:
    WRITE '(' expression_list ')'
    {
        for (auto id : listID) {
            appendWrite(symtable[id]);
        }
        listID.clear();
    }
    ;

%%

bool isType(int type) {
    if (type != INT && type != REAL) {
        yyerror("Nieznany typ");
        return true;
    }
    return false;
}

void yyerror(char const *s) {
    printf("\n\nBłąd \"%s\" w linii %d\n", s, lineno);
    errorno++;
}

const char *token_name(int token) {
    return yytname[YYTRANSLATE(token)];
}
