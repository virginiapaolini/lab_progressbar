//
// Created by Virginia Paolini on 23/04/25.
//

#ifndef LAB_PROGRESSBAR_OBSERVER_H
#define LAB_PROGRESSBAR_OBSERVER_H

class Observer {
public:
    virtual ~Observer() = default;
    virtual void update (int progress) = 0;
    virtual void attach () = 0;
    virtual void detach () = 0;
};

#endif //LAB_PROGRESSBAR_OBSERVER_H
