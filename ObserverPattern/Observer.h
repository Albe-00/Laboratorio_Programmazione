//
// Created by pucci on 04/06/2024.
//

#ifndef LABORATORIO_PROGRAMMAZIONE_OBSERVER_H
#define LABORATORIO_PROGRAMMAZIONE_OBSERVER_H

#include <string>

// OBSERVER INTERFACE

class Observer {
public:
    virtual ~Observer() {}

    virtual void update(const std::string& nomeLista , int oggettiMancanti) =0;

};

#endif //LABORATORIO_PROGRAMMAZIONE_OBSERVER_H
