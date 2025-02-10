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
    return L;
  else if (yytext == "<=")
    return LE;
  else if (yytext == ">")
    return G;
  else if (yytext == ">=")
    return GE;
  else if (yytext == "=")
    return E;
  else if (yytext == "<>")
    return NE;

  return -1;
}
