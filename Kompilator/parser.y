%{
#include "global.h"

int errorno = 0;
int tempCountAddress = 0;
std::vector<int> listID;
std::vector<int> listArgs;
int offset = 8;
int localOffset = 0;
bool contextGlobal = true;
int startLabel;

int yylex();
void yyerror(const char* s);
%}

%token PROGRAM ID INT REAL VAR NUM LABEL PROC NONE BEG END ASSIGN ADDOP MULOP WRITE READ IF THEN ELSE WHILE DO RELOP NOT FUNCTION PROCEDURE

%%

program:
    PROGRAM ID {
        startLabel = newLabel();
    }'(' identifier_list ')' ';'
    declarations 
    subprogram_declarations
    {
        //main label
        gencode_label(startLabel);
    }
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
            symtable[id].isGlobal = contextGlobal;
            if (contextGlobal) {
                symtable[id].address = tempCountAddress;
                tempCountAddress += size;
            } else {
                symtable[id].address = getLocalAddress(size);
            }
        }
        listID.clear();
    }
    | // E
    ;

type:
    standerd_type
    ;

standerd_type:
    INT
    | REAL
    ;

subprogram_declarations:
    subprogram_declarations subprogram_declaration ';'
    | // E
    ;

subprogram_declaration:
    subprogram_head {
        contextGlobal = false;
        localOffset = 0;
        gencode_startFunc();
    } declarations compound_statement {
        int stackSize = newNumber(-localOffset);
        gencode_endFunc(stackSize);
        contextGlobal = true;
    }
    ;

subprogram_head:
    FUNCTION ID {
        gencode_label($2);
    } arguments ':' standerd_type ';' {

        offset = 8;
        symtable[$2].token = FUNCTION;
        symtable[$2].type = $6;
        symtable[$2].address = offset;
        symtable[$2].isReference = true;

        std::vector<symbol_t>args;
        for(auto arg: listArgs) {
            symbol_t id = symtable[arg];
            args.push_back(newArgument(id.type));
        }

        symtable[$2].arguments = args;
        listArgs.clear();

    }
    | PROCEDURE ID {

    } arguments ';' {

        symtable[$2].token = PROCEDURE;

        std::vector<symbol_t>args;
        for(auto arg: listArgs) {
            symbol_t id = symtable[arg];
            args.push_back(newArgument(id.type));
        }

        symtable[$2].arguments = args;
        listArgs.clear();

    }
    ;

arguments:
    '(' parametr_list ')' {
        std::vector<int>::iterator arg;
        for (arg = listArgs.end() - 1; arg >= listArgs.begin(); arg--) {
            offset += 4; // Size of reference
            symtable[*arg].address = offset;
        }
    }
    | // E
    ;

parametr_list:
    parametr
    | parametr_list ';' parametr
    ;

parametr:
    identifier_list ':' type {
        for (auto symbolIndex : listID) {
            symbol_t* symbol = &symtable[symbolIndex];
            symbol->type = $3;
            symbol->token = VAR;
            symbol->isGlobal = false;
            symbol->isReference = true;
        }
        listArgs.insert(listArgs.end(), listID.begin(), listID.end());
        listID.clear();
    }
    ;

compound_statement:
    BEG 
    optional_statments 
    END
    ;

optional_statments:
    statement_list
    | // E
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
    | IF expression {
       $$ = gencode_if($2);
    } THEN {
       $$ = gencode_then($3);
    } 
    statement ELSE {
       $$ = gencode_else($5);
    } 
    statement {
        gencode_label($8);
    }
    | {
        $$ = newLabel();
    }WHILE {
        $$ = gencode_while();
    }
    expression DO {
        int temp = gencode_if($4);
        $$ = gencode_while_then(temp,$1);
        
    } statement {
       gencode_end_while($1 ,$3);
    }
    | READ '(' expression_list ')' { 
        for (auto id : listID) {
            gencode_read(id);
        }
        listID.clear();
    }
    | WRITE '(' expression_list ')' { 
        for (auto id : listID) {
            gencode_write(id);
        }
        listID.clear();
    }
    ;

variable:
    ID
    ;

procedure_statement:
    ID {
        
    }
    | ID '(' expression_list ')' {

    }
    ;

expression_list:
    expression {
        listID.push_back($1);
    }
    | expression_list ',' expression {
        listID.push_back($3);
    }
    ;

expression:
    simple_expression
    | simple_expression RELOP simple_expression {
       $$ = gencode_relop($2, $1, $3);
    }
    ;

simple_expression:
    term { $$ = $1; }
    | ADDOP term {
        if ($1 == SUB) {
            $$ = gencode_sign($2);
        } else {
            $$ = $2;
        }
    }
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
    | ID '(' expression_list ')' {
       
        symbol_t func = symtable[$1];
        if(func.arguments.size() != listID.size()) {
            yyerror("Zła ilość argumentów funkcji!");
        }

        int incsp = 0;

        for(int id = 0; id < int(listID.size()); ++id) { 
            symbol_t expected = func.arguments[id];
            gencode_push(listID[id], expected);
            incsp += 4;
        }
        listID.clear();
        
        //push result
        int result = newTemp(func.type);
        gencode_push(result, newArgument(func.type));
        incsp += 4;

        $$ = result;
        gencode_call($1);
        int index = newNumber(incsp);
        gencode_incsp(index);
    }
    | NUM { $$ = $1; }
    | '(' expression ')'  { $$ = $2; }
    | NOT factor {
       $$ = gencode_not($2);
    }
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
    if(contextGlobal) {
        int temp = tempCountAddress;
        tempCountAddress+=size;
        return temp;
    }
    return 0;
}

int getLocalAddress(int size) {
    localOffset -= size;
    return localOffset;
}
