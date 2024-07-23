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

class ListaSpesa : public Subject{
public:
    ListaSpesa(string nome):nomeLista(nome),daComprare(0){};
    ~ListaSpesa()=default;

    void subscribe(Observer* o) override;
    void unsubscribe(Observer* o) override;
    void notify() override;

    const string &getNome() const{ return nomeLista;};

    const int getDaComprare() const { return daComprare; }
    const int getObservers() const { return observers.size(); } //Testing
    const int getNumOggetti() const { return oggettiDellaLista.size(); } //Testing

    friend std::ostream& operator<<(ostream& os, const ListaSpesa* lista);

    void aggiungiOggetto(const string nome , const string categoria , const int quantita);
    void rimuoviOggetto(const string oggettoDaRimuovere);
    void compraOggetto(const string oggettoDaComprare);
private:
    string nomeLista;
    list<Observer*> observers;
    map<string , shared_ptr<Oggetto>> oggettiDellaLista;
    int daComprare;

};

#endif //LABORATORIO_PROGRAMMAZIONE_LISTASPESA_H
