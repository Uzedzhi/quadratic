#ifndef QUADRATIC_UNITEST_H
#define QUADRATIC_UNITEST_H

int get_do_you_need_test();
void unitest_solve_quadratic(const char * const file_name);
int do_test(struct equation* equation, int exp_nRoots, double exp_x1, double exp_x2);
int is_one_of_roots(double x, double ans1, double ans2);
void print_result(equation, int, double, double, int*);
int test_next_and_print(FILE* fp, int* num_of_tests, int* num_of_incorrect);
void print_everything_is_right();
FILE* try_to_open_file(const char * const file_name);

#endif // QUADRATIC_UNITEST_H