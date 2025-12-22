#ifndef STACK_H
#define STACK_H

#include "login_record.h"
#include "config.h"

/*
===============================================================================
STACK — CONSECUTIVE FAILURE TRACKER
===============================================================================

Tracks consecutive FAILED login attempts for ONE user.

Rules:
- Push on failure
- Clear on success
- Threshold reached → suspicious user

Does NOT store LoginRecord.
Only counts failures.

===============================================================================
*/

typedef struct {
    int *data;
    int top;
    int capacity;
} Stack;

void stack_init(Stack *s, int capacity);
void stack_push(Stack *s, int value);
void stack_clear(Stack *s);
int stack_is_threshold_reached(const Stack *s);
void stack_free(Stack *s);

#endif
