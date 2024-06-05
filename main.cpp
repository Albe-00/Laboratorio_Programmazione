#include "Utente/Utente.h"

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

    /*lista1->aggiungiOggetto();

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
    system("pause");*/


    //TEST CLASSE UTENTE

    auto utente1 = new Utente("Alberto");
    auto utente2 = new Utente("Vittoria");
    auto utente3 = new Utente("Giorgio");

    utente1->aggiungiLista(*lista1);
    utente1->aggiungiLista(*lista2);

    utente2->aggiungiLista(*lista1);

    utente3->aggiungiLista(*lista1);
    utente3->aggiungiLista(*lista2);

    utente1->compraOggetto();

    cout<<*utente1;
    system("pause");
    system("cls");

    utente1->creaLista();

    cout<<*utente1;
    system("pause");
    system("cls");

    utente1->aggiungiOggettoALista();

    cout<<*utente1;
    system("pause");
    system("cls");

    utente1->condividiLista(utente2);

    cout<<*utente1<<*utente2;
    system("pause");
    system("cls");

    utente1->aggiungiOggettoALista();

    cout<<*utente1<<*utente2;
    system("pause");
    system("cls");

    utente1->cancellaOggettoDaLista();

    cout<<*utente1<<*utente2;
    system("pause");
    system("cls");

    utente1->rimuoviLista();

    cout<<*utente1<<*utente2;


    return 0;
}
