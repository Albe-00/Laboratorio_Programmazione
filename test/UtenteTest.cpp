//
// Created by pucci on 05/06/2024.
//

#include "gtest/gtest.h"
#include"../Utente/Utente.h"
#include <sstream>

class TestUtente : public ::testing::Test{
protected:
    void SetUp() override{
        cout<<"-> SetUp-Utente"<<endl;
        lista1->aggiungiOggetto("Nutella", "dolce", 2);
        lista1->aggiungiOggetto("Pane", "Cibo", 2);

        lista2->aggiungiOggetto("CocaCola", "Bevanda", 6);
        lista2->aggiungiOggetto("ipad", "Tablet", 1);

        utente1->aggiungiLista(lista1);
        utente2->aggiungiLista(lista2);
        cout<<"<- Fine SetUp-Utente"<<endl;
    }

    shared_ptr<ListaSpesa> lista1 = make_shared<ListaSpesa>("Lista1");
    shared_ptr<ListaSpesa> lista2 = make_shared<ListaSpesa>("Lista2");
    shared_ptr<ListaSpesa> lista3 = make_shared<ListaSpesa>("Lista3");
    shared_ptr<Utente> utente1 = make_shared<Utente>("Alberto");
    shared_ptr<Utente> utente2 = make_shared<Utente>("Giorgio");


};


TEST_F(TestUtente,TestConstructor) {
    Utente* nuovoUtente = new Utente("Alberto");
    ASSERT_EQ(nuovoUtente->getNome(),"Alberto");
    ASSERT_EQ(nuovoUtente->getNumListe(),0);
}

TEST_F(TestUtente,TestCreaLista) {
    utente1->creaLista("nuovaLista");
    ASSERT_EQ(utente1->getNumListe(),2);
    shared_ptr<ListaSpesa> lista = utente1->getUltimaListaAggiunta();
    ASSERT_EQ(lista->getNome(),"nuovaLista");
}

TEST_F(TestUtente,TestRidefinizioenOperatoreOutput) {
    std::stringstream ss;
    ss<<utente1;
    ASSERT_EQ(ss.str(),"[ Utente: Alberto ]\n"
                       "< Lista1 > - TOTALE RIMANENTI : 4\n"
                       "1) nome : Nutella\t\tcategoria : dolce\t\tquantita : 2\t\t[ X ]\n"
                       "2) nome : Pane\t\tcategoria : Cibo\t\tquantita : 2\t\t[ X ]\n\n"
                       );
}

TEST_F(TestUtente,TestAggiungiLista) {
    utente2->aggiungiLista(lista1);
    ASSERT_EQ(utente2->getNumListe(),2);
}

TEST_F(TestUtente,TestRimuoviLista) {
    utente1->rimuoviLista("Lista1");
    ASSERT_EQ(utente1->getNumListe(),0);
}

TEST_F(TestUtente,TestCondividiLista) {
    string nomeLista="Lista1";
    utente1->condividiLista(utente2,nomeLista);
    ASSERT_EQ(utente1->getNumListe(),1);
    ASSERT_EQ(utente2->getNumListe(),2);
    shared_ptr<ListaSpesa> lista = utente1->getUltimaListaAggiunta();
    ASSERT_EQ(lista->getNome(),nomeLista);

    utente2->rimuoviLista(nomeLista);
    ASSERT_EQ(utente1->getNumListe(),1);
    ASSERT_EQ(utente2->getNumListe(),1);
}