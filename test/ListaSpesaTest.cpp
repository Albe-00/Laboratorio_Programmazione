//
// Created by pucci on 05/06/2024.
//

#include "gtest/gtest.h"
#include"../Utente/Utente.h"


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
    ASSERT_EQ(lista1->aggiungiOggetto("Fanta", "Bevanda", 1) , true);       //aggiungo un nuovo oggetto
    ASSERT_EQ(lista1->getDaComprare(),6);                                   //5+1=6
    ASSERT_EQ(lista1->aggiungiOggetto("Fanta", "Maglietta", 1) , false);    //oggetto con stesso nome ma categoria diversa
    ASSERT_EQ(lista1->getDaComprare(),6);                                   //6+0=6
    ASSERT_EQ(lista1->aggiungiOggetto("Fanta", "Bevanda", 1) , true);       //incremento la quantita' di un oggetto gia' presente
    ASSERT_EQ(lista1->getDaComprare(),7);                                   //6+1=7
}

TEST_F(TestListaSpesa, TestRimuoviOggetto) {
    ASSERT_EQ(lista1->rimuoviOggetto("Nutella") , true);    //rimuovo un oggetto
    ASSERT_EQ(lista1->getDaComprare(),3);                   //5-2=3
    ASSERT_EQ(lista1->rimuoviOggetto("iPad") , false);      //provo a rimuovere un oggetto non presente
    ASSERT_EQ(lista1->getDaComprare(),3);                   //3-0=3
}

TEST_F(TestListaSpesa, TestCompraOggetto) {
    ASSERT_EQ(lista1->compraOggetto("Nutella") , true);     //compro un oggetto
    ASSERT_EQ(lista1->getDaComprare(),3);                   //5-2=3
    ASSERT_EQ(lista1->compraOggetto("iPad") , false);       //provo a comprare un oggetto non presente
    ASSERT_EQ(lista1->getDaComprare(),3);                   //3-0=3
}

TEST_F(TestListaSpesa, TestObservers) {
    auto utente1 = new Utente("Alberto");
    auto utente2 = new Utente("Giorgio");
    lista1->subscribe(utente1);
    lista1->subscribe(utente2);
    ASSERT_EQ(lista1->compraOggetto("Nutella") , true);     //compro un oggetto e notifico gli utenti
    ASSERT_EQ(lista1->getObservers(),2);
    lista1->unsubscribe(utente1);
    ASSERT_EQ(lista1->getObservers(),1);
    lista1->unsubscribe(utente2);
    ASSERT_EQ(lista1->getObservers(),0);
}
