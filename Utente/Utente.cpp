//
// Created by pucci on 04/06/2024.
//

#include "Utente.h"
#include <sstream>

Utente::~Utente() {
    for(auto& it : liste){
        it.second->unsubscribe(this);
    }
    liste.clear();
}

void Utente::update(const string& nomeLista, int oggettiMancanti) {
    cout<<"!! ATTENZIONE "<<nome<<" !! La lista "<<nomeLista;
    cout<<" e' stata modificata , Oggetti da comprare rimanenti : "<<oggettiMancanti<<"\n\n";
}

ostream &operator<<(ostream &os, const Utente *u) {
    os<<"[ Utente: "<<u->nome<<" ]"<<endl;
    if(u->liste.empty())
        os<<"Nessuna lista presente"<<endl;
    else {
        for (auto& it : u->liste)
            os<< it.second;
    }
    return os;
}

bool Utente::creaLista(const string& nuovoNome) {
    auto check = liste.find(nuovoNome);
    if(check!=liste.end())
        return false;

    aggiungiLista(make_shared<ListaSpesa>(nuovoNome));
    return true;
}

bool Utente::aggiungiLista(const shared_ptr<ListaSpesa>& nuovaLista) {
    auto check = liste.find(nuovaLista->getNome());
    if(check!=liste.end())
        return false;

    liste.insert(make_pair(nuovaLista->getNome(),nuovaLista));
    nuovaLista->subscribe(this);
    return true;
}

bool Utente::rimuoviLista(const string& nomeLista) {
    auto it = liste.find(nomeLista);
    if(it==liste.end())
        return false;

    it->second->unsubscribe(this);
    liste.erase(nomeLista);
    return true;
}

bool Utente::condividiLista(const shared_ptr<Utente>& condivisore ,const string& nomeLista) {
    auto it = liste.find(nomeLista);
    if(it==liste.end())
        return false;

    if(condivisore->aggiungiLista(it->second))
        return true;
    else
        return false;
}