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

    void update(int progress) override {
        werase(progressWin);  // pulisce la finestra prima di ridisegnare
        box(progressWin, 0, 0);

        int barWidth = 50;
        int filled = (progress * barWidth) / 100;

        mvwprintw(progressWin, 1, 2, "Progress: [");
        for (int i = 0; i < barWidth; ++i) {
            if (i < filled)
                waddch(progressWin, '|');
            else
                waddch(progressWin, '-');
        }
        wprintw(progressWin, "] %3d%%", progress);
        wrefresh(progressWin);
    }

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
