//
// Created by Virginia Paolini on 23/04/25.
//

#ifndef LAB_PROGRESSBAR_PROGRESSBAR_H
#define LAB_PROGRESSBAR_PROGRESSBAR_H
#include "Observer.h"
#include "FileLoader.h"

class ProgressBar : public Observer {
public:
    explicit ProgressBar(FileLoader *file) : subject(file) {
        attach();
    }
    ~ProgressBar() override {
        detach();
    }

    void update(int progress) override;

    void attach() override {
        subject->subscribe(this);
    }
    void detach() override {
        subject->unsubscribe(this);
    }

private:
    FileLoader* subject;
};


#endif //LAB_PROGRESSBAR_PROGRESSBAR_H
