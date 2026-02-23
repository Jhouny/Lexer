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
        void decalage(Symbole* symbole, Etat* etat);
        void transitionSimple(Symbole* symbole, Etat* etat);
        void reduction(int n, Symbole* symbole);

        Symbole* popSymbol();
        void popAndDestroySymbol();
};