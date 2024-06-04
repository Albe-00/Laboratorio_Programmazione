#include "Oggetto/Oggetto.h"

int main() {

    //TEST CLASSE OGGETTO
    auto og1 = new Oggetto("Nutella", "dolce", -2);
    auto og2 = new Oggetto("Pane", "Cibo", 2);

    cout<<og1;

    og1->aumentaDiminuisciQuantita(2);

    cout<<og1;

    og1->aumentaDiminuisciQuantita(-2);

    cout<<og1;


    return 0;
}
