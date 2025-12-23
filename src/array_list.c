#include "../include/array_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void array_init(ArrayList *list, int capacity) {
    list->size = 0;
    list->capacity = capacity;
    list->data = (LoginRecord *)malloc(capacity * sizeof(LoginRecord));
    if (!list->data) {
        perror("Erreur d'allocation array_init");
        exit(EXIT_FAILURE);
    }
}

void array_insert(ArrayList *list, LoginRecord record) {
    // Redimensionnement automatique si plein
    if (list->size >= list->capacity) {
        list->capacity *= 2;
        LoginRecord *temp = (LoginRecord *)realloc(list->data, list->capacity * sizeof(LoginRecord));
        if (!temp) {
            perror("Erreur de reallocation array_insert");
            return;
        }
        list->data = temp;
    }
    
    list->data[list->size] = record;
    list->size++;
}

void array_delete(ArrayList *list, int index) {
    if (index < 0 || index >= list->size) {
        printf("Index invalide pour suppression\n");
        return;
    }

    // Décalage des éléments vers la gauche
    for (int i = index; i < list->size - 1; i++) {
        list->data[i] = list->data[i + 1];
    }
    list->size--;
}

void array_print(const ArrayList *list) {
    printf("=== ARRAY LIST CONTENT (%d records) ===\n", list->size);
    for (int i = 0; i < list->size; i++) {
        printf("[%s] User: %s | IP: %s | Success: %d\n",
               list->data[i].timestamp,
               list->data[i].username,
               list->data[i].ip,
               list->data[i].success);
    }
    printf("=======================================\n");
}

void array_free(ArrayList *list) {
    if (list->data) {
        free(list->data);
        list->data = NULL;
    }
    list->size = 0;
    list->capacity = 0;
}
