//
// Created by pucci on 04/06/2024.
//

#include "Oggetto.h"

void Oggetto::setQuantita(int quantita) {
    if(quantita>=0)
        this->quantita=quantita;
    else
        this->quantita=-quantita;
}

ostream &operator<<(ostream &os, const Oggetto *o) {
    os<<"nome : "<<o->nome<<"\t\t";
    os<<"categoria : "<<o->categoria<<"\t\t";
    os<<"quantita : "<<o->quantita<<"\t\t";
    if(o->comprato)
        os<<"[ V ]\n";
    else
        os<<"[ X ]\n";
    return os;
}
