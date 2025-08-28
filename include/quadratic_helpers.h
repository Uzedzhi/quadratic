#ifndef QUADRATIC_HELPERS_H
#define QUADRATIC_HELPERS_H

#include <assert.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>

#include "quadratic_constants.h"

#ifndef NDEBUG
#define sassert(condition, ...) {                                                  \
                        if (!(condition)){                                         \
                            printf("ERROR: in file \"%s\"\n"                       \
                                   "          line %d\n", __FILE_NAME__, __LINE__);\
                            printf(" " __VA_ARGS__ );                              \
                            abort();                                               \
                    }}
#else 
#define sassert(condition, ...) ((void)0)
#endif // sassert

int SS_coefficients_okay(double a, double b, double c);
int is_end_of_input_clear();
void clear_line(FILE* fp);
int is_same(double a, double b);

#endif // QUADRATIC_HELPERS_