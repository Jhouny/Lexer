#pragma once

#include <string>
#include "symbole.h"
#include <iostream>
using namespace std;

class Automate;

class Etat {
    public:
        Etat(string name);
        virtual ~Etat();
        void Affiche() const;
        virtual bool transition(Automate& automate, Symbole* symbole) = 0;
    protected:
        string name;
};

/* ============= Etats de transition ============ */

class E0 : public Etat {
    public:
        E0() : Etat("E0") {}
        virtual ~E0() {}
        virtual bool transition(Automate& automate, Symbole* symbole) override;
};

class E1 : public Etat {
    public:
        E1() : Etat("E1") {}
        virtual ~E1() {}
        virtual bool transition(Automate& automate, Symbole* symbole) override;
};

class E2 : public Etat {
    public:
        E2() : Etat("E2") {}
        virtual ~E2() {}
        virtual bool transition(Automate& automate, Symbole* symbole) override;
};

class E3 : public Etat {
    public:
        E3() : Etat("E3") {}
        virtual ~E3() {}
        virtual bool transition(Automate& automate, Symbole* symbole) override;
};

class E4 : public Etat {
    public:
        E4() : Etat("E4") {}
        virtual ~E4() {}
        virtual bool transition(Automate& automate, Symbole* symbole) override;
};

class E5 : public Etat {
    public:
        E5() : Etat("E5") {}
        virtual ~E5() {}
        virtual bool transition(Automate& automate, Symbole* symbole) override;
};

class E6 : public Etat {
    public:
        E6() : Etat("E6") {}
        virtual ~E6() {}
        virtual bool transition(Automate& automate, Symbole* symbole) override;
};

class E7 : public Etat {
    public:
        E7() : Etat("E7") {}
        virtual ~E7() {}
        virtual bool transition(Automate& automate, Symbole* symbole) override;
};

class E8 : public Etat {
    public:
        E8() : Etat("E8") {}
        virtual ~E8() {}
        virtual bool transition(Automate& automate, Symbole* symbole) override;
};

class E9 : public Etat {
    public:
        E9() : Etat("E9") {}
        virtual ~E9() {}
        virtual bool transition(Automate& automate, Symbole* symbole) override;
};