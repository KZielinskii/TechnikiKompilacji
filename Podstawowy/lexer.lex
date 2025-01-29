%{
#include "global.h"

int lineno = 1;
%}
%option noyywrap

letter      [A-Za-z]
digit       [0-9]
integer     {digit}+
fraction    "."{integer}+
real        {integer}{fraction}?
id          {letter}({letter}|{integer})*

assign      ":="
addop       "-" | "+"
mulop       "*" | "/" | "mul" | "div" | "mod" | "and"

%%
[ \t]       {}

\n          lineno++;

program     {return PROGRAM;}
begin       {return BEG;}
end         {return END;}

write       {return WRITE;}
read        {return READ;}

var         {return VAR;}
integer     {yylval = INT; return INT;}
real        {yylval = REAL; return REAL;}

:=          {return ASSIGN;}
{addop}     {yylval = getOperationToken(yytext); return ADDOP;}
{mulop}     {yylval = getOperationToken(yytext); return MULOP;}

{integer}   {yylval = insert(yytext, VAL, INT); return VAL;}
{real}      {yylval = insert(yytext, VAL, REAL); return VAL;}
{id}        {yylval = insert(yytext, ID, NONE); return ID;}
<<EOF>>     {return DONE;}
.           {return *yytext;}
%%