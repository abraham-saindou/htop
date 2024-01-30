//
// Created by kubun on 29/01/24.
//
#include "stdlib.h"
#include "time.h"
#include "stdio.h"
#include "unistd.h"


void leak(){

    const int ARR_SIZE = 997;
    int *array = malloc(sizeof(int) * ARR_SIZE);

    for (int i = 0; i < ARR_SIZE; ++i){
        array[i] = i;
    }
    srand(time(NULL));
    int randnum = rand() % ARR_SIZE;

    printf("array[%d] : %d\n", randnum, array[randnum]);
}

