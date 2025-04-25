//
// Created by Virginia Paolini on 24/04/25.
//

#include "global_functions.h"

// Qui invece vanno le definizioni reali!
WINDOW* progressWin = nullptr;
WINDOW* logWin = nullptr;

 void initNcurses() {
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    refresh();

    int progHeight = 3, progWidth = 70;
    int logHeight = 50, logWidth = 50;
    int starty = 1;
    int startx = 5;

    progressWin = newwin(progHeight, progWidth, starty, startx);
    box(progressWin, 0, 0);
    wrefresh(progressWin);

    logWin = newwin(logHeight, logWidth, starty + progHeight + 1, startx);
    scrollok(logWin, TRUE);
    //box(logWin, 0, 0);
    wrefresh(logWin);
}

void endNcurses() {
    delwin(progressWin);
    delwin(logWin);
    endwin();
}

