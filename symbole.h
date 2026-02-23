#pragma once

#include <string>
using namespace std;

enum Identificateurs { OPENPAR, CLOSEPAR, PLUS, MULT, INT, EXPR, FIN, ERREUR };

const string Etiquettes[] = { "OPENPAR", "CLOSEPAR", "PLUS", "MULT", "INT", "EXPR", "FIN", "ERREUR" };

class Symbole {
   public:
      Symbole(int i) : ident(i) {  }
      virtual ~Symbole() { }
      operator int() const { return ident; }
      virtual void Affiche();

   protected:
      int ident;
};

class Entier : public Symbole {
   public:
      Entier(int v) : Symbole(INT), valeur(v) { }
      ~Entier() { }
      virtual void Affiche();
      int getValeur() const { return valeur; }
   protected:
      int valeur;
};

class Expr : public Symbole {
   public:
      Expr(int val) : Symbole(EXPR) { valeur = val; }
      Expr() : Symbole(EXPR) { valeur = 0; }
      virtual ~Expr() {}
      int getValeur() const { return valeur; }
   protected:
      int valeur;
};

class ExprMult : public Expr {
   public:
      ExprMult(Expr* e1, Expr* e2) { valeur = e1->getValeur() * e2->getValeur(); }
      ~ExprMult() {}
};

class ExprPlus : public Expr {
   public:
      ExprPlus(Expr* e1, Expr* e2) { valeur = e1->getValeur() + e2->getValeur(); }
      ~ExprPlus() {}
};