//
// Created by kubun on 29/01/24.
//

#ifndef HTOP_DATA_GETTER_H
#define HTOP_DATA_GETTER_H
#define MAX_PROC_NAME_LEN 300

typedef struct {
    char name[MAX_PROC_NAME_LEN];
    int pid;
}ProcessInfo;


static void get_processes(ProcessInfo **procList, int *numProc);


#endif //HTOP_DATA_GETTER_H
