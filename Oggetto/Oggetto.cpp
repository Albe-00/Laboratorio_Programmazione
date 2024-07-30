//
// Created by pucci on 04/06/2024.
//

#include "Oggetto.h"

void Oggetto::setQuantita(int q) {
    if(q>=0)
        quantita=q;
    else
        quantita=-q;
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
