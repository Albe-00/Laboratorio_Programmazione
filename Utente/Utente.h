//
// Created by pucci on 04/06/2024.
//

#ifndef LABORATORIO_PROGRAMMAZIONE_UTENTE_H
#define LABORATORIO_PROGRAMMAZIONE_UTENTE_H


#include <utility>

#include "..\ObserverPattern\Observer.h"
#include "..\ListaSpesa\ListaSpesa.h"


class Utente : public Observer{
public:
    explicit Utente(string nome):nome(std::move(nome)){};
    ~Utente() override;

    void update(const string& nomeLista, int oggettiMancanti) override;

    friend ostream& operator<<(ostream& os, const Utente* u);

    string getNome() const { return nome; }     //Testing
    int getNumListe() const { return int(liste.size()); }   //Testing
    shared_ptr<ListaSpesa> getUltimaListaAggiunta(){ return liste.rbegin()->second; };  //Testing
    shared_ptr<ListaSpesa> getLista(const string& nomeLista) { return liste.find(nomeLista)->second; }

    bool creaLista(const string& nuovoNome);
    bool aggiungiLista(const shared_ptr<ListaSpesa>& nuovaLista);
    bool rimuoviLista(const string& nomeLista);
    bool condividiLista(const shared_ptr<Utente>& condivisore , const string& nomeLista);

private:
    string nome;
    map<string, shared_ptr<ListaSpesa>> liste;
};


#endif //LABORATORIO_PROGRAMMAZIONE_UTENTE_H
