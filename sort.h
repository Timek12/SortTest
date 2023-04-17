#ifndef TEST_FRAMEWORK_SORT_H
#define TEST_FRAMEWORK_SORT_H
#include "types_utils.h"

int bubble_sort_asc(int tab[], int size);
int bubble_sort_desc(int tab[], int size);
int bubble_sort(int tab[], int size, enum direction dir);

int selection_sort_asc(int tab[], int size);
int selection_sort_desc(int tab[], int size);
int selection_sort(int tab[], int size, enum direction dir);

int insertion_sort_asc(int tab[], int size);
int insertion_sort_desc(int tab[], int size);
int insertion_sort(int tab[], int size, enum direction dir);

int sort(int tab[], int size, enum direction dir, enum algorithm alg);
#endif //TEST_FRAMEWORK_SORT_H
