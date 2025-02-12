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
addop       "-"|"+"
mulop       "*"|"/"|"mul"|"div"|"mod"
relop       "<"|"<="|">"|">="|"="|"<>"

%%
\n          lineno++;
[ \t]        {}

program     {return PROGRAM;}
function    {return FUNCTION;}
procedure   {return PROCEDURE;}
begin       {return BEG;}
end         {return END;}

write       {return WRITE;}
read        {return READ;}

if          {return IF;}
then        {return THEN;}
else        {return ELSE;}
while       {return WHILE;}
do          {return DO;}
not         {return NOT;}

var         {return VAR;}
integer     {yylval = INT; return INT;}
real        {yylval = REAL; return REAL;}

{assign}    {return ASSIGN;}
{addop}     {yylval = getOperationToken(yytext); return ADDOP;}
{mulop}     {yylval = getOperationToken(yytext); return MULOP;}
{relop}     {yylval = getOperationToken(yytext); return RELOP;}

{integer}   {yylval = insert(yytext, NUM, INT); return NUM;}
{real}      {yylval = insert(yytext, NUM, REAL); return NUM;}
{id}        {yylval = insert(yytext, ID, NONE); return ID;}
\{[^}]*\}    {}
.           {return *yytext;}
%%