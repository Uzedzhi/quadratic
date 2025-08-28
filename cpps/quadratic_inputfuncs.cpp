#include <stdio.h>
#include <string.h>

#include "quadratic_helpers.h"
#include "quadratic_printfuncs.h"
#include "quadratic_inputfuncs.h"


void get_coefficients(double* a, double* b, double* c) { // gets VALID coefficients a, b and c
    assert(a != b && b != c && a != c);
    assert(a != NULL);
    assert(b != NULL);
    assert(c != NULL);

    printf("type your coefficients a, b and c: ");
    
    while (scanf("%lg %lg %lg", a, b, c) != 3 || !SS_coefficients_okay(*a, *b, *c)  || !is_end_of_input_clear()) {
        clear_line(stdin);
        printf(LIGHT_RED_COLOR_CODE);
        ascii_printf("bad coefficients,\ntry again\n\0");
        printf(NORMAL_COLOR_CODE);
    }
}

int write_test_to_file(equation *equation, char file_name[]) {
    sassert(file_name != NULL);
    sassert(equation  != NULL);

    FILE * fp = fopen(file_name, "a");
    sassert(fp != NULL);


    int is_successful = !write_test_with_switch(equation->nRoots, equation, fp);
    if (is_successful)
        print_wrote_successfully();
    else
        print_writing_failed();


    fclose(fp);
    return 0;
}


char* get_file_name(char *file_name) {
    sassert(file_name != NULL);

    printf("Type path to the file to write test\n"
           "or type d for default path(default ..\\tests\\tests.txt):\n");
    while (scanf("%49s", file_name) != 1) {
        printf(LIGHT_RED_COLOR_CODE "please try again:\n" NORMAL_COLOR_CODE);
        scanf("%*s");
    }

    if (!strcmp(file_name, "d"))
        sprintf(file_name, "..\\tests\\tests.txt");

    return file_name;
}

int need_to_write_to_file() {
    printf("That was quite a good equation\n"
           "Do you want to write it as a test?(y for yes and n for no): ");

    int user_answer = 0;
    while ((user_answer = getchar()) != 'y' && user_answer != 'n') {
        printf(LIGHT_RED_COLOR_CODE "invalid input. Type y for yes and n for no: " NORMAL_COLOR_CODE);
        clear_line(stdin);
    }
    return user_answer == 'y';
}
