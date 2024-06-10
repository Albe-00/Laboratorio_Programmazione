cmake_minimum_required(VERSION 3.25)
project(Laboratorio_Programmazione)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(test)

set( SOURCE_FILES
        ObserverPattern/Subject.h
        ObserverPattern/Observer.h
        Oggetto/Oggetto.cpp
        Oggetto/Oggetto.h
        ListaSpesa/ListaSpesa.cpp
        ListaSpesa/ListaSpesa.h
        Utente/Utente.cpp
        Utente/Utente.h
        )

add_executable(Laboratorio_Programmazione main.cpp)

add_library(core ${SOURCE_FILES})

target_link_libraries(Laboratorio_Programmazione core)