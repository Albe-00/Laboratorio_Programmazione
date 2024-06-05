#include "ListaSpesa/ListaSpesa.h"

int main() {

    //TEST CLASSE OGGETTO
    auto og1 = new Oggetto("Nutella", "dolce", -2);
    auto og2 = new Oggetto("Pane", "Cibo", 2);

    /*cout<<og1;

    og1->aumentaDiminuisciQuantita(2);

    cout<<og1;

    og1->aumentaDiminuisciQuantita(-2);

    cout<<og1;*/


    //TEST CLASSE LISTASPESA
    auto lista1 = new ListaSpesa("Lista1");
    auto lista2 = new ListaSpesa("Lista2");
    lista1->aggiungiOggetto(og1);
    lista1->aggiungiOggetto(og1);
    lista1->aggiungiOggetto(og2);
    lista1->aggiungiOggetto();

    system("cls");
    cout<<*lista1;
    system("pause");
    system("cls");

    //lista1->compraOggetto(og1);
    lista1->compraOggetto();

    cout<<*lista1;
    system("pause");
    system("cls");

    //lista1->rimuoviOggetto(og1);
    lista1->rimuoviOggetto();

    cout<<*lista1;
    system("pause");


    return 0;
}
