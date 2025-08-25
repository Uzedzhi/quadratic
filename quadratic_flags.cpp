#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>

#include "quadratic_constants.h"
#include "quadratic_flags.h"
#include "quadratic_unitest.h"

void print_help() {
    printf("-help: prints this information\n"
           "-self-test <filename>: runs unitest on solve_quadratic function with\n"
           "                       tests from <filename> (default: tests.txt)\n"
           "-version: prints version of quadratic solver\n\n" NORMAL_COLOR_CODE);
}

void print_version() {
    printf("current version of quadratic solver is %s\n"
           "brought to you by Dima\n\n", PROGRAM_VERSION);
}

void print_error(char *incorrect_flag) {
    assert(incorrect_flag != NULL);

    printf(RED_COLOR_CODE "Incorrect flag: %.40s\nAllowed flags are:\n", incorrect_flag);
    print_help();
}

void print_fatal_error() {
    printf(RED_COLOR_CODE "Fatal error: segmentation fault(how tf did you trigger this)");
}

type_of_flags check_if_flag_correct(char *current_flag){
    assert(current_flag != NULL);

    type_of_flags type_of_flag = INCORRECT_FLAG;
    for (int i = 0;i < SF;i++) {
        if (strcmp(current_flag+1, all_flags[i]) == 0) { // checks if input flag is correct
            type_of_flag = (enum type_of_flags) i;
            break;
        }
    }

    return type_of_flag;
}

void check_for_flags_and_execute(bool active_flags[], char *argv[], int argc) {
    const char * file_name = "tests.txt";
    int i = 1;

    while (i < argc) {
        type_of_flags num_of_flag_in_array = check_if_flag_correct(argv[i]);

        if (num_of_flag_in_array == INCORRECT_FLAG) {
            print_error(argv[i]);
            exit(0);
        }
        if (num_of_flag_in_array == SELF_TEST_FLAG) {
            if (i+1 < argc && argv[i+1][0] != '-') 
                file_name = argv[++i];
        }

        active_flags[num_of_flag_in_array] = 1;
        i++;
    }

    execute_flags(active_flags, file_name);
}

void execute_flags(bool active_flags[], const char * const file_name) {
    for (int i = 0; i < SF;i++){
        if (active_flags[i]) {
            switch(i) {
                case 0:
                    print_help();
                    break;
                case 1:
                    print_version();
                    break;
                case 2:
                    unitest_solve_quadratic(file_name);
                    break;
                default:
                    print_fatal_error();
                    break;
            }
        }
    }
}