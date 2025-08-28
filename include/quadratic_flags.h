#ifndef QUADRATIC_FAGS_H
#define QUADRATIC_FAGS_H

int check_for_flags_and_execute(bool active_flags[], char *argv[], int argc, char* fp);
int execute_flags(bool active_flags[], char * file_name);
type_of_flags check_if_flag_correct(char *current_flag);
int execute_flag(char * file_name, int *need_to_continue, enum type_of_flags flag_number);

#endif // QUADRATIC_FAGS_H