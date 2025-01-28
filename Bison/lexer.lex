%option noyywrap
%{
#include "global.h"
#include "parser.h"

%}

%%

[ \t]        {}

\n           { lineno++; }

[0-9]+       { 
                sscanf(yytext, "%d", &yylval);
                return NUM;
             }

div          { 
                yylval=NONE;
		return DIV; 
	     }

mod          { 
                yylval=NONE;
		return MOD; 
             }

[a-zA-Z][a-zA-Z0-9]*   {
                                int p = lookup(yytext); 
                                if (p == 0)
                                p = insert (yytext, ID); 
                                yylval = p; 
                                return symtable[p].token;
                        }

.            { 
	       yylval = NONE;
	       return yytext[0]; 
             }

%%

int lexan() { return yylex(); }
