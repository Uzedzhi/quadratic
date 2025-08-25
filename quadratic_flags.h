#ifndef QUADRATIC_FAGS_H
#define QUADRATIC_FAGS_H

void check_for_flags_and_execute(bool active_flags[], char *argv[], int argc);
void execute_flags(bool *active_flags, const char * const file_name);
void print_help();
void print_error(char *incorrect_flag);
void print_fatal_error();
type_of_flags check_if_flag_correct(char *current_flag);
void print_version();
char* get_file_name();

#endif // QUADRATIC_FAGS_H