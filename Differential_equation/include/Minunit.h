#pragma once

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_RESET "\x1b[0m"
#define RED(text) ANSI_COLOR_RED text ANSI_COLOR_RESET
#define GREEN(text) ANSI_COLOR_GREEN text ANSI_COLOR_RESET
#define MAGENTA(text) ANSI_COLOR_MAGENTA text ANSI_COLOR_RESET

#define mu_assert(message, test) do { count_t++; if (!(test)) {printf(RED(message));} else correct_tests++; } while (0)
#define mu_run_test(test) do { char *message = test(); tests_run++; \
                                if (message) return message; } while (0)
extern int tests_run;
extern int correct_tests;
extern int count_t;