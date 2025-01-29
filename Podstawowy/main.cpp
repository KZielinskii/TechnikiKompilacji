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
    cout << "Tabela symboli: " << endl;
    printSymtable();
    string outFileName = "Program.asm";

    cout << endl << "Kod w assemblerze: " << endl;
    saveAsmCode(outFileName);
  }
  else
  {
    cout << endl << "Błąd kompilacji!!!" << endl;
  }

  yylex_destroy();
};