#include <iostream>
#include "lexer.h"
#include "etat.h"
#include "automate.h"

int main(int argc, char* argv[]) {
   if (argc != 2) {
       cout << "Usage: " << argv[0] << " <expression>" << endl;
       return 1;
   }

   string chaine = argv[1];
   
   Automate transformers;
   Lexer l(chaine);

   transformers.setLexer(&l);
   cout << "Expression: " << chaine << endl;
   transformers.iterate();
   transformers.Afficher();
   return 0;
}

