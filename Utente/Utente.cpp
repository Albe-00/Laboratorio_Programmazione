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
    if(check!=liste.end()){
        cout<<"Impossibile usare '"<<nuovoNome << "' come nuovo nome , nome gia' esistente"<<endl;
        return false;
    }
    cout<<"Lista '"<<nuovoNome<<"' creata con successo"<<endl;
    aggiungiLista(make_shared<ListaSpesa>(nuovoNome));
    return true;
}

bool Utente::aggiungiLista(const shared_ptr<ListaSpesa>& nuovaLista) {
    auto check = liste.find(nuovaLista->getNome());
    if(check!=liste.end()){
        cout<<"Impossibile aggiungere la lista , nome gia' esistente"<<endl;
        return false;
    }
    liste.insert(make_pair(nuovaLista->getNome(),nuovaLista));
    nuovaLista->subscribe(this);
    return true;
}

bool Utente::rimuoviLista(const string& nomeLista) {
    auto it = liste.find(nomeLista);
    if(it!=liste.end()){
        it->second->unsubscribe(this);
        liste.erase(nomeLista);
        cout<<"Lista '"<<nomeLista<<"' rimossa con successo da "<<this->nome<<endl;
        return true;
    }else{
        cout<<"Rimozione Fallita , Lista non trovata"<<endl;
        return false;
    }
}

bool Utente::condividiLista(const shared_ptr<Utente>& condivisore ,const string& nomeLista) {
    auto it = liste.find(nomeLista);
    if(it!=liste.end()){
        if(condivisore->aggiungiLista(it->second)){
            cout<<this->nome<<" hai condiviso la lista '"<<nomeLista<<"' con "<<condivisore->getNome()<<endl;
            return true;
        }else{
            cout<<"Condivisione Fallita , lista con quel nome gia' presente nel condivisore"<<endl;
            return false;
        }
    }else{
        cout<<"Condivisione Fallita , Lista non trovata"<<endl;
        return false;
    }
}