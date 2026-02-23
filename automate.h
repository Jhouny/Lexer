#pragma once

#include "symbole.h"
#include "etat.h"
#include "lexer.h"
#include <vector>
using namespace std;

class Automate {
    private:
        vector<Etat*> statestack;
        vector<Symbole*> symbolstack;
        Lexer* lexer;
    public:
        Automate();
        ~Automate();
        void setLexer(Lexer* l) { lexer = l; }
        void decalage(Symbole* symbole, Etat* etat);
        void transitionSimple(Symbole* symbole, Etat* etat);
        void reduction(int n, Symbole* symbole);
        Symbole* consulter();
        Symbole* popSymbol();
        void popAndDestroySymbol();

        void iterate();
        void Afficher() const;
};