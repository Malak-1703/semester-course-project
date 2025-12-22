#ifndef LOGIN_RECORD_H
#define LOGIN_RECORD_H

/*
===============================================================================
LOGIN RECORD — CENTRAL DATA STRUCTURE
===============================================================================

Represents ONE login attempt read from the dataset.

This structure is shared by ALL modules:
arrays, linked lists, queues, stacks, trees, and graphs.

Rules:
- No pointers
- No logic
- Only raw login data

===============================================================================
*/

typedef struct {
    char timestamp[20];   // YYYY-MM-DD HH:MM
    char username[32];    // account name
    char ip[16];          // IPv4 address
    int success;          // 1 = success, 0 = failure
} LoginRecord;

#endif
