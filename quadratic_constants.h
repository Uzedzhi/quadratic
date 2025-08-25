#ifndef QUADRATIC_CONSTANTS_H
#define QUADRATIC_CONSTANTS_H

#define RED_COLOR_CODE "\033[31m"
#define GREEN_COLOR_CODE "\033[32m"
#define NORMAL_COLOR_CODE "\033[37m"
const char *const PROGRAM_VERSION = "1.0.2";
const double FLT_ERR = 1e-6;
const char * const all_flags[] = {"help", "version", "self-test"};
const int SF = sizeof(all_flags) / sizeof(char*);
enum roots {
    NO_ROOTS, 
    ONE_ROOT, 
    TWO_ROOTS, 
    INF_ROOTS
};
struct equation{
    double a, b, c;
    double x1, x2;
    int nRoots;
};
struct flags{
    bool help;
    bool self_test;
};
enum type_of_flags {
    HELP_FLAG, VERSION_FLAG, SELF_TEST_FLAG, INCORRECT_FLAG
};

#endif // QUADRATIC_CONSTANTS_Hconst 