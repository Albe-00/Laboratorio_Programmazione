//
// Created by pucci on 04/06/2024.
//

#ifndef LABORATORIO_PROGRAMMAZIONE_SUBJECT_H
#define LABORATORIO_PROGRAMMAZIONE_SUBJECT_H

#include "Observer.h"

//SUBJECT INTERFACE

class Subject {
public:

    virtual void subscribe(Observer* o)=0;
    virtual void unsubscribe(Observer* o)=0;

    virtual void notify()=0;

    virtual ~Subject() = default;
};

#endif //LABORATORIO_PROGRAMMAZIONE_SUBJECT_H


