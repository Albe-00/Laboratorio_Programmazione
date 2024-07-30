//
// Created by pucci on 04/06/2024.
//

#include "ListaSpesa.h"

void ListaSpesa::subscribe(Observer *o) {
    observers.push_back(o);
}

void ListaSpesa::unsubscribe(Observer *o) {
    observers.remove(o);
}

void ListaSpesa::notify() {
    for (auto itr:observers) {
        itr->update(nomeLista, daComprare);
    }
}

ostream& operator<<(ostream& os, const ListaSpesa* lista){
    os<<"< "<<lista->nomeLista<<" > - TOTALE RIMANENTI : "<<lista->daComprare<<"\n";
    if(lista->oggettiDellaLista.empty())
        os<<"Lista vuota\n\n";
    else {
        int i = 1;
        for (auto& ptr: lista->oggettiDellaLista) {
            os << i++ << ") ";
            os << ptr.second;
        }
        os << "\n";
    }
    return os;
}

bool ListaSpesa::aggiungiOggetto(const string& nome , const string& categoria , int quantita) {
    int checkedQuantita = quantita;
    if(quantita<0){
        checkedQuantita*=-1;
    }
    auto check = oggettiDellaLista.find(nome);

    if(check!=oggettiDellaLista.end()){
        if(categoria==check->second->getCategoria())
            check->second->aumentaDiminuisciQuantita(checkedQuantita);
        else
            return false;

    }else {
        auto ptr = make_shared<Oggetto>(nome,categoria,quantita);
        oggettiDellaLista.insert(make_pair(nome,ptr));
    }
    daComprare+=checkedQuantita;
    cout<<"Oggetto aggiunto\n";
    notify();
    return true;
}

bool ListaSpesa::rimuoviOggetto(const string& oggettoDaRimuovere) {
    auto check = oggettiDellaLista.find(oggettoDaRimuovere);
    if(check==oggettiDellaLista.end()){
        return false;
    }else{
        daComprare-=check->second->getQuantita();
        oggettiDellaLista.erase(check);
        cout<<oggettoDaRimuovere<<" rimosso\n";
        notify();
        return true;
    }
}

bool ListaSpesa::compraOggetto(const string& oggettoDaComprare) {
    auto check = oggettiDellaLista.find(oggettoDaComprare);
    if(check==oggettiDellaLista.end()){
        return false;
    }else {
        check->second->setComprato(true);
        daComprare -= check->second->getQuantita();
        cout<<oggettoDaComprare<<" comprato\n";
        notify();
        return true;
    }
}


