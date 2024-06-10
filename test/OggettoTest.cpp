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

    Oggetto o2("CocaCola","Bibite",-4);
    ASSERT_EQ(o2.getNome(),"CocaCola");
    ASSERT_EQ(o2.getCategoria(),"Bibite");
    ASSERT_EQ(o2.getQuantita(),4);

}

