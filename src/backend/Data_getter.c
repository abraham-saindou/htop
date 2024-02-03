//
// Created by kubun on 29/01/24.
//

/*#include "sys/resource.h"
#include "sys/time.h"*/
#include <dirent.h>
#include "unistd.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#include "Data_getter.h"

void get_processes(ProcessInfo **procList, int *numProc){
    DIR* process_dir = opendir("/proc");
    if(!process_dir){
        perror("opendir");
    }
    struct dirent* entry;
    *numProc = 0;
    *procList = NULL;

    while ((entry = readdir(process_dir)) != NULL){
        if (entry->d_type == DT_DIR && atoi(entry->d_name) != 0){
            int pid = atoi(entry->d_name);
            char cmdline_path[300];

            snprintf(cmdline_path, sizeof(cmdline_path), "/proc/%d/cmdline", pid);

            FILE *cmdline_file = fopen(cmdline_path, "r");
            if (cmdline_file == NULL){
                perror("Error opening cmdline file");
                exit(EXIT_FAILURE);
            }

            char procName[MAX_PROC_NAME_LEN];
            fgets(procName, sizeof(procName), cmdline_file);
            procName[strcspn(procName, "\n")] = '\0';

            fclose(cmdline_file);

            *procList = realloc(*procList, (*numProc + 1) * sizeof(ProcessInfo));
            strcpy((*procList)[*numProc].name, procName);
            (*procList)[*numProc].pid = pid;
            (*numProc)++;

        }
    }
    closedir(process_dir);
}

