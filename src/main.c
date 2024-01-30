//
// Created by kubun on 29/01/24.
//

#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "backend/Data_getter.c"



int main(){
    int pid = get_pid();
    printf("Process ID = %d\n", pid);
    get_processes();
//    char ch;
//    initscr();
//
//    while(ch == getch() != '\n'){
//        printw("You've pressed %c\n",ch);
//        refresh();
//    }
//    endwin();
    return 0;
}