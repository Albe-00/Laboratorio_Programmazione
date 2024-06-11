//
// Created by pucci on 04/06/2024.
//

#ifndef LABORATORIO_PROGRAMMAZIONE_LISTASPESA_H
#define LABORATORIO_PROGRAMMAZIONE_LISTASPESA_H

#include "..\ObserverPattern\Subject.h"
#include "..\Oggetto\Oggetto.h"
#include <list>

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
    const std::list<Oggetto*>& getOggetti() const { return oggettiDellaLista; } //Testing

    friend std::ostream& operator<<(ostream& os, const ListaSpesa& lista);

    void aggiungiOggetto(Oggetto* oggetto);
    void aggiungiOggettoInputStream(std::istream& input = std::cin);    //Testing
    void rimuoviOggetto(Oggetto* oggetto);
    void rimuoviOggettoInputStream(std::istream& input = std::cin);    //Testing
    void compraOggetto(Oggetto* oggetto);
    void compraOggettoInputStream(std::istream& input = std::cin);    //Testing

    //------------------------------------//
    //funzioni senza parametri

    void aggiungiOggetto();
    void rimuoviOggetto();
    void compraOggetto();
private:
    string nomeLista;
    list<Observer*> observers;
    list<Oggetto*> oggettiDellaLista;
    int daComprare;

};

#endif //LABORATORIO_PROGRAMMAZIONE_LISTASPESA_H
