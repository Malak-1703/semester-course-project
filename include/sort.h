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
