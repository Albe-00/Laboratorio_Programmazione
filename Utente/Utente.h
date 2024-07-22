//
// Created by pucci on 04/06/2024.
//

#ifndef LABORATORIO_PROGRAMMAZIONE_UTENTE_H
#define LABORATORIO_PROGRAMMAZIONE_UTENTE_H


#include "..\ObserverPattern\Observer.h"
#include "..\ListaSpesa\ListaSpesa.h"


class Utente : public Observer{
public:
    Utente(std::string nome):nome(nome){};
    ~Utente() override;

    void update(const std::string listName, int oggettiMancanti) override;

    friend ostream& operator<<(ostream& os, const Utente& u);

    string getNome() const { return nome; }
    int getNumListe() const { return liste.size(); }
    shared_ptr<ListaSpesa> getUltimaListaAggiunta(){ return liste.rbegin()->second; };
    shared_ptr<ListaSpesa> getLista(string nomeLista) { return liste.find(nomeLista)->second; }

    void creaLista(std::string nomeLista);
    void aggiungiLista(std::shared_ptr<ListaSpesa> nuovaLista);
    void rimuoviLista(std::string nomeLista);
    void condividiLista(shared_ptr<Utente> condivisore , std::string nomeLista);

private:
    std::string nome;
    std::map<string, shared_ptr<ListaSpesa>> liste;
};


#endif //LABORATORIO_PROGRAMMAZIONE_UTENTE_H
