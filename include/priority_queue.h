#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include "login_record.h"

/*
===============================================================================
PRIORITY QUEUE — HIGH-RISK LOGIN PROCESSING
===============================================================================

Higher priority value → processed first.

===============================================================================
*/

typedef struct {
    LoginRecord record;
    int priority;
} PQNode;

typedef struct {
    PQNode *data;
    int size;
    int capacity;
} PriorityQueue;

void pq_init(PriorityQueue *pq, int capacity);
void pq_insert(PriorityQueue *pq, LoginRecord record, int priority);
LoginRecord pq_extract(PriorityQueue *pq);
int pq_is_empty(const PriorityQueue *pq);
void pq_free(PriorityQueue *pq);

#endif
