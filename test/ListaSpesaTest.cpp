//
// Created by pucci on 05/06/2024.
//

#include "gtest/gtest.h"
#include"../Utente/Utente.h"


class TestListaSpesa : public ::testing::Test{
protected:
    void SetUp() override{
        lista1.aggiungiOggetto(&og1);
        lista1.aggiungiOggetto(&og2);
        lista1.aggiungiOggetto(&og3);
    }
    Oggetto og1 {"Nutella", "dolce", 2};
    Oggetto og2 {"Pane", "Cibo", 2};
    Oggetto og3 {"CocaCola", "Bevanda", 1};
    ListaSpesa lista1 {"Lista1"};
};


TEST_F(TestListaSpesa, TestConstructor) {
    ASSERT_EQ(lista1.getNome(),"Lista1");
    ASSERT_EQ(lista1.getDaComprare(),5);
}

TEST_F(TestListaSpesa, TestAggiungiOggetto) {
    Utente utente1("Alberto");
    lista1.subscribe(&utente1);
    Oggetto nuovo {"Fanta", "Bevanda", 1};
    lista1.aggiungiOggetto(&nuovo);   //5+1=6
    ASSERT_EQ(lista1.getDaComprare(),6);
    ASSERT_EQ(lista1.getObservers(),1);
}

TEST_F(TestListaSpesa, TestCompraOggetto) {
    Utente utente1("Alberto");
    lista1.subscribe(&utente1);
    lista1.compraOggetto(&og1);    //5-2=3
    ASSERT_EQ(lista1.getDaComprare(),3);
    ASSERT_EQ(lista1.getObservers(),1);
}

TEST_F(TestListaSpesa, TestRimuoviOggetto) {
    Utente utente1("Alberto");
    lista1.subscribe(&utente1);
    lista1.rimuoviOggetto(&og1);    //5-2=3
    ASSERT_EQ(lista1.getDaComprare(),3);
    ASSERT_EQ(lista1.getObservers(),1);
}



TEST_F(TestListaSpesa, TestObservers) {
    Utente utente1("Alberto");
    Utente utente2("Giorgio");
    lista1.subscribe(&utente1);
    lista1.subscribe(&utente2);
    ASSERT_EQ(lista1.getObservers(),2);
    lista1.unsubscribe(&utente1);
    ASSERT_EQ(lista1.getObservers(),1);
    lista1.unsubscribe(&utente2);
    ASSERT_EQ(lista1.getObservers(),0);
}