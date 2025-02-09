#include "global.h"

int getOperationToken(std::string yytext)
{
  if(yytext == "+")
    return ADD;
  else if(yytext == "-")
    return SUB;
  else if(yytext == "*" || yytext == "mul")
    return MUL;
  else if(yytext == "/" || yytext == "div")
    return DIV;
  else if(yytext == "mod")
    return MOD;
  else if (yytext == "<")
    return LT;
  else if (yytext == "<=")
    return LE;
  else if (yytext == ">")
    return GT;
  else if (yytext == ">=")
    return GE;
  else if (yytext == "=")
    return EQ;
  else if (yytext == "<>")
    return NE;

  return -1;
}
