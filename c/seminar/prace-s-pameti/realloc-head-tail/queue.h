//
// Created by Jakub Andrýsek on 21.09.2022.
//

#ifndef JAKUBANDRYSEK_PR5_CVIKO01_MATICE_JET_QUEUE_H
#define JAKUBANDRYSEK_PR5_CVIKO01_MATICE_JET_QUEUE_H

#include <stdlib.h>
#include <stdio.h>

#define BLOCK_INCREMENT 10;

typedef struct {
    char **data;
    int length;
} Tqueue;

Tqueue* createQueue(int length);
void deleteQueue(Tqueue* queue);

void loadQueue(Tqueue* queue, FILE* in);
void printQueue(Tqueue* queue);




#endif //JAKUBANDRYSEK_PR5_CVIKO01_MATICE_JET_QUEUE_H
