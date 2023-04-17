#include <time.h>
#include "test_framework.h"
#include "test_framework.c"
#include "bubble_sort_2d.c"
#include "my_quicksort.c"
#include "sort.c"
#include "assert.c"

#define SIZE 100000


int main() {
    srand(time(NULL));
    int *input_tab = malloc(sizeof(int) * SIZE);
    int *expected_tab = malloc(sizeof(int) * SIZE);
    for(int i=0; i<SIZE; i++){
        *(input_tab + i) = (rand() % (2001) - 1000);
        *(expected_tab + i) = *(input_tab + i);
    }

    test_case_t *tests[3];
    quicksort_asc(0, SIZE-1, expected_tab, SIZE);
    int (*sort_functions[3])(int*, int) = {bubble_sort_asc, selection_sort_asc, insertion_sort_asc};
    for(int i=0; i<3; i++){
        int input_tab_copy[SIZE];
        memcpy(input_tab_copy, input_tab, SIZE * sizeof(int));
        test_case_t *test = NULL;
        test = add_test_case(*(sort_functions + i), "sort.c", input_tab_copy, expected_tab, SIZE);
        *(tests + i) = test;
    }


    run_all_tests(tests, 3);

    return 0;
}
