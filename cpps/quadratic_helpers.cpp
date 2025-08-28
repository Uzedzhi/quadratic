#include <assert.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

#include "quadratic_constants.h"
#include "quadratic_helpers.h"
#include "quadratic_printfuncs.h"

int is_same(double a, double b) {
    return abs(abs(a)-abs(b)) < FLT_ERR || (isnan(a) && isnan(b));
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
    sassert(fp != NULL);

    int c = 0;
    while ((c = getc(fp)) != '\n' && c != EOF)
        ;
}
