//
// Created by pucci on 04/06/2024.
//

#ifndef LABORATORIO_PROGRAMMAZIONE_UTENTE_H
#define LABORATORIO_PROGRAMMAZIONE_UTENTE_H


#include "..\ObserverPattern\Observer.h"
#include "..\ListaSpesa\ListaSpesa.h"
#include <memory>
#include <map>


class Utente : public Observer{
public:
    Utente(std::string nome):nome(nome){};
    ~Utente() override;

    void update(const std::string listName, int oggettiMancanti) override;

    friend ostream& operator<<(ostream& os, const Utente& u);

    string getNome() const { return nome; }
    int getNumListe() const { return liste.size(); }


    void creaLista();
    void aggiungiLista(ListaSpesa& nuovaLista);
    void rimuoviLista();
    void condividiLista(Utente* condivisore);

    void aggiungiOggettoALista();
    void cancellaOggettoDaLista();
    void compraOggetto();


private:
    std::string nome;
    std::map<string, shared_ptr<ListaSpesa>> liste;
};


#endif //LABORATORIO_PROGRAMMAZIONE_UTENTE_H
