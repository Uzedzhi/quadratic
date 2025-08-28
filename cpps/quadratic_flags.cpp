#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>

#include "quadratic_constants.h"
#include "quadratic_flags.h"
#include "quadratic_unitest.h"
#include "quadratic_printfuncs.h"
#include "quadratic_helpers.h"

type_of_flags check_if_flag_correct(char *current_flag) {
    sassert(current_flag != NULL);

    type_of_flags type_of_flag = INCORRECT_FLAG;
    for (int i = 0;i < SF;i++) {
        if (strcmp(current_flag+1, all_flags[i]) == 0) { // checks if input flag is correct
            type_of_flag = (enum type_of_flags) i;
            break;
        }
    }

    return type_of_flag;
}

int check_for_flags_and_execute(bool active_flags[], char *argv[], int argc, char * file_name) {
    sassert(argv      != NULL);
    sassert(file_name != NULL);
    int i = 1;

    while (i < argc) {
        type_of_flags num_of_flag_in_array = check_if_flag_correct(argv[i]);

        if (num_of_flag_in_array == INCORRECT_FLAG) {
            print_error(argv[i]);
            return FATAL_ERROR_CODE;
        }
        if (num_of_flag_in_array == SELF_TEST_FLAG) {
            if (i+1 < argc && argv[i+1][0] != '-')
                file_name = argv[++i];
        }

        active_flags[num_of_flag_in_array] = 1;
        i++;
    }
    printf("%s", file_name);
    return execute_flags(active_flags, file_name);
}

int execute_flags(bool active_flags[], char * file_name) {
    sassert(file_name != NULL);
    int need_to_continue = 0;
    for (int i = 0; i < SF;i++){
        if (active_flags[i]) {
            execute_flag(file_name, &need_to_continue, (enum type_of_flags) i);
        }
    }
    return need_to_continue;
}

int execute_flag(char * file_name, int *need_to_continue, enum type_of_flags flag_number) {
    sassert(file_name != NULL);
    sassert(need_to_continue != NULL);

    switch(flag_number) {
        case HELP_FLAG:
            print_help();
            break;
        case VERSION_FLAG:
            print_version();
            break;
        case SELF_TEST_FLAG:
            unitest_solve_quadratic(file_name);
            break;
        case CONTINUE_FLAG:
            *need_to_continue = 1;
            break;
        case INCORRECT_FLAG:
            print_flag_error();
            return 1;
            break;
        default:
            return 2;
            break;
    }

    return 0;
}
