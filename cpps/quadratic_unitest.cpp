#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "quadratic_constants.h"
#include "quadratic_helpers.h"
#include "quadratic_logic.h"
#include "quadratic_unitest.h"
#include "quadratic_printfuncs.h"

int is_one_of_roots(double x, double ans1, double ans2) {
    return is_same(x, ans1) || is_same(x, ans2);
}

// returns 1 if passed else 0
int do_test(struct equation *test, enum roots exp_nRoots, double exp_x1, double exp_x2) {
    sassert(test != NULL);

    test->nRoots = solve_quadratic(test);
    if  (test->nRoots == exp_nRoots                       &&
        is_one_of_roots(test->x1, exp_x1, exp_x2)         &&
        is_one_of_roots(test->x2, exp_x1, exp_x2)) return 1;

    return 0;
}

int test_next_and_print(char curr_test[], int* num_of_test, int* num_of_incorrect) {
    sassert(num_of_test      != NULL, "Error with arguments in function test_next_and_print");
    sassert(num_of_incorrect != NULL, "Error with arguments in function test_next_and_print");
    sassert(curr_test        != NULL, "Error buffer is NULL");

    struct equation test = {0, 0, 0, NAN, NAN, NO_ROOTS};
    enum roots exp_nRoots = NO_ROOTS;
    double exp_x1  = 0;
    double exp_x2  = 0;

    if (curr_test[0] == '\0') return 0;
    if (sscanf(curr_test, "%lg %lg %lg %d %lg %lg", // a b c exp_nRoots exp_x1 exp_x2
           &test.a, &test.b, &test.c, &exp_nRoots, &exp_x1, &exp_x2) != 6) return 0;


    if (curr_test == NULL) return 0;

    int is_passed = do_test(&test, exp_nRoots, exp_x1, exp_x2);
    if (!is_passed) { // not passed
        print_result(test, exp_nRoots, exp_x1, exp_x2, num_of_test);
        (*num_of_incorrect)++;
    }

    (*num_of_test)++;
    return 1;
}

void from_file_to_buffer(FILE * fp, char * curr_test) {
    sassert(fp        != NULL);
    sassert(curr_test != NULL);

    int i   = 0;
    char ch = 0;

    while ((ch = (char) getc(fp)) != EOF) {
        curr_test[i++] = ch;
    }

}


int test_solve_quadratic_func(char curr_test[]) {
    sassert(curr_test != NULL, "NULL_ptr");

    int num_of_test      = 1;
    int num_of_incorrect = 0;

    while (test_next_and_print(curr_test, &num_of_test, &num_of_incorrect))
        curr_test = strchr(curr_test, '\n') + 1; // move pointer to next line

    if (num_of_incorrect == 0) {
        print_everything_is_right();
    }
    return 0;
}

void unitest_solve_quadratic(char * file_name) {
    sassert(file_name != NULL, "Error file_name is invalid");

    char tests[BUFFER_SIZE] = {}; // initializing buffer
    sassert(tests != NULL, "Error initializing buffer");
    char *curr_test = tests;
    
    FILE* fp = fopen(file_name, "r"); // open file with tests
    sassert(fp != NULL, "Error when opening file %s", file_name);
    
    clear_line(fp); // remove headers
    
    from_file_to_buffer(fp, curr_test); // write tests to buffer
    fclose(fp);

    test_solve_quadratic_func(curr_test);
}
