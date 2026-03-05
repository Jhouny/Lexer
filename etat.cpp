#include "etat.h"

class Etat;
class Automate {
    public:
        Automate();
        ~Automate();
        void decalage(Symbole* symbole, Etat* etat);
        void transitionSimple(Symbole* symbole, Etat* etat);
        void reduction(int n, Symbole* symbole);
        Symbole* consulter();
        Symbole* popSymbol();
        void popAndDestroySymbol();
        void printStacks() const; // Méthode pour afficher les piles (pour le débogage)
        void iterate();
        void Afficher() const;
        void reset();
}; // Éviter les inclusions circulaires

Etat::Etat(string name) : name(name) {}

Etat::~Etat() {}

void Etat::Affiche() const {
    cout << "Etat: " << name << endl;
}

bool E0::transition(Automate& automate, Symbole* symbole) {
    switch (int(*symbole)) {
        case OPENPAR:
            automate.decalage(symbole, new E2());
            return true;
        case EXPR:
            automate.transitionSimple(symbole, new E1());
            return true;
        case INT:
            automate.decalage(symbole, new E3());
            return true;
        default:
            cout << "Erreur de syntaxe: symbole inattendu " << Etiquettes[int(*symbole)] << " dans l'etat " << name << endl;
            // Reset symbol and state stacks to initial state
            automate.reset();
            return false;
    }
}

bool E1::transition(Automate& automate, Symbole* symbole) {
    switch (int(*symbole)) {
        case PLUS:
            automate.decalage(symbole, new E4());
            return true;
        case MULT:
            automate.decalage(symbole, new E5());
            return true;
        case FIN:
            /* QUIT ITERATION */
            return false;
        default:
            cout << "Erreur de syntaxe: symbole inattendu " << Etiquettes[int(*symbole)] << " dans l'etat " << name << endl;
            // Reset symbol and state stacks to initial state
            automate.reset();
            return false;
    }
}

bool E2::transition(Automate& automate, Symbole* symbole) {
    switch (int(*symbole)) {
        case INT:
            automate.decalage(symbole, new E3());
            return true;
        case EXPR:
            automate.transitionSimple(symbole, new E6());
            return true;
        case OPENPAR: 
            automate.decalage(symbole, new E2());
            return true;
        default:
            cout << "Erreur de syntaxe: symbole inattendu " << Etiquettes[int(*symbole)] << " dans l'etat " << name << endl;
            // Reset symbol and state stacks to initial state
            automate.reset();
            return false;
    }
}

bool E3::transition(Automate& automate, Symbole* symbole) {
    switch (int(*symbole)) {
        default:
            Entier* i = (Entier*) automate.popSymbol();
            automate.reduction(1, new Expr(i->getValeur()));
            return true;
    }
}

bool E4::transition(Automate& automate, Symbole* symbole) {
    switch (int(*symbole)) {
        case OPENPAR:
            automate.decalage(symbole, new E2());
            return true;
        case EXPR:
            automate.transitionSimple(symbole, new E7());
            return true;
        case INT:
            automate.decalage(symbole, new E3());
            return true;
        default:
            cout << "Erreur de syntaxe: symbole inattendu " << Etiquettes[int(*symbole)] << " dans l'etat " << name << endl;
            // Reset symbol and state stacks to initial state
            automate.reset();
            return false;
    }
}

bool E5::transition(Automate& automate, Symbole* symbole) {
    switch (int(*symbole)) {
        case OPENPAR:
            automate.decalage(symbole, new E2());
            return true;
        case EXPR:
            automate.transitionSimple(symbole, new E8());
            return true;
        case INT:
            automate.decalage(symbole, new E3());
            return true;
        default:
            cout << "Erreur de syntaxe: symbole inattendu " << Etiquettes[int(*symbole)] << " dans l'etat " << name << endl;
            // Reset symbol and state stacks to initial state
            automate.reset();
            return false;
    }
}

bool E6::transition(Automate& automate, Symbole* symbole) {
    switch (int(*symbole)) {
        case MULT:
            automate.decalage(symbole, new E5());
            return true;
        case PLUS:
            automate.decalage(symbole, new E4());
            return true;
        case CLOSEPAR:
            automate.decalage(symbole, new E9());
            return true;
        default:
            cout << "Erreur de syntaxe: symbole inattendu " << Etiquettes[int(*symbole)] << " dans l'etat " << name << endl;
            // Reset symbol and state stacks to initial state
            automate.reset();
            return false;
    }
}

bool E7::transition(Automate& automate, Symbole* symbole) {
    switch (int(*symbole)) {
        case MULT:
            automate.decalage(symbole, new E5());
            return true;
        default:
            Expr* e1 = (Expr*) automate.popSymbol();
            automate.popAndDestroySymbol();
            Expr* e2 = (Expr*) automate.popSymbol();
            automate.reduction(3, new ExprPlus(e2, e1));
            return true;
    }
}

bool E8::transition(Automate& automate, Symbole* symbole) {
    switch (int(*symbole)) {
        default:
            Expr* e1 = (Expr*) automate.popSymbol();
            automate.popAndDestroySymbol();
            Expr* e2 = (Expr*) automate.popSymbol();
            automate.reduction(3, new ExprMult(e1, e2));
            return true;
    }
}

bool E9::transition(Automate& automate, Symbole* symbole) {
    switch (int(*symbole)) {
        default:
            automate.popAndDestroySymbol();
            Expr* e = (Expr*) automate.popSymbol();
            automate.popAndDestroySymbol();
            automate.reduction(3, e);
            return true;
    }
}