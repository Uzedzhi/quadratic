#include <assert.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>

#include "quadratic_constants.h"
#include "quadratic_helpers.h"

void print_introduction() {
    printf("solving quadratic formula ax2 + bx + c = 0\n");
    printf("type your coefficients a, b and c:\n");
}

int is_same(double a, double b) {
    return abs(abs(a)-abs(b)) < FLT_ERR || (isnan(a) && isnan(b));
}

void print_answer(enum roots num_answers, equation *equation) {
    assert(equation != NULL);

    switch(num_answers) {
        case NO_ROOTS:
            printf("no answers");
            break;
        case ONE_ROOT:
            printf("x = %.3lf", equation->x1);
            break;
        case TWO_ROOTS:
            printf("x1 = %.3lf\n"
                   "x2 = %.3lf", equation->x1, equation->x2);
            break;
        case INF_ROOTS:
            printf("infinity answers");
            break;
        default:
            printf("an exception is caught, num_answers=%d", num_answers);
            break;
    }
}

void get_coefficients(double* a, double* b, double* c) { // gets VALID coefficients a, b and c
    assert(a != b && b != c && a != c);
    assert(a != NULL);
    assert(b != NULL);
    assert(c != NULL);

    while (scanf("%lf %lf %lf", a, b, c) != 3 || !SS_coefficients_okay(*a, *b, *c)  || !is_end_of_input_clear()) { 
        clear_line(stdin);
        printf("bad coefficients, try again\n");
    }
}

int SS_coefficients_okay(double a, double b, double c) {
    return isfinite(a) && isfinite(b) && isfinite(c);
}

int is_end_of_input_clear() {
    int c = 0;
    while ((c = getchar()) != '\n') {
        if (!isspace(c)) return 0;
    }
    return 1;
}

void clear_line(FILE* fp) {
    assert(fp != NULL);

    int c = 0;
    while ((c = getc(fp)) != '\n' && c != EOF)
        ;
}

void print_file_open_error(){
    printf(RED_COLOR_CODE "Error when opening file please type existing file name\nafter flag -self-test" NORMAL_COLOR_CODE);
}