#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "login_record.h"

/*
===============================================================================
LINKED LIST — POINTER-BASED LOGIN STORAGE
===============================================================================

Alternative to array list.
Optimized for insertions.

===============================================================================
*/

typedef struct Node {
    LoginRecord record;
    struct Node *next;
} Node;

void list_insert(Node **head, LoginRecord record);
void list_delete(Node **head, const char *username);
void list_print(Node *head);
void list_free(Node *head);

#endif
