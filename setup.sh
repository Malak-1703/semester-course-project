#!/bin/bash

echo "Initializing Malicious Login Detector project structure..."

# Create folders
mkdir -p src
mkdir -p include

# -------------------------
# Create EMPTY .c files
# -------------------------
touch src/array_list.c
touch src/linked_list.c
touch src/stack.c
touch src/queue.c
touch src/priority_queue.c
touch src/search.c
touch src/sort.c
touch src/tree.c
touch src/graph.c
touch src/main.c

# -------------------------
# Create FILLED .h files
# -------------------------

cat > include/login_record.h << 'EOF'
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
EOF

cat > include/config.h << 'EOF'
#ifndef CONFIG_H
#define CONFIG_H

/*
Global configuration shared across all modules.
Changing values here affects system behavior.
*/

#define MAX_FAILED_ATTEMPTS 5
#define MAX_QUEUE_SIZE 1000
#define MAX_USERS 500

#endif
EOF

cat > include/array_list.h << 'EOF'
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
EOF

cat > include/linked_list.h << 'EOF'
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
EOF

cat > include/stack.h << 'EOF'
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
EOF

cat > include/queue.h << 'EOF'
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
EOF

cat > include/priority_queue.h << 'EOF'
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
EOF

cat > include/search.h << 'EOF'
#ifndef SEARCH_H
#define SEARCH_H

/*
===============================================================================
SEARCHING — BLACKLIST CHECKING
===============================================================================
*/

int linear_search(char arr[][32], int size, const char *target);
int binary_search(char arr[][32], int size, const char *target);

#endif
EOF

cat > include/sort.h << 'EOF'
#ifndef SORT_H
#define SORT_H

/*
===============================================================================
SORTING — RANK USERS BY FAILED ATTEMPTS
===============================================================================
*/

typedef struct {
    char username[32];
    int failed_attempts;
} UserStat;

void bubble_sort(UserStat arr[], int n);
void insertion_sort(UserStat arr[], int n);
void quick_sort(UserStat arr[], int low, int high);
void merge_sort(UserStat arr[], int left, int right);

#endif
EOF

cat > include/tree.h << 'EOF'
#ifndef TREE_H
#define TREE_H

/*
===============================================================================
TREE — CLASSIFICATION ENGINE
===============================================================================
*/

typedef enum {
    NORMAL,
    SUSPICIOUS,
    ATTACK
} Classification;

typedef struct TreeNode {
    Classification type;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode* create_node(Classification type);
Classification classify_user(int failed_attempts);
void tree_traverse(TreeNode *root);
void tree_free(TreeNode *root);

#endif
EOF

cat > include/graph.h << 'EOF'
#ifndef GRAPH_H
#define GRAPH_H

/*
===============================================================================
GRAPH — ATTACK SPREAD MODEL
===============================================================================
*/

typedef struct AdjNode {
    int dest;
    struct AdjNode *next;
} AdjNode;

typedef struct {
    int num_vertices;
    AdjNode **adj_lists;
} Graph;

Graph* graph_create(int vertices);
void graph_add_edge(Graph *graph, int src, int dest);
void bfs(Graph *graph, int start);
void dfs(Graph *graph, int start);
void graph_free(Graph *graph);

#endif
EOF

echo "Project structure created successfully."

