#ifndef TEST_FRAMEWORK_H
#define TEST_FRAMEWORK_H

#include <stdio.h>
typedef int (*test_func_t)(int*, int);

typedef struct {
    const char *name;
    test_func_t func;
    int input_size;
    int dimension;
    int* excepted_data;
    int* resulted_data;
    double elapsed_time;
    int err_code;
} test_case_t;

typedef struct {
    const char *message;
    int number_of_test_cases;
    int number_of_passed_tests;
    int number_of_failed_tests;
    double total_elapsed_time;
} report_t;

int check_file_type(const char* filename, const char* suffix);
test_case_t* add_test_case(test_func_t func, const char *filename, int *input_data, int *expected_data, int input_size);
void run_test_case(test_case_t *test_case);
void display_test_case(test_case_t *test_case);
report_t* run_all_tests(test_case_t **test_cases, int num_of_test_cases);

#endif //TEST_FRAMEWORK_H
