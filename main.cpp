#include <iostream>
#include "lexer.h"
#include "etat.h"
#include "automate.h"

int main(void) {
   string chaine("1+3");
   
   Automate transformers;
   Lexer l(chaine);

   transformers.setLexer(&l);

   transformers.iterate();
   transformers.Afficher();
   return 0;
}

