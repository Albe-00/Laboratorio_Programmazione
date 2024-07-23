//
// Created by pucci on 05/06/2024.
//

#include "gtest/gtest.h"
#include"../Oggetto/oggetto.h"


TEST(TestOggetto,TestCostruttore)
{
    Oggetto o("CocaCola","Bibite",4);
    ASSERT_EQ(o.getNome(),"CocaCola");
    ASSERT_EQ(o.getCategoria(),"Bibite");
    ASSERT_EQ(o.getQuantita(),4);
    ASSERT_EQ(o.isComprato(),false);

    Oggetto o2("CocaCola","Bibite",-4);
    ASSERT_EQ(o2.getNome(),"CocaCola");
    ASSERT_EQ(o2.getCategoria(),"Bibite");
    ASSERT_EQ(o2.getQuantita(),4);
    ASSERT_EQ(o2.isComprato(),false);

}

TEST(TestOggetto,TestSettersGetters)
{
    Oggetto o("CocaCola","Bibite",4);
    o.setNome("Fanta");
    o.setCategoria("Bibite");
    o.setQuantita(3);
    o.setComprato(true);
    ASSERT_EQ(o.getNome(),"Fanta");
    ASSERT_EQ(o.getCategoria(),"Bibite");
    ASSERT_EQ(o.getQuantita(),3);
    ASSERT_EQ(o.isComprato(),true);
}

TEST(TestOggetto,TestAumentaDiminuisciQuantita)
{
    Oggetto o("CocaCola","Bibite",4);
    o.aumentaDiminuisciQuantita(3);
    ASSERT_EQ(o.getQuantita(),7);
    o.aumentaDiminuisciQuantita(-2);
    ASSERT_EQ(o.getQuantita(),5);
}

TEST(TestOggetto,TestRidefinizioenOperatoreOutput)
{
    Oggetto o("CocaCola","Bibite",4);
    std::stringstream ss;
    ss<<&o;
    ASSERT_EQ(ss.str(),"nome : CocaCola\t\tcategoria : Bibite\t\tquantita : 4\t\t[ X ]\n");
    o.setComprato(true);
    std::stringstream ss2;
    ss2<<&o;
    ASSERT_EQ(ss2.str(),"nome : CocaCola\t\tcategoria : Bibite\t\tquantita : 4\t\t[ V ]\n");
}



