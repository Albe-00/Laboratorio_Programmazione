//
// Created by pucci on 04/06/2024.
//

#include "Utente.h"

Utente::~Utente() {
    for(auto it = liste.begin(); it!=liste.end(); it++){
        it->second->unsubscribe(this);
    }
}

void Utente::update(const std::string listName, int oggettiMancanti) {
    cout<<"!! ATTENZIONE "<<nome<<" !! La lista "<<listName;
    cout<<" e' stata modificata , Oggetti da comprare rimanenti : "<<oggettiMancanti<<"\n\n";
}

ostream &operator<<(ostream &os, const Utente &u) {
    os<<"[ Utente: "<<u.nome<<" ]"<<std::endl;
    os<<"Liste: "<<std::endl;
    for(auto it = u.liste.begin(); it!=u.liste.end(); it++){
        os<<*it->second;
    }
    return os;
}

void Utente::creaLista() {
    string nuovoNome;
    cout<<"Inserisci il nome della nuova lista : ";
    cin>>nuovoNome;
    auto ptr = make_shared<ListaSpesa>(nuovoNome);
    liste.insert(make_pair(nuovoNome,ptr));
    ptr->subscribe(this);
    cout<<"Lista creata con successo"<<endl;
}


void Utente::aggiungiLista(ListaSpesa& nuovaLista) {
    shared_ptr<ListaSpesa> ptr(&nuovaLista);
    liste.insert(make_pair(nuovaLista.getNome(),ptr));
    ptr->subscribe(this);
    cout<<"Lista aggiunta con successo"<<endl;
}

void Utente::rimuoviLista() {
    string nomeLista;
    cout<<"Inserisci il nome della lista da rimuovere: ";
    cin>>nomeLista;
    auto it = liste.find(nomeLista);
    if(it!=liste.end()){
        liste.erase(it);
        cout<<"Lista rimossa con successo"<<endl;
    }else{
        cout<<"Lista non trovata"<<endl;
    }
}

void Utente::condividiLista(Utente *condivisore) {
    string nomeLista;
    cout<<"Inserisci il nome della lista da condividere con "<<condivisore->getNome()<<" : ";
    cin>>nomeLista;
    auto it = liste.find(nomeLista);
    if(it!=liste.end()){
        condivisore->aggiungiLista(*it->second);
        cout<<"Lista condivisa con successo"<<endl;
    }else{
        cout<<"Lista non trovata"<<endl;
    }
}

void Utente::aggiungiOggettoALista() {
    string nomeLista;
    cout<<"Inserisci il nome della lista a cui vuoi aggiungere un oggetto: ";
    cin>>nomeLista;
    auto it = liste.find(nomeLista);
    if(it!=liste.end()){
        it->second->aggiungiOggetto();
    }else{
        cout<<"Lista non trovata"<<endl;
    }
}

void Utente::cancellaOggettoDaLista() {
    string nomeLista;
    cout<<"Inserisci il nome della lista da cui vuoi cancellare un oggetto: ";
    cin>>nomeLista;
    auto it = liste.find(nomeLista);
    if(it!=liste.end()){
        it->second->rimuoviOggetto();
    }else{
        cout<<"Lista non trovata"<<endl;
    }

}

void Utente::compraOggetto() {
    string nomeLista;
    cout<<"Inserisci il nome della lista da cui vuoi comprare un oggetto: ";
    cin>>nomeLista;
    auto it = liste.find(nomeLista);
    if(it!=liste.end()){
        it->second->compraOggetto();
    }else{
        cout<<"Lista non trovata"<<endl;
    }
}
