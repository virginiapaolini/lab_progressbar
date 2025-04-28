//
// Created by Virginia Paolini on 23/04/25.
//

#include "ProgressBar.h"

void ProgressBar::update(int progress) {
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
