#ifndef QUEUE_H
#define QUEUE_H

#include "login_record.h"

/*
===============================================================================
QUEUE — LOGIN REQUEST SIMULATION (FIFO)
===============================================================================

Simulates real-time arrival of login attempts.

===============================================================================
*/

typedef struct {
    LoginRecord *data;
    int front;
    int rear;
    int size;
    int capacity;
} Queue;

void queue_init(Queue *q, int capacity);
void enqueue(Queue *q, LoginRecord record);
LoginRecord dequeue(Queue *q);
int queue_is_empty(const Queue *q);
void queue_free(Queue *q);

#endif
