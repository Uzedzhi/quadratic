#include <stdio.h>

#include "quadratic_constants.h"
#include "quadratic_helpers.h"
#include "quadratic_logic.h"
#include "quadratic_unitest.h"


int get_do_you_need_test() {
    int need_test = 0;
    printf("do you need to test your function?(type y if yes and n if no): ");

    while ((need_test = getchar()) != 'y' && need_test != 'n') {
        clear_line(stdin);
        printf("incorrect input, please try again\n"
               "do you need to test your function?(type y if yes and n if no): ");
    }

    return need_test;
}

FILE* try_to_open_file(const char * const file_name){
    try{
        return fopen(file_name, "r");
    }
    catch(...){
        print_file_open_error();
        exit(0);
    }
}

int is_one_of_roots(double x, double ans1, double ans2) {
    return is_same(x, ans1) || is_same(x, ans2);
}

void print_result(struct equation test, int exp_nRoots, double exp_x1, double exp_x2, int* num_of_test) {
    printf(RED_COLOR_CODE "test %d failed, expected: nRoots=%d, x1=%lg, x2=%lg\n"
                          "               received: nRoots=%d, x1=%lg, x2=%lg\n\n" NORMAL_COLOR_CODE, (*num_of_test),
           exp_nRoots, exp_x1, exp_x2, // expected
           test.nRoots, test.x1, test.x2 // received
          );
}

void print_everything_is_right() {
    printf(GREEN_COLOR_CODE "every test was done correctly\n"
                            "congratulations!\n\n" NORMAL_COLOR_CODE);
}

// returns 1 if passed else 0
int do_test(struct equation *test, int exp_nRoots, double exp_x1, double exp_x2) {
    assert(test != NULL);

    test->nRoots = solve_quadratic(test);
    
    if  (test->nRoots == exp_nRoots               &&
        is_one_of_roots(test->x1, exp_x1, exp_x2) &&
        is_one_of_roots(test->x2, exp_x1, exp_x2)) return 1;
    return 0;
}

int test_next_and_print(FILE* fp, int* num_of_test, int* num_of_incorrect) {
    assert(fp != NULL);
    assert(num_of_test != NULL);
    assert(num_of_incorrect != NULL);

    struct equation test = {0, 0, 0, NAN, NAN, 0};
    int exp_nRoots = 0;
    double exp_x1 = 0;
    double exp_x2 = 0;

    int c = fscanf(fp, "%lf %lf %lf %d %lf %lf", // a b c exp_nRoots exp_x1 exp_x2
           &test.a, &test.b, &test.c, &exp_nRoots, &exp_x1, &exp_x2);
    if (c != 6) return 0;

    int is_passed = do_test(&test, exp_nRoots, exp_x1, exp_x2);
    if (!is_passed) {
        print_result(test, exp_nRoots, exp_x1, exp_x2, num_of_test);
        (*num_of_incorrect)++;
    }

    (*num_of_test)++;
    return 1;
}

void unitest_solve_quadratic(const char * const file_name) {
    int num_of_test = 1;
    int num_of_incorrect = 0;
    FILE* fp = fopen(file_name, "r"); // open file with tests
    
    if (fp == NULL){
        print_file_open_error();
        exit(0);
    }

    clear_line(fp);
    
    while (test_next_and_print(fp, &num_of_test, &num_of_incorrect))
        ;
    
    if (num_of_incorrect == 0) {
        print_everything_is_right();
    }
}