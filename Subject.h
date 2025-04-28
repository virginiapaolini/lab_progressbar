//
// Created by Virginia Paolini on 23/04/25.
//

#ifndef LAB_PROGRESSBAR_SUBJECT_H
#define LAB_PROGRESSBAR_SUBJECT_H

#include <list>
#include <string>
#include "Observer.h"
#include <iostream>
using namespace std;

class Subject {
public:
    virtual ~Subject() = default;
    virtual void subscribe(Observer* o) = 0;
    virtual void unsubscribe(Observer* o) = 0;
    virtual void notify(int progress) const = 0;
};

#endif //LAB_PROGRESSBAR_SUBJECT_H
