//
// Created by kubun on 29/01/24.
//

#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "backend/Data_getter.h"
#include "frontend/gui.h"


int main(){
    ProcessInfo *processList;
    int numProc;

    get_processes(&processList, &numProc);
    for (int i = 0; i < numProc; ++i) {
        printf("Process Name: %s, PID: %d\n", processList[i].name, processList[i].pid);
    }

    display(processList, numProc);

    free(processList);

    return 0;
}