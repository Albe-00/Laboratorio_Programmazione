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

ostream& operator<<(ostream& os, const ListaSpesa& lista){
    os<<"< "<<lista.nomeLista<<" > - TOTALE RIMANENTI : "<<lista.daComprare<<"\n";
    if(lista.oggettiDellaLista.empty())
        os<<"Lista vuota\n\n";
    else {
        int i = 1;
        for (auto ptr: lista.oggettiDellaLista) {
            os << i++ << ") ";
            os << ptr;
        }
        os << "\n";
    }
    return os;
}

void ListaSpesa::aggiungiOggetto(Oggetto *oggetto) {
    for(auto o : oggettiDellaLista)
        if(oggetto->getNome()==o->getNome() && oggetto->getCategoria()==o->getCategoria()) {
            o->aumentaDiminuisciQuantita(oggetto->getQuantita());
            daComprare+=oggetto->getQuantita();
            notify();
            cout<<"Oggetto aggiunto"<<endl;
            return;
        }
    oggettiDellaLista.push_back(oggetto);
    daComprare+=oggetto->getQuantita();
    notify();
    cout<<"Oggetto aggiunto"<<endl;
}

void ListaSpesa::rimuoviOggetto(Oggetto *oggetto) {
    for(auto o : oggettiDellaLista)
        if(oggetto->getNome()==o->getNome() && oggetto->getCategoria()==o->getCategoria()) {
            daComprare-=oggetto->getQuantita();
            oggettiDellaLista.remove(oggetto);
            notify();
            cout<<"Oggetto rimosso"<<endl;
            return;
        }
    cout<<"Oggetto non trovato"<<endl;
}

void ListaSpesa::compraOggetto(Oggetto *oggetto) {
    for(auto o : oggettiDellaLista)
        if(oggetto->getNome()==o->getNome() && oggetto->getCategoria()==o->getCategoria()) {
            o->setComprato(true);
            daComprare-=oggetto->getQuantita();
            notify();
            cout<<"Oggetto comprato"<<endl;
            return;
        }
    cout<<"Oggetto non trovato"<<endl;
}

//funzioni senza parametri

void ListaSpesa::aggiungiOggetto() {
    string nome;
    string categoria;
    int quantita;
    cout<<"Inserisci il nome dell'oggetto: ";
    cin>>nome;
    cout<<"Inserisci la categoria dell'oggetto: ";
    cin>>categoria;
    cout<<"Inserisci la quantita dell'oggetto: ";
    cin>>quantita;
    auto oggetto = new Oggetto(nome, categoria, quantita);
    aggiungiOggetto(oggetto);
}

void ListaSpesa::aggiungiOggettoInputStream(std::istream &input) {
    std::string nome;
    std::string categoria;
    int quantita;
    std::cout << "Inserisci il nome dell'oggetto: ";
    input >> nome;
    std::cout << "Inserisci la categoria dell'oggetto: ";
    input >> categoria;
    std::cout << "Inserisci la quantita dell'oggetto: ";
    input >> quantita;
    auto oggetto = new Oggetto(nome, categoria, quantita);
    oggettiDellaLista.push_back(oggetto);
    daComprare+=quantita;
    notify();
}

void ListaSpesa::rimuoviOggetto() {
    string nome;
    cout << "Inserisci il nome dell'oggetto da rimuovere: ";
    cin >> nome;
    for (auto oggetto: oggettiDellaLista) {
        if (oggetto->getNome() == nome) {
            oggettiDellaLista.remove(oggetto);
            daComprare -= oggetto->getQuantita();
            notify();
            cout << "Oggetto rimosso" << endl;
            return;
        }
    }
    cout << "Oggetto non trovato" << endl;
    return;
}

void ListaSpesa::rimuoviOggettoInputStream(std::istream &input) {
    std::string nome;
    std::cout << "Inserisci il nome dell'oggetto da rimuovere: ";
    input >> nome;
    for (auto oggetto: oggettiDellaLista) {
        if (oggetto->getNome() == nome) {
            oggettiDellaLista.remove(oggetto);
            daComprare -= oggetto->getQuantita();
            notify();
            return;
        }
    }
    std::cout << "Oggetto non trovato" << std::endl;
    return;
}

void ListaSpesa::compraOggetto() {
    string nome;
    cout << "Inserisci il nome dell'oggetto da comprare: ";
    cin >> nome;
    for (auto oggetto: oggettiDellaLista) {
        if (oggetto->getNome() == nome) {
            oggetto->setComprato(true);
            daComprare -= oggetto->getQuantita();
            notify();
            cout << "Oggetto comprato" << endl;
            return;
        }
    }
    cout << "Oggetto non trovato" << endl;
    return;
}

void ListaSpesa::compraOggettoInputStream(std::istream &input) {
    string nome;
    cout << "Inserisci il nome dell'oggetto da comprare: ";
    input >> nome;
    for (auto oggetto: oggettiDellaLista) {
        if (oggetto->getNome() == nome) {
            oggetto->setComprato(true);
            daComprare -= oggetto->getQuantita();
            notify();
            cout << "Oggetto comprato" << endl;
            return;
        }
    }
    cout << "Oggetto non trovato" << endl;
    return;
}
