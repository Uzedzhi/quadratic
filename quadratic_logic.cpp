#include <assert.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>

#include "quadratic_constants.h"
#include "quadratic_helpers.h"
#include "quadratic_logic.h"

enum roots solve_linear(equation *equation) { // solve bx+c = 0
    assert(equation != NULL);

    double b = equation->b, c = equation->c;
    if (is_same(b, 0)) {
        if (is_same(c, 0))
            return (enum roots)INF_ROOTS;
        else // a == 0 b == 0 c != 0
            return (enum roots)NO_ROOTS;
    } else { // a == 0 b != 0
        equation->x1 = -(c) / (b);
        return (enum roots)ONE_ROOT;
    }
}

enum roots solve_only_quadratic(equation *equation) { // solve ax^2+bx+c = 0 where a != 0
    assert(equation != NULL);

    double a = equation->a, b = equation->b, c = equation->c;
    double x1 = equation->x1, x2 = equation->x2;
    double D = b * b - 4 * a * c;
    if (D < 0) {
        return (enum roots)NO_ROOTS;
    } else if (is_same(D, 0)) {
        double sqrt_D = sqrt(D);
        x1 = (-b + sqrt_D) / (2 * a);
        equation->x1 = is_same(x1, 0) ? fabs(x1) : x1;
        return (enum roots)ONE_ROOT;
    } else {
        double sqrt_D = sqrt(D);
        x1 = (-b + sqrt_D) / (2 * a);
        x2 = (-b - sqrt_D) / (2 * a);
        equation->x1 = is_same(x1, 0) ? fabs(x1) : x1;
        equation->x2 = is_same(x2, 0) ? fabs(x2) : x2;
        return (enum roots)TWO_ROOTS;
    }
}

enum roots solve_quadratic(equation *equation) { // solve ax^2+bx+c=0 for ALL cases
    assert(equation != NULL);

    if (is_same(equation->a, 0)) {
        return solve_linear(equation);
    } else {
        return solve_only_quadratic(equation);
    }
}