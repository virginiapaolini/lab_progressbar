//
// Created by Virginia Paolini on 24/04/25.
//

#ifndef LAB_PROGRESSBAR_GLOBAL_FUNCTIONS_H
#define LAB_PROGRESSBAR_GLOBAL_FUNCTIONS_H

#include <ncurses.h>
#include <unistd.h>

extern WINDOW* progressWin;
extern WINDOW* logWin;

void initNcurses();
void endNcurses();


#endif //LAB_PROGRESSBAR_GLOBAL_FUNCTIONS_H
