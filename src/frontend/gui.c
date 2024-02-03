//
// Created by kubun on 29/01/24.
//

#include "gui.h"
#include "ncurses.h"

void display(ProcessInfo *processList, int numProc){
    initscr();
    scrollok(stdscr, TRUE);

    start_color();

    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);

    attron(COLOR_PAIR(1));
    mvprintw(0, 0, "PID");
    mvprintw(0, 10, "Process Name");
    attroff(COLOR_PAIR(1));

    for (int i = 0; i < numProc; ++i) {
        if (i % 2 == 0){
            attron(COLOR_PAIR(1));
        } else {
            attron(COLOR_PAIR(2));
        }

        mvprintw(i + 1, 0, "%d", processList[i].pid);

        int maxLength = 30;
        char truncatedName[40];
        snprintf(truncatedName, sizeof(truncatedName), "%.36s", processList[i].name);

        mvprintw(i + 1, 10, "%.*s", maxLength, processList[i].name);

        if (i % 2 == 0){
            attroff(COLOR_PAIR(1));
        } else {
            attroff(COLOR_PAIR(2));
        }
    }
    refresh();
    getch();
    endwin();
}





