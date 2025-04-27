//
// Created by Virginia Paolini on 24/04/25.
//

#include "global_functions.h"

// inizializza le finestre
WINDOW* progressWin = nullptr;
WINDOW* logWin = nullptr;

 void initNcurses() {
    initscr(); //prepara la libreria per essere utilizzata
    curs_set(0); //per rendere invisibile il cursore
    refresh(); // per visualizzare effettivamente le cose

    int progHeight = 3, progWidth = 70;
    int logHeight = 50, logWidth = 50;
    int starty = 1;
    int startx = 5;

    progressWin = newwin(progHeight, progWidth, starty, startx);
    box(progressWin, 0, 0); // crea un box per la finestra con coordinate
    wrefresh(progressWin);

    logWin = newwin(logHeight, logWidth, starty + progHeight + 1, startx);
    scrollok(logWin, TRUE);
    //per abilitare lo scroll dello schermo se l’output vada oltre l’ultima riga disponibile
    wrefresh(logWin);
}

void endNcurses() {
    delwin(progressWin); //elimina la finestra progressWin
    delwin(logWin); //elimina la finestra logWin
    endwin(); //chiude la libreria
}

