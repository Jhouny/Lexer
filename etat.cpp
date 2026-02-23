#include "etat.h"

Etat::Etat(string name) : name(name) {}

Etat::~Etat() {}

void Etat::Affiche() const {
    cout << "Etat: " << name << endl;
}

E0::E0() : Etat("E0") {}
E0::~E0() {}
bool E0::transition(Automate& automate, Symbole* symbole) {
    switch (int(*symbole)) {
        case OPENPAR:
            automate.decalage(symbole, new E2());
            return true;
        case EXPR:
            automate.decalage(symbole, new E1());
            return true;
        case INT:
            automate.decalage(symbole, new E3());
            return true;
        default:
            return false;
    }
}

E1::E1() : Etat("E1") {}
E1::~E1() {}
bool E1::transition(Automate& automate, Symbole* symbole) {
    switch (int(*symbole)) {
        case PLUS:
            automate.decalage(symbole, new E4());
            return true;
        case MULT:
            automate.decalage(symbole, new E5());
            return true;
        case FIN:
            /* TODO */
            return true;
        default:
            return false;
    }
}

E2::E2() : Etat("E2") {}
E2::~E2() {}
bool E2::transition(Automate& automate, Symbole* symbole) {
    switch (int(*symbole)) {
        case INT:
            automate.decalage(symbole, new E3());
            return true;
        case EXPR:
            automate.decalage(symbole, new E6());
            return true;
        case OPENPAR: 
            automate.decalage(symbole, new E2());
            return true;
        default:
            return false;
    }
}

E3::E3() : Etat("E3") {}
E3::~E3() {}
bool E3::transition(Automate& automate, Symbole* symbole) {
    switch (int(*symbole)) {
        case FIN:
            /* TODO */
            return true;
        default:
            return false;
    }
}

E4::E4() : Etat("E4") {}
E4::~E4() {}
bool E4::transition(Automate& automate, Symbole* symbole) {
    switch (int(*symbole)) {
        case OPENPAR:
            automate.decalage(symbole, new E2());
            return true;
        case EXPR:
            automate.decalage(symbole, new E7());
            return true;
        case INT:
            automate.decalage(symbole, new E3());
            return true;
        default:
            return false;
    }
}

E5::E5() : Etat("E5") {}
E5::~E5() {}
bool E5::transition(Automate& automate, Symbole* symbole) {
    switch (int(*symbole)) {
        case OPENPAR:
            automate.decalage(symbole, new E2());
            return true;
        case EXPR:
            automate.decalage(symbole, new E8());
            return true;
        case INT:
            automate.decalage(symbole, new E3());
            return true;
        default:
            return false;
    }
}

E6::E6() : Etat("E6") {}
E6::~E6() {}
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
            return false;
    }
}

E7::E7() : Etat("E7") {}
E7::~E7() {}
bool E7::transition(Automate& automate, Symbole* symbole) {
    switch (int(*symbole)) {
        case MULT:
            automate.decalage(symbole, new E5());
            return true;
        default:
            return false;
    }
}

E8::E8() : Etat("E8") {}
E8::~E8() {}
bool E8::transition(Automate& automate, Symbole* symbole) {
    switch (int(*symbole)) {
        case FIN:
            /* TODO */
            return true;
        default:
            return false;
    }
}

E9::E9() : Etat("E9") {}
E9::~E9() {}
bool E9::transition(Automate& automate, Symbole* symbole) {
    switch (int(*symbole)) {
        case FIN:
            /* TODO */
            return true;
        default:
            return false;
    }
}