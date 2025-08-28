#ifndef QUADRATIC_CONSTANTS_H
#define QUADRATIC_CONSTANTS_H

#define RED_COLOR_CODE "\033[91m"
#define GREEN_COLOR_CODE "\033[32m"
#define NORMAL_COLOR_CODE "\033[37m"
#define CYAN_COLOR_CODE "\033[36m"
#define LIGHT_RED_COLOR_CODE "\033[31m"

const char *const PROGRAM_VERSION = "1.0.2";
const int CHAR_LIMIT = 50;
const double FLT_ERR = 1e-3;
const char * const all_flags[] = {"help", "version", "self-test", "continue"};
const int SF = sizeof(all_flags) / sizeof(char*);
const int BUFFER_SIZE = 1000;
const int SYMBOL_HEIGHT = 6;

enum roots {
    NO_ROOTS,
    ONE_ROOT,
    TWO_ROOTS,
    INF_ROOTS
};
struct equation{
    double a, b, c;
    double x1, x2;
    enum roots nRoots;
};
struct flags{
    bool help;
    bool self_test;
};
enum type_of_flags {
    HELP_FLAG, VERSION_FLAG, SELF_TEST_FLAG, CONTINUE_FLAG, INCORRECT_FLAG
};

enum error_codes {
    FATAL_ERROR_CODE = -1
};

#endif // QUADRATIC_CONSTANTS_Hconst
