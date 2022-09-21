//
// Created by Jakub Andrýsek on 21.09.2022.
//

#include "queue.h"

Tqueue* createQueue(int length) {
    Tqueue* queue = malloc(sizeof(Tqueue));
    if (queue == NULL) {
        printf("E: queue not created\n");
        exit(EXIT_FAILURE);
    }
    queue->length = length;
    queue->data = malloc(length*sizeof(char*));
    if (queue->data == NULL) {
        printf("E: queue not created\n");
        exit(EXIT_FAILURE);
    }

    return queue;
}

void deleteQueue(Tqueue* queue) {
    for(int r = 0; r < queue->length; r++) {
        free(queue->data[r]);
    }
    free(queue->data);
    free(queue);
}

void printQueue(Tqueue* queue) {
    for(int r = 0; r < queue->length; r++) {
        printf("%s\n", queue->data[r]);
    }
}

void loadQueue(Tqueue* queue, FILE* in) {
    int size = 0;
    int index = 0;
    int line = 0;
    int lineSmall = 0;

    char c;
    while ((c = fgetc(in)) != EOF) {
        if(c == '\n') {
            line++;
            lineSmall = line % queue->length;
            if(queue->data[index] != NULL) {
                free(queue->data[index]);
            }
        }
        if(index >= size) {
            size += BLOCK_INCREMENT;
            char* rebuf = realloc(queue->data[lineSmall], sizeof(char) * size);
            if(rebuf == NULL) {
                free(queue->data[lineSmall]);
                printf("E: nelze zvetsit pole\n");
            }
            printf("Zvetsen radek %d na %d\n", line, size);
        }
        queue->data[lineSmall][index] = c;
        index++;;
    }

}

