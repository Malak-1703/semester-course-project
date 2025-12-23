#include "../include/linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Insertion en tête (O(1)) car "Optimized for insertions"
void list_insert(Node **head, LoginRecord record) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (!new_node) {
        perror("Erreur d'allocation list_insert");
        return;
    }
    
    // Attention: ton .h appelle le champ 'record', pas 'data'
    new_node->record = record;
    new_node->next = *head;
    *head = new_node;
}

void list_delete(Node **head, const char *username) {
    Node *current = *head;
    Node *prev = NULL;

    // Parcours de la liste
    while (current != NULL) {
        if (strcmp(current->record.username, username) == 0) {
            // Trouvé !
            if (prev == NULL) {
                // Cas suppression de la tête
                *head = current->next;
            } else {
                // Cas suppression milieu ou fin
                prev->next = current->next;
            }
            free(current);
            return; // On arrête après la première suppression trouvée
        }
        prev = current;
        current = current->next;
    }
    // Si on arrive ici, l'utilisateur n'a pas été trouvé
}

void list_print(Node *head) {
    printf("=== LINKED LIST CONTENT ===\n");
    Node *current = head;
    while (current != NULL) {
        printf("[%s] User: %s | IP: %s | Success: %d\n",
               current->record.timestamp,
               current->record.username,
               current->record.ip,
               current->record.success);
        current = current->next;
    }
    printf("===========================\n");
}

void list_free(Node *head) {
    Node *current = head;
    while (current != NULL) {
        Node *temp = current;
        current = current->next;
        free(temp);
    }
}
