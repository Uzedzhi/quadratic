#ifndef QUADRATIC_INPUT_FUNCS_H
#define QUADRATIC_INPUT_FUNCS_H

void get_coefficients(double* a, double* b, double* c); 
int write_test_to_file(struct equation *equation, char file_name[]);
char* get_file_name(char file_name[]);
int need_to_write_to_file();

#endif // QUADRATIC_INPUT_FUNC_H