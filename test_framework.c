#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "assert.h"
#include "test_framework.h"

#define MAX_TESTS 10

int num_of_test_cases = 0;
test_case_t *test_cases[MAX_TESTS];

int is_file_type(const char* filename, const char* suffix) {
    size_t filename_len = strlen(filename);
    size_t suffix_len = strlen(suffix);

    if (filename_len < suffix_len) {
        return 0;
    }

    const char* end = filename + (filename_len - suffix_len);
    return strcmp(end, suffix) == 0;
}

void add_test_case(test_func_t func, const char *filename, int **input_data, int **expected_data, int input_size)
{
    // check for invalid data
    if(filename == NULL || input_data == NULL || expected_data == NULL || num_of_test_cases > MAX_TESTS)
        return;

    test_case_t *test = malloc(sizeof(test_case_t));
    if(test == NULL)
        return;

    test->name = filename;
    test->func = func;
    test->elapsed_time = 0.0;
    test->excepted_data = expected_data;
    test->resulted_data = input_data;
    test->input_size = input_size;
    test->err_code = 0;
    *(test_cases + num_of_test_cases) = test;
    num_of_test_cases++;

}

void display_test_case(test_case_t *test_case)
{
    if(test_case == NULL)
        return;

    printf("Report for: %s\n", test_case->name);
    printf("Resulted tab:\n");
    for(int i=0; i<test_case->input_size; i++){
        printf("%d ", *(*test_case->resulted_data + i));
    }
}

void run_test_case(test_case_t *test_case)
{
    if(test_case == NULL)
        return;
    // err_code 1 - incorrect test_case data
    // err_code 2 - incorrect sorting algorithm

    // check for incorrect data in the test

    if(my_assert(test_case->name == NULL, "Assertion failed: test case name should not be NULL\n")){
        test_case->err_code = 1;
        return;
    }

    if(my_assert(test_case->func == NULL, "Assertion failed: pointer to sorting function should not be NULL\n")){
        test_case->err_code = 1;
        return;
    }

    if(my_assert(is_file_type(test_case->name, ".c"), "Assertion failed: file for sorting function should have .c extension\n")){
        test_case->err_code = 1;
        return;
    }

    if(my_assert(test_case->excepted_data == NULL, "Assertion failed: pointer to expected data array should not be null\n")){
        test_case->err_code = 1;
        return;
    }

    if(my_assert(test_case->resulted_data == NULL, "Assertion failed: pointer to resulted data array should not be NULL\n")){
        test_case->err_code = 1;
        return;
    }

    if(my_assert(test_case->input_size <= 0, "Assertion failed: input size should be a positive value\n")){
        test_case->err_code = 1;
        return;
    }

    if(my_assert(test_case->err_code != 0, "Assertion failed: error code should be set to 0\n")){
        test_case->err_code = 1;
        return;
    }

    clock_t start_time = clock();
    test_case->func(test_case->resulted_data, test_case->input_size);
    clock_t end_time = clock();

    test_case->elapsed_time = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;

    // testing functions that sorts 2d arrays
    for(int i=0; i<test_case->input_size; i++){
        for(int j=0; j<test_case->input_size; j++){
            if(my_assert(*(test_case->resulted_data + i) == *(test_case->excepted_data + i),
                      "Assertion failed: expected %d, instead got %d at index [%d][%d]\n", *(test_case->resulted_data + i), *(test_case->excepted_data + i), i, j)){
                test_case->err_code = 2;
            }
        }
    }
}

void destroy_test_cases(test_case_t **test_cases_array){
    for(int i=0; i<num_of_test_cases; i++){
        free(*(test_cases_array + i));
    }
}

report_t* run_all_tests(test_case_t **test_cases_array, int number_of_test_cases)
{
    if(test_cases_array == NULL || *test_cases_array == NULL || number_of_test_cases <= 0){
        return NULL;
    }

    report_t *report = malloc(sizeof(report_t));
    if(report == NULL){
        destroy_test_cases(test_cases_array);
        return NULL;
    }

    report->number_of_test_cases = number_of_test_cases;
    report->number_of_passed_tests = 0;
    report->number_of_failed_tests = 0;
    report->total_elapsed_time = 0.0;
    report->message = "Testing sorting function";

    clock_t start_time = clock();
    for(int i=0; i<number_of_test_cases; i++){
        if(*(test_cases_array + i) == NULL){
            report->number_of_failed_tests++;
            continue;
        }

        run_test_case(*(test_cases_array + i));
        if((*test_cases_array + i)->err_code != 0){
            report->number_of_failed_tests++;
        }
        else{
            report->number_of_passed_tests++;
        }
    }

    clock_t end_time = clock();
    report->total_elapsed_time = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;

    destroy_test_cases(test_cases_array);
    return report;
}
