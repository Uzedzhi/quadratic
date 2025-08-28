#ifndef QUADRATIC_UNITEST_H
#define QUADRATIC_UNITEST_H

void unitest_solve_quadratic(char * file_name);
int do_test(struct equation* equation, enum roots exp_nRoots, double exp_x1, double exp_x2);
int is_one_of_roots(double x, double ans1, double ans2);
int test_next_and_print(char * curr_test, int* num_of_test, int* num_of_incorrect);
int test_solve_quadratic_func(char * curr_test);
void from_file_to_buffer(FILE * fp, char * curr_test);

#endif // QUADRATIC_UNITEST_H