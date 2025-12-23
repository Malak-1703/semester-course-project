#include "../include/array_list.h"
#include <stdlib.h>
#include <stdio.h>

#define INITIAL_CAPACITY 10

void array_list_init(ArrayList *list) {
    list->size = 0;
    list->capacity = INITIAL_CAPACITY;
    list->data = (LoginRecord *)malloc(list->capacity * sizeof(LoginRecord));
    if (!list->data) exit(EXIT_FAILURE);
}

void array_list_add(ArrayList *list, LoginRecord record) {
    if (list->size >= list->capacity) {
        list->capacity *= 2;
        LoginRecord *temp = (LoginRecord *)realloc(list->data, list->capacity * sizeof(LoginRecord));
        if (!temp) return;
        list->data = temp;
    }
    list->data[list->size++] = record;
}

void array_list_remove_at(ArrayList *list, size_t index) {
    if (index >= list->size) return;
    for (size_t i = index; i < list->size - 1; i++) {
        list->data[i] = list->data[i + 1];
    }
    list->size--;
}

LoginRecord* array_list_get(ArrayList *list, size_t index) {
    if (index >= list->size) return NULL;
    return &list->data[index];
}

void array_list_free(ArrayList *list) {
    free(list->data);
    list->size = 0;
    list->capacity = 0;
}
