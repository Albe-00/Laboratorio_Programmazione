#include "Utente/Utente.h"

int main(){
    map<string, shared_ptr<Utente>> utenti;
    int sceltaMenu1 = 0;
    string nome , utenteCorrente;
    while(sceltaMenu1!=3){
        utenteCorrente="";
        system("cls");
        cout<<"Benvenuto nel programma di gestione delle liste della spesa\n";
        cout<<"1) Accedi\n";
        cout<<"2) Registrati\n";
        cout<<"3) Chiudi App\n";
        cin>>sceltaMenu1;
        switch (sceltaMenu1) {
            case 1:
                if(utenti.empty()){
                    cout << "Nessun utente registrato , procedere con la registrazione" << endl;
                    system("pause");
                    break;
                }
                cout << "Inserisci il tuo nome : ";
                cin >> nome;
                if(utenti.find(nome) == utenti.end()) {
                    cout << "Utente non presente" << endl;
                    system("pause");
                    break;
                }
                utenteCorrente = nome;
                system("cls");
                cout << "Benvenuto " << nome << endl;
                break;
            case 2:
                cout << "Inserisci il tuo nome : ";
                cin >> nome;
                if (utenti.find(nome) != utenti.end()) {
                    cout << "Nome gia' in uso" << endl;
                    break;
                }
                utenti.insert(make_pair(nome, make_shared<Utente>(nome)));
                utenteCorrente = nome;
                system("cls");
                cout << "Benvenuto " << nome << endl;
                break;
            case 3:
                cout<<"A presto , Spegnimento ..."<<endl;
                return 0;
        }

        //-------------------------------------------------------------------------------
        if(utenteCorrente!="") {
            int sceltaMenu2 = 0;
            while (sceltaMenu2 != 7) {
                cout << utenti.find(nome)->second;
                cout << "Cosa vuoi fare ?" << endl;
                cout << "1) Crea una nuova lista" << endl;
                cout << "2) Cancella una lista esistente" << endl;
                cout << "3) Condividi una lista con un'altro utente" << endl;
                cout << "4) Aggiungi un oggetto ad una lista" << endl;
                cout << "5) Rimuovi un oggetto da una lista" << endl;
                cout << "6) Compra un oggetto" << endl;
                cout << "7) Esci" << endl;
                cin >> sceltaMenu2;
                string nomeUtente, nomeLista, nomeOggetto, categoria;
                switch (sceltaMenu2) {
                    case 1:
                        system("cls");
                        cout << "Inserisci il nome della lista : ";
                        cin >> nomeLista;
                        utenti.find(nome)->second->creaLista(nomeLista);
                        break;
                    case 2:
                        system("cls");
                        if (utenti.find(nome)->second->getNumListe() == 0)
                            cout << "Impossibile cancellare , Nessuna lista presente" << endl;
                        else {
                            cout << utenti.find(nome)->second;
                            cout << "Inserisci il nome della lista da cancellare : ";
                            cin >> nomeLista;
                            utenti.find(nome)->second->rimuoviLista(nomeLista);
                        }
                        break;
                    case 3:
                        system("cls");
                        if (utenti.find(nome)->second->getNumListe() == 0 ) {
                            cout<< "Impossibile condividere , Nessuna lista presente"<< endl;
                            break;
                        }
                        if(utenti.size() == 1){
                            cout<< "Impossibile condividere , Nessun utente con cui poter condividere"<< endl;
                            break;
                        }
                        cout << utenti.find(nome)->second;
                        cout << "Inserisci il nome della lista da condividere : ";
                        cin >> nomeLista;
                        system("cls");
                        for (auto it = utenti.begin(); it != utenti.end(); it++) {
                            if (it->first != nome)
                                cout << "-) " << it->first << endl;
                        }
                        cout << "Inserisci il nome dell'utente con cui condividere la lista : ";
                        cin >> nomeUtente;
                        utenti.find(nome)->second->condividiLista(utenti.find(nomeUtente)->second, nomeLista);
                        break;
                    case 4:
                        system("cls");
                        if (utenti.find(nome)->second->getNumListe() == 0)
                            cout << "Impossibile aggiungere un oggetto , Nessuna lista presente" << endl;
                        else {
                            cout << utenti.find(nome)->second;
                            cout << "Inserisci il nome della lista a cui aggiungere l'oggetto : ";
                            cin >> nomeLista;
                            if (utenti.find(nome)->second->getLista(nomeLista) == nullptr) {
                                cout << "Lista non trovata" << endl;
                                break;
                            }
                            cout << "Inserisci il nome dell'oggetto : ";
                            cin >> nomeOggetto;
                            cout << "Inserisci la categoria : ";
                            cin >> categoria;
                            cout << "Inserisci la quantita' : ";
                            int quantita;
                            cin >> quantita;
                            utenti.find(nome)->second->getLista(nomeLista)->aggiungiOggetto(nomeOggetto, categoria,quantita);
                        }
                        break;
                    case 5:
                        system("cls");
                        if (utenti.find(nome)->second->getNumListe() == 0)
                            cout << "Impossibile rimuovere un oggetto , Nessuna lista presente" << endl;
                        else {
                            cout << utenti.find(nome)->second;
                            cout << "Inserisci il nome della lista da cui rimuovere l'oggetto : ";
                            cin >> nomeLista;
                            if (utenti.find(nome)->second->getLista(nomeLista) == nullptr) {
                                cout << "Lista non trovata" << endl;
                                break;
                            }
                            cout << "Inserisci il nome dell'oggetto : ";
                            cin >> nomeOggetto;
                            utenti.find(nome)->second->getLista(nomeLista)->rimuoviOggetto(nomeOggetto);
                        }
                        break;
                    case 6:
                        system("cls");
                        if (utenti.find(nome)->second->getNumListe() == 0)
                            cout << "Impossibile comprare un oggetto , Nessuna lista presente" << endl;
                        else {
                            cout << utenti.find(nome)->second;
                            cout << "Inserisci il nome della lista da cui comprare l'oggetto : ";
                            cin >> nomeLista;
                            cout << "Inserisci il nome dell'oggetto da comprare : ";
                            cin >> nomeOggetto;
                            utenti.find(nome)->second->getLista(nomeLista)->compraOggetto(nomeOggetto);
                        }
                        break;
                    case 7:
                        cout << "Arrivederci " << nome << endl;
                        break;
                    default:
                        cout << "Scelta non valida" << endl;
                        break;
                }
                system("pause");
                system("cls");
            }
        }
    }
}
