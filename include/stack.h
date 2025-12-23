#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

#define MAX_STACK_SIZE 100

#define MAX_USERS 1000

typedef struct {
    char timestamp[20];
    char username[32];
    char ip[16];
    int success;  
} LoginRecord;

// Stack node to store login results
typedef struct StackNode {
    int success;              
    char timestamp[20];       
    struct StackNode* next;   
} StackNode;

// Stack structure for each user
typedef struct {
    StackNode* top;           
    int size;                 
    int failed_streak;        
} Stack;

// User tracking structure
typedef struct {
    char username[32];        
    Stack login_stack;        
    bool is_suspicious;       
    int total_failures;       
    int total_attempts;       
} UserTracker;

// Main tracking system
typedef struct {
    UserTracker users[MAX_USERS];  
    int user_count;                
    int suspicious_threshold;       
} SuspiciousTracker;

/**
 * Initialize the suspicious tracker system
 * @param tracker Pointer to tracker structure
 * @param threshold Number of consecutive failures to mark as suspicious
 */
void tracker_init(SuspiciousTracker* tracker, int threshold);

bool stack_push(Stack* stack, LoginRecord* record);

bool stack_pop(Stack* stack);

/**
 * Peek at the top element without removing it
 * @param stack Pointer to user's stack
 * @return Pointer to top node, or NULL if empty
 */
StackNode* stack_peek(Stack* stack);

bool stack_is_empty(Stack* stack);

int stack_size(Stack* stack);

bool tracker_process_login(SuspiciousTracker* tracker, LoginRecord* record);

UserTracker* tracker_find_user(SuspiciousTracker* tracker, const char* username);

bool tracker_is_suspicious(SuspiciousTracker* tracker, const char* username);

/**
 * Get list of all suspicious users
 * @param tracker Pointer to tracker system
 * @param suspicious_users Array to store suspicious usernames
 * @param max_users Maximum size of array
 * @return Number of suspicious users found
 */
int tracker_get_suspicious_users(SuspiciousTracker* tracker, 
                                  char suspicious_users[][32], 
                                  int max_users);

void tracker_print_user_stats(SuspiciousTracker* tracker, const char* username);

void tracker_print_suspicious_report(SuspiciousTracker* tracker);

void tracker_cleanup(SuspiciousTracker* tracker);


void stack_free(Stack* stack);

#endif