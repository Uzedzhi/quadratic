#ifndef QUADRATIC_HELPERS_H
#define QUADRATIC_HELPERS_H

#include <assert.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>

#include "quadratic_constants.h"

void print_introduction();
void print_answer(enum roots num_answers, equation *equation);
void get_coefficients(double* a, double* b, double* c);
int SS_coefficients_okay(double a, double b, double c);
int is_end_of_input_clear();
void clear_line(FILE* fp);
int is_same(double a, double b);
void print_file_open_error();

#endif // QUADRATIC_HELPERS_H