cmake_minimum_required(VERSION 3.25)
project(Laboratorio_Programmazione)

set(CMAKE_CXX_STANDARD 17)

add_executable(Laboratorio_Programmazione main.cpp Oggetto/Oggetto.cpp Oggetto/Oggetto.h ListaSpesa/ListaSpesa.cpp ListaSpesa/ListaSpesa.h ObserverPattern/Observer.h ObserverPattern/Subject.h Utente/Utente.cpp Utente/Utente.h)
