//
// Created by Jakub Andrýsek on 21.09.2022.
//

#include "queue.h"

Tqueue* createQueue(int capacity) {
    Tqueue* queue = malloc(sizeof(Tqueue));
    if (queue == NULL) {
        printf("E: queue not created\n");
        exit(EXIT_FAILURE);
    }
    queue->capacity = capacity;
    queue->length = 0;
    queue->actual = 0;
    queue->data = malloc(capacity * sizeof(char*));
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
    int actual = (++queue->actual) % queue->length;
    for(int r = 0; r < queue->length; r++) {
        printf("%s\n", queue->data[actual]);
        ++actual;
        actual  %= queue->length;
//        actual = (++actual) % queue->length; // same as above
    }
}

void addItem(Tqueue* queue, char item, int *size, int *capacity) {
    if(*size >= *capacity) {
        *capacity += BLOCK_INCREMENT;
        char* data = realloc(queue->data[queue->actual], *capacity * sizeof(char));
        if(data == NULL) {
            free(queue->data);
            queue->data = NULL;
            printf("Failed to allocate memory\n");
            exit(EXIT_FAILURE);
        }
        queue->data[queue->actual] = data;
    }

    queue->data[queue->actual][*size] = item;
    *size = *size + 1;

    if(queue->length < queue->capacity) {
        queue->length++;
    }
}

void startNewLine(Tqueue* queue) {
    queue->actual = ++queue->actual % queue->capacity;
    if(queue->length < queue->capacity) {
        queue->length++;
    }

    if(queue->data[queue->actual] != NULL) {
        free(queue->data[queue->actual]);
        queue->data[queue->actual] = NULL;
    }
}