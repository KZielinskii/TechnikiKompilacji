#include "global.h"
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char **argv)
{

  initSymtable();
  yyparse();

  if (errorno == 0)
  {
    printSymtable();
    string outFileName = "Program.asm";
    saveAsmCode(outFileName);
  }
  else
  {
    cout << endl << "Błąd kompilacji!!!" << endl;
  }

  yylex_destroy();
};