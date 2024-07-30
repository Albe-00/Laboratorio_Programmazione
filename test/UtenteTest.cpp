//
// Created by pucci on 05/06/2024.
//

#include "gtest/gtest.h"
#include"../Utente/Utente.h"
#include <sstream>

class TestUtente : public ::testing::Test{
protected:
    void SetUp() override{
        lista1->aggiungiOggetto("Nutella", "dolce", 2);
        lista1->aggiungiOggetto("Pane", "Cibo", 2);

        lista2->aggiungiOggetto("CocaCola", "Bevanda", 6);
        lista2->aggiungiOggetto("ipad", "Tablet", 1);

        utente1->aggiungiLista(lista1);
        utente1->aggiungiLista(lista3);
        utente2->aggiungiLista(lista2);
    }

    shared_ptr<ListaSpesa> lista1 = make_shared<ListaSpesa>("Lista1");
    shared_ptr<ListaSpesa> lista2 = make_shared<ListaSpesa>("Lista2");
    shared_ptr<ListaSpesa> lista3 = make_shared<ListaSpesa>("Lista3");
    shared_ptr<Utente> utente1 = make_shared<Utente>("Alberto");
    shared_ptr<Utente> utente2 = make_shared<Utente>("Giorgio");


};


TEST_F(TestUtente,TestConstructor) {
    auto nuovoUtente = new Utente("Alberto");
    string nome = nuovoUtente->getNome();
    ASSERT_EQ(nuovoUtente->getNome(),"Alberto");
    ASSERT_EQ(nuovoUtente->getNumListe(),0);
}

TEST_F(TestUtente,TestCreaLista) {
    ASSERT_EQ(utente1->creaLista("nuovaLista") , true);                 //creo una nuova lista

    shared_ptr<ListaSpesa> lista = utente1->getUltimaListaAggiunta();
    ASSERT_EQ(lista->getNome(),"nuovaLista");
    ASSERT_EQ(utente1->getNumListe(),3);                              //2+1=3

    ASSERT_EQ(utente1->creaLista("nuovaLista") , false);                //provo a creare una lista con lo stesso nome
    ASSERT_EQ(utente1->getNumListe(),3);                              //3+0=3
}

TEST_F(TestUtente,TestRidefinizioenOperatoreOutput) {
    std::stringstream ss;
    ss<<utente1;
    ASSERT_EQ(ss.str(),"[ Utente: Alberto ]\n"
                       "< Lista1 > - TOTALE RIMANENTI : 4\n"
                       "1) nome : Nutella\t\tcategoria : dolce\t\tquantita : 2\t\t[ X ]\n"
                       "2) nome : Pane\t\tcategoria : Cibo\t\tquantita : 2\t\t[ X ]\n\n"
                       "< Lista3 > - TOTALE RIMANENTI : 0\n"
                       "Lista vuota\n\n"
                       );
}

TEST_F(TestUtente,TestAggiungiLista) {
    auto nuovaLista = make_shared<ListaSpesa>("nuovaLista");
    ASSERT_EQ(utente1->aggiungiLista(nuovaLista) , true);       //aggiungo una lista
    ASSERT_EQ(utente1->getNumListe(),3);                        //2+1=3
    ASSERT_EQ(utente1->aggiungiLista(nuovaLista) , false);      //provo ad aggiungere una lista con lo stesso nome
                                                                //(non dipende dal contenuto della lista passata ma solo dal nome )
                                                                //(in quanto chiave della mappa)
    ASSERT_EQ(utente1->getNumListe(),3);                        //3+0=3
}

TEST_F(TestUtente,TestRimuoviLista) {
    ASSERT_EQ(utente1->rimuoviLista("Lista1") , true);      //rimuovo una lista
    ASSERT_EQ(utente1->getNumListe(),1);                    //2-1=1
    ASSERT_EQ(utente1->rimuoviLista("Lista1") , false);     //provo a rimuovere una lista non presente
    ASSERT_EQ(utente1->getNumListe(),1);                    //1-0=1

}

TEST_F(TestUtente,TestCondividiLista) {
    ASSERT_EQ(utente1->condividiLista(utente2,"ListaNonPresente"), false);  //provo a condividere una lista non presente
                                                                            //nell'utente1
    ASSERT_EQ(utente1->getNumListe(),2);
    ASSERT_EQ(utente2->getNumListe(),1);


    ASSERT_EQ(utente1->condividiLista(utente2,"Lista1"), true);     //condivido la lista1 con l'utente2
    ASSERT_EQ(utente1->getNumListe(),2);
    ASSERT_EQ(utente2->getNumListe(),2);

    utente2->creaLista("Lista1");
    ASSERT_EQ(utente1->condividiLista(utente2,"Lista1"), false);    //provo a condividere una lista con nome gia' esistente
                                                                    //nell'utente2
    ASSERT_EQ(utente1->getNumListe(),2);
    ASSERT_EQ(utente2->getNumListe(),2);

}