//
// Created by pucci on 05/06/2024.
//

#include "gtest/gtest.h"
#include"../Utente/Utente.h"
#include <sstream>


class TestListaSpesa : public ::testing::Test{
protected:
    void SetUp() override{
        cout<<"-> SetUp-ListaSpesa"<<endl;
        lista1->aggiungiOggetto("Nutella", "dolce", 2);
        lista1->aggiungiOggetto("Pane", "Cibo", 2);
        lista1->aggiungiOggetto("CocaCola", "Bevanda", 1);
        cout<<"<- Fine SetUp-Utente"<<endl;
    }
    ListaSpesa* lista1 = new ListaSpesa("Lista1");
};


TEST_F (TestListaSpesa, TestConstructor) {
    ListaSpesa nuovaLista {"nuovaLista"};
    ASSERT_EQ(nuovaLista.getNome(),"nuovaLista");
    ASSERT_EQ(nuovaLista.getObservers(),0);
    ASSERT_EQ(nuovaLista.getDaComprare(),0);
}

TEST_F (TestListaSpesa, TestRidefinizioenOperatoreOutput) {
    std::stringstream ss;
    ss<<lista1;
    ASSERT_EQ(ss.str(),"< Lista1 > - TOTALE RIMANENTI : 5\n"
                       "1) nome : CocaCola\t\tcategoria : Bevanda\t\tquantita : 1\t\t[ X ]\n"
                       "2) nome : Nutella\t\tcategoria : dolce\t\tquantita : 2\t\t[ X ]\n"
                       "3) nome : Pane\t\tcategoria : Cibo\t\tquantita : 2\t\t[ X ]\n\n"
                       );
}


TEST_F(TestListaSpesa, TestAggiungiOggetto) {
    lista1->aggiungiOggetto("Fanta", "Bevanda", 1);   //5+1=6
    ASSERT_EQ(lista1->getDaComprare(),6);
}

TEST_F(TestListaSpesa, TestRimuoviOggetto) {
    lista1->rimuoviOggetto("Nutella");    //5-2=3
    ASSERT_EQ(lista1->getNumOggetti(),2);
    ASSERT_EQ(lista1->getDaComprare(),3);
}

TEST_F(TestListaSpesa, TestCompraOggetto) {
    lista1->compraOggetto("Nutella");    //5-2=3
    ASSERT_EQ(lista1->getDaComprare(),3);
}

TEST_F(TestListaSpesa, TestObservers) {
    Utente* utente1 = new Utente("Alberto");
    Utente* utente2 = new Utente("Giorgio");
    lista1->subscribe(utente1);
    lista1->subscribe(utente2);
    ASSERT_EQ(lista1->getObservers(),2);
    lista1->unsubscribe(utente1);
    ASSERT_EQ(lista1->getObservers(),1);
    lista1->unsubscribe(utente2);
    ASSERT_EQ(lista1->getObservers(),0);
}
