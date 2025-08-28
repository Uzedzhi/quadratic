#ifndef QUADRATIC_LOGIC_H
#define QUADRATIC_LOGIC_H

#include <assert.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>

#include "quadratic_constants.h"
#include "quadratic_helpers.h"

enum roots solve_linear(equation *equation);
enum roots solve_only_quadratic(equation *equation);
enum roots solve_quadratic(equation *equation);

#endif // QUADRATIC_LOGIC_H