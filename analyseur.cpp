#include "analyseur.h"

int analyse(const string& expression) {
   // Convertir la chaîne d'entrée en une chaîne modifiable
   string chaine = expression;

   // Créer une instance de l'automate et du lexer
   Automate transformers;
   Lexer l(chaine);

   // Configurer l'automate pour utiliser le lexer et lancer l'analyse
   transformers.setLexer(&l);
   transformers.iterate();
   return transformers.getResult();
}