%{
#include "global.h"
void yyerror(char const *s);
int yylex();
int lineno = 1;
%}

%token NUM
%token DIV
%token MOD
%token ID
%token DONE 0

%%

S:
    %empty
    | S expr ';';

expr: term
    | expr '+' term { printf("+\n"); }
    | expr '-' term { printf("-\n"); };

term: factor
    | term '*' factor { printf("*\n"); }
    | term '/' factor { printf("/\n"); }
    | term DIV factor { printf("DIV\n"); }
    | term MOD factor { printf("MOD\n"); };

factor: '(' expr ')'
    | NUM {  printf("%d\n", $1); }
    | ID { printf ("%s\n", symtable[$1].lexptr); };
%%
void yyerror (char const *error_description) {
  extern char *yytext;
  fprintf (stderr, "ERROR : %s: \"%s\" jest nieoczekiwanym znakiem!\n",error_description, yytext);
}
