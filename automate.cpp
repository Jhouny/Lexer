#include "automate.h"

#include <iostream>
using namespace std;

Automate::Automate() {
    statestack.push_back(new E0());
    lexer = nullptr;
}

Automate::~Automate() {
    for (Etat* etat : statestack) {
        delete etat;
    }
    for (Symbole* symbole : symbolstack) {
        delete symbole;
    }
}

void Automate::decalage(Symbole* symbole, Etat* etat) {
    statestack.push_back(etat);
    symbolstack.push_back(symbole);
    lexer->Avancer();
}

void Automate::transitionSimple(Symbole* symbole, Etat* etat) {
    statestack.push_back(etat);
    symbolstack.push_back(symbole);
}

void Automate::reduction(int n, Symbole* symbole) {
    for (int i = 0; i < n; i++) {
        delete statestack.back();
        statestack.pop_back();
    }
    statestack.back()->transition(*this, symbole);
}

Symbole* Automate::consulter() {
    return lexer->Consulter();
}

Symbole* Automate::popSymbol() {
    if (symbolstack.empty()) {
        return nullptr;
    }
    Symbole* symbole = symbolstack.back();
    symbolstack.pop_back();
    return symbole;
}

void Automate::popAndDestroySymbol() {
    if (!symbolstack.empty()) {
        delete symbolstack.back();
        symbolstack.pop_back();
    }
}

void Automate::printStacks() const {
    cout << endl;
    cout << "Etat stack: ";
    for (const auto& etat : statestack) {
        etat->Affiche();
    }
    cout << "Symbole stack: ";
    for (const auto& symbole : symbolstack) {
        symbole->Affiche();
        cout << " ";
    }
    cout << endl;
}

void Automate::iterate() {
    while (true) {
        Symbole* symbole = consulter();
        if (!statestack.back()->transition(*this, symbole)) {
            break;
        }
    }
}

void Automate::Afficher() const {
    if (!symbolstack.empty()) {
        cout << "Resultat: " << ((Expr*) symbolstack.back())->getValeur() << endl;
    } else {
        cout << "Aucun resultat a afficher." << endl;
    }
}

int Automate::getResult() const {
    if (!symbolstack.empty()) {
        return ((Expr*) symbolstack.back())->getValeur();
    }
    return -1; // Valeur par défaut en cas d'erreur
}

void Automate::reset() {
    symbolstack.clear();
    statestack.clear();
}