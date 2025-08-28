#include <assert.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

#include "quadratic_constants.h"
#include "quadratic_helpers.h"
#include "quadratic_logic.h"
#include "quadratic_flags.h"
#include "quadratic_printfuncs.h"
#include "quadratic_inputfuncs.h"

int main(int argc, char *argv[]) {
    equation equation = {};
    bool active_flags[SF] = {};
    char file_name[CHAR_LIMIT] = "..\\tests\\tests.txt";

    if (argc > 1) { // if flags are present
        int need_to_continue = check_for_flags_and_execute(active_flags, argv, argc, file_name);
        sassert(need_to_continue != FATAL_ERROR_CODE, "error when checking for flags");
        
        if (!need_to_continue)
            return 0;
    }
    do {
        print_introduction();
        get_coefficients(&equation.a, &equation.b, &equation.c);
        equation.nRoots = solve_quadratic(&equation);
        print_answer(&equation);
    
        if (need_to_write_to_file()){
            get_file_name(file_name);
            write_test_to_file(&equation, file_name);
        }
    } while (active_flags[CONTINUE_FLAG]);

    return 0;
}