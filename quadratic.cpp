#include <assert.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <signal.h>

#include "quadratic_constants.h"
#include "quadratic_unitest.h"
#include "quadratic_helpers.h"
#include "quadratic_logic.h"
#include "quadratic_flags.h"


int main(int argc, char *argv[]) {
    equation equation = {};
    bool active_flags[SF] = {};

    if (argc > 1) { // if flags are present
        check_for_flags_and_execute(active_flags, argv, argc);
        return 0;
    }
    
    print_introduction();
    get_coefficients(&equation.a, &equation.b, &equation.c);
    enum roots num_answers = solve_quadratic(&equation);
    print_answer(num_answers, &equation);

    return 0;
}