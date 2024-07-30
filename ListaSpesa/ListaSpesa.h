//
// Created by pucci on 04/06/2024.
//

#ifndef LABORATORIO_PROGRAMMAZIONE_LISTASPESA_H
#define LABORATORIO_PROGRAMMAZIONE_LISTASPESA_H

#include "..\ObserverPattern\Subject.h"
#include "..\Oggetto\Oggetto.h"
#include <list>
#include <memory>
#include <map>
#include <utility>

class ListaSpesa : public Subject{
public:
    explicit ListaSpesa(string  nome):nomeLista(std::move(nome)),daComprare(0){};
    ~ListaSpesa() override =default;

    void subscribe(Observer* o) override;
    void unsubscribe(Observer* o) override;
    void notify() override;

    const string &getNome() const{ return nomeLista;};


    int getDaComprare() const { return daComprare; }    //Testing
    int getObservers() const { return int(observers.size()); } //Testing

    friend ostream& operator<<(ostream& os, const ListaSpesa* lista);

    bool aggiungiOggetto(const string& nome , const string& categoria , int quantita);
    bool rimuoviOggetto(const string& oggettoDaRimuovere);
    bool compraOggetto(const string& oggettoDaComprare);
private:
    string nomeLista;
    list<Observer*> observers;
    map<string , shared_ptr<Oggetto>> oggettiDellaLista;
    int daComprare;

};

#endif //LABORATORIO_PROGRAMMAZIONE_LISTASPESA_H
