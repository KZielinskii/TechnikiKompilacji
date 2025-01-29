%option noyywrap
%{
#include "global.h"

int lineno = 1;
int tokenval = NONE;
%}

%%

[ \t]        {}

\n           { lineno++; }

[0-9]+       { 
                sscanf(yytext, "%d", &tokenval);
                return NUM;
             }

div          { 
                tokenval=NONE;
		return DIV; 
	     }

mod          { 
                tokenval=NONE;
		return MOD; 
             }

[a-zA-Z][a-zA-Z0-9]*   {
                                int p = lookup(yytext); 
                                if (p == 0)
                                p = insert (yytext, ID); 
                                tokenval = p; 
                                return symtable[p].token;
                        }

.            { 
	       tokenval = NONE;
	       return yytext[0]; 
             }

<<EOF>> {
            return DONE;
        }

%%

int lexan() { return yylex(); }
