#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include "login_record.h"

/*
===============================================================================
ARRAY LIST — ARRAY-BASED LOGIN STORAGE
===============================================================================

Stores LoginRecord elements in contiguous memory.

Responsibilities:
- Insert
- Delete
- Traverse

No detection or classification logic allowed here.

===============================================================================
*/

typedef struct {
    LoginRecord *data;
    int size;
    int capacity;
} ArrayList;

void array_init(ArrayList *list, int capacity);
void array_insert(ArrayList *list, LoginRecord record);
void array_delete(ArrayList *list, int index);
void array_print(const ArrayList *list);
void array_free(ArrayList *list);

#endif
