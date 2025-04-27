//
// Created by Virginia Paolini on 24/04/25.
//

#ifndef LAB_PROGRESSBAR_GLOBAL_FUNCTIONS_H
#define LAB_PROGRESSBAR_GLOBAL_FUNCTIONS_H

#include <ncurses.h>
#include <unistd.h>

extern WINDOW* progressWin; // crea finestra x progresso
extern WINDOW* logWin; // crea finestra x log

void initNcurses(); // funzione per inizializzare ncurses
void endNcurses(); //funzione per terminare ncurses


#endif //LAB_PROGRESSBAR_GLOBAL_FUNCTIONS_H
