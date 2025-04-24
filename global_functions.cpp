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

    int progHeight = 3, progWidth = 50;
    int logHeight = 15, logWidth = 60;
    int starty = 1, startx = (COLS - progWidth) / 2;

    progressWin = newwin(progHeight, progWidth, starty, startx);
    box(progressWin, 0, 0);
    wrefresh(progressWin);

    logWin = newwin(logHeight, logWidth, starty + progHeight + 1, startx - 5);
    scrollok(logWin, TRUE);
    box(logWin, 0, 0);
    wrefresh(logWin);
}

void endNcurses() {
    delwin(progressWin);
    delwin(logWin);
    endwin();
}

