#include "global.h"

int main () 
{
  parse ();
  yylex_destroy(); 
  exit (0);
}


