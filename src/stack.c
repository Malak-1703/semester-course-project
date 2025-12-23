#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

/*
===============================================================================
STACK IMPLEMENTATION
Tracks consecutive failed login attempts for ONE user
===============================================================================
*/


//Initialize the stack with a given capacity

void stack_init(Stack *s, int capacity) {
    s->capacity = capacity;
    s->top = -1;
    s->data = (int *)malloc(sizeof(int) * capacity);

    if (s->data == NULL) {
        fprintf(stderr, "Error: Memory allocation failed for stack\n");
        exit(EXIT_FAILURE);
    }
}

//Push a failure indicator onto the stack
void stack_push(Stack *s, int value) {
    if (s->top >= s->capacity - 1) {
        return;
    }

    s->top++;
    s->data[s->top] = value;
}

//Clear the stack (used after a successful login)
void stack_clear(Stack *s) {
    s->top = -1;
}

//Check if failure threshold is reached
int stack_is_threshold_reached(const Stack *s) {
    return (s->top + 1) >= FAILURE_THRESHOLD;
}

//Free allocated memory
void stack_free(Stack *s) {
    free(s->data);
    s->data = NULL;
    s->capacity = 0;
    s->top = -1;
}
