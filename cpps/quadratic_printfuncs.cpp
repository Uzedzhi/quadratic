#include <stdio.h>

#include "quadratic_constants.h"
#include "quadratic_printfuncs.h"
#include "quadratic_helpers.h"


void print_introduction() {
    printf(CYAN_COLOR_CODE);
    ascii_printf("solving quadratic\nformula\nax2 + bx + c = 1\0");
    printf(NORMAL_COLOR_CODE);
}

void print_error(char *incorrect_flag) {
    sassert(incorrect_flag != NULL, "NULL_ptr");

    printf(RED_COLOR_CODE "Incorrect flag: %.40s\nAllowed flags are:\n", incorrect_flag);
    print_help();
}

void print_help() {
    printf("-help: prints this information\n"
           "-self-test <filename>: runs unitest on solve_quadratic function with\n"
           "                       tests from <filename> (default: tests.txt)\n"
           "-version: prints version of quadratic solver\n"
           "-continue: continues to run program after executing all flags\n\n" NORMAL_COLOR_CODE);
}

void print_version() {
    printf("current version of quadratic solver is %s\n"
           "brought to you by Dima\n\n", PROGRAM_VERSION);
}

void print_flag_error() {
    printf(RED_COLOR_CODE "Tried to execute incorrect flag" NORMAL_COLOR_CODE);
}
void print_fatal_error() {
    printf(RED_COLOR_CODE "Fatal error: segmentation fault (how tf did you trigger this)" NORMAL_COLOR_CODE);
}


void print_answer(equation *equation) {
    sassert(equation != NULL, "NULL_ptr");

    switch(equation->nRoots) {
        case NO_ROOTS:
            ascii_printf("no answers\0");
            break;
        case ONE_ROOT:
            printf("x = %lg", equation->x1);
            break;
        case TWO_ROOTS:
            printf("x1 = %lg\n"
                   "x2 = %lg\n", equation->x1, equation->x2);
            break;
        case INF_ROOTS:
            ascii_printf("infinity\nanswers\0");
            break;
        default:
            printf("an exception is caught, num_answers=%d", equation->nRoots);
            break;
    }
}

void print_result(struct equation test, enum roots exp_nRoots, double exp_x1, double exp_x2, int* num_of_test) {
    sassert(num_of_test != NULL, "NULL_ptr");

    printf(RED_COLOR_CODE "test %d failed, expected: nRoots=%d, x1=%lg, x2=%lg\n"
                          "               received: nRoots=%d, x1=%lg, x2=%lg\n\n" NORMAL_COLOR_CODE, (*num_of_test),
           exp_nRoots, exp_x1, exp_x2, // expected
           test.nRoots, test.x1, test.x2 // received
          );
}

void print_wrote_successfully(){
    printf(GREEN_COLOR_CODE "Test was wrote successfully to the file" NORMAL_COLOR_CODE);
}

void print_everything_is_right() {
    printf(GREEN_COLOR_CODE);
    ascii_printf("every test was\ndone correctly\n"
                            "congratulations!\n\0");
    printf(NORMAL_COLOR_CODE);
}

void print_writing_failed(){
    printf(RED_COLOR_CODE "There was an error when writing to the file" NORMAL_COLOR_CODE);
}

int write_test_with_switch(enum roots num_answers, equation *equation, FILE * fp) {
    sassert(equation != NULL);
    sassert(fp != NULL);

    switch(num_answers) {
        case NO_ROOTS:
            fprintf(fp, "%lg %lg %lg %d %lg %lg\n", equation->a, equation->b, equation->c, num_answers, NAN, NAN);
            break;
        case ONE_ROOT:
            fprintf(fp, "%lg %lg %lg %d %lg %lg\n", equation->a, equation->b, equation->c, num_answers, equation->x1, NAN);
            break;
        case TWO_ROOTS:
            fprintf(fp, "%lg %lg %lg %d %lg %lg\n", equation->a, equation->b, equation->c, num_answers, equation->x1, equation->x2);
            break;
        case INF_ROOTS: 
            fprintf(fp, "%lg %lg %lg %d %lg %lg\n", equation->a, equation->b, equation->c, num_answers, NAN, NAN);
            break;
        default:
            return 1;
    }
    
    return 0;
}

void ascii_printf(const char * str) {
    sassert(str != NULL);
    
    const char * c = str;
    int count = 0;

    while (*c != '\0') {
        for (int i = 0; i < SYMBOL_HEIGHT; i++){
            while (*c != '\0' && *c != '\n') {
                int num_in_array = 0;
                num_in_array = (*c - ' ') * 2;
                for (int j = ascii_helper[num_in_array]; j < ascii_helper[num_in_array + 1]; j++) {
                    printf("%c", ascii_alphabet[i][j]);
                }
                count++;
                c++;
                printf(" ");
            }
            if (i == 5){
                str += count+1;
            }
            c = str;
            count = 0;
            printf("\n");
        }
    }
}