//
// Created by pucci on 04/06/2024.
//

#include "Utente.h"
#include <sstream>

Utente::~Utente() {
    for(auto it = liste.begin(); it!=liste.end(); it++){
        it->second->unsubscribe(this);
    }
    liste.clear();
}

void Utente::update(const std::string listName, int oggettiMancanti) {
    cout<<"!! ATTENZIONE "<<nome<<" !! La lista "<<listName;
    cout<<" e' stata modificata , Oggetti da comprare rimanenti : "<<oggettiMancanti<<"\n\n";
}

ostream &operator<<(ostream &os, const Utente *u) {
    os<<"[ Utente: "<<u->nome<<" ]"<<std::endl;
    if(u->liste.empty())
        os<<"Nessuna lista presente"<<std::endl;
    else {
        for (auto it = u->liste.begin(); it != u->liste.end(); it++)
            os<< it->second;
    }
    return os;
}

void Utente::creaLista(std::string nuovoNome) {
    auto check = liste.find(nuovoNome);
    if(check!=liste.end()){
        cout<<"Impossibile usare '"<<nuovoNome << "' come nuovo nome , nome gia' esistente"<<endl;
        return;
    }
    cout<<"Lista '"<<nuovoNome<<"' creata con successo"<<endl;
    aggiungiLista(make_shared<ListaSpesa>(nuovoNome));
}

void Utente::aggiungiLista(std::shared_ptr<ListaSpesa> nuovaLista) {
    auto check = liste.find(nuovaLista->getNome());
    if(check!=liste.end()){
        cout<<"Impossibile aggiungere la lista , nome gia' esistente"<<endl;
        return;
    }
    liste.insert(make_pair(nuovaLista->getNome(),nuovaLista));
    nuovaLista->subscribe(this);
}

void Utente::rimuoviLista(std::string nomeLista) {
    auto it = liste.find(nomeLista);
    if(it!=liste.end()){
        it->second->unsubscribe(this);
        liste.erase(nomeLista);
        cout<<"Lista '"<<nomeLista<<"' rimossa con successo da "<<this->nome<<endl;
    }else{
        cout<<"Rimozione Fallita , Lista non trovata"<<endl;
    }
}

void Utente::condividiLista(shared_ptr<Utente> condivisore , std::string nomeLista) {
    auto it = liste.find(nomeLista);
    if(it!=liste.end()){
        condivisore->aggiungiLista(it->second);
        cout<<this->nome<<" hai condiviso la lista '"<<nomeLista<<"' con "<<condivisore->getNome()<<endl;
    }else{
        cout<<"Condivisione Fallita , Lista non trovata"<<endl;
    }
}