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

int get_processes(){
    DIR* process_dir = opendir("/proc");
    if(!process_dir){
        perror("opendir");
        return 1;
    }

    struct dirent* entry;
    while ((entry = readdir(process_dir)) != NULL){
        if (entry->d_type == DT_DIR && atoi(entry->d_name) != 0){
            char cmdline_path[300];
            snprintf(cmdline_path, sizeof(cmdline_path), "/proc/%s/cmdline", entry->d_name);

            FILE *cmdline_file = fopen(cmdline_path, "r");

            if (cmdline_file){
                char cmdline[300];
                if(fgets(cmdline, sizeof(cmdline), cmdline_file)){
                    printf("Process Name : %s\n",cmdline);
                }
                else{
                    perror("fgets");
                }
                fclose(cmdline_file);
            }
        }
    }

    return 0;
};

int get_pid(){
    int PID = getpid();

    return PID;
}

int get_ppid(){
    int PPID = getppid();
    return PPID;
}

