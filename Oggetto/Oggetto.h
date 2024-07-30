//
// Created by pucci on 04/06/2024.
//

#ifndef LABORATORIO_PROGRAMMAZIONE_OGGETTO_H
#define LABORATORIO_PROGRAMMAZIONE_OGGETTO_H


#include <string>
#include <iostream>
#include <utility>

using namespace std;

class Oggetto{
public:
    //-------------- COSTRUTTORE E DISTRUTTORE --------------//
    Oggetto(string  n ,string  c, int q=1): nome(std::move(n)), categoria(std::move(c)), comprato(false){
        if(q>=0)
            quantita=q;
        else
            quantita=-q;
    };
    ~Oggetto()=default;

    //-------------- GETTERS AND SETTERS --------------//

    const string &getNome() const { return nome; }

    void setNome(const string &nome) { this->nome = nome; }

    const string &getCategoria() const { return categoria; }

    void setCategoria(const string &categoria) { this->categoria = categoria; }

    int getQuantita() const { return quantita; }

    void setQuantita(int quantita);

    void aumentaDiminuisciQuantita(int quantita){this->quantita += quantita;}

    bool isComprato() const { return comprato; }

    void setComprato(bool comprato) { this->comprato = comprato; }

    //-------------- OUTPUT --------------//
    friend ostream& operator<<(ostream& os, const Oggetto* o);


private:
    string nome ;
    string categoria;
    int quantita;
    bool comprato;
};


#endif //LABORATORIO_PROGRAMMAZIONE_OGGETTO_H
