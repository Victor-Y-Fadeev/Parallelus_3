#include "../include/Test_SpecialPoins.h"
#include "../include/Minunit.h"
#include "../include/SpecialPoints.h"

#include <stdio.h>

int tests_run = 0;
int correct_tests = 0;
int count_t = 0;

void TEST(const char * suit_name)
{

}

static char * test_solve_linear_eqation()
{
    printf(MAGENTA("[ %s ] - started \n"), __func__);
    Vector * vector = create_vector(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
    SpecialPoint * sPoint = create_SpecialPoint(vector);
    mu_assert("error in test_LINEAR 1\n", 2 == solve_linear_eqation(2.0, 6.0, sPoint));
    mu_assert("error in test_LINEAR 2\n", 1 == solve_linear_eqation(2.0, 0.0, sPoint));
    mu_assert("error in test_LINEAR 3\n", 1 == solve_linear_eqation(-2.0, 0.0, sPoint));
    mu_assert("error in test_LINEAR 4\n", 2 == solve_linear_eqation(2.0, 6.0, sPoint));
    printf(MAGENTA("[ %s ] - ended\n\n"), __func__);
    return 0;
}

static char * test_solve_square_eqation()
{
    printf(MAGENTA("[ %s ] - started \n"), __func__);
    Vector * vector = create_vector(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
    SpecialPoint * sPoint = create_SpecialPoint(vector);
    mu_assert("error in test_SQUARE 1\n", 1 == solve_square_eqation(1.0, 0.0, 0.0001, sPoint));
    mu_assert("error in test_SQUARE 2\n", 3 == solve_square_eqation(1.0, 0.0, -0.0001, sPoint));
    mu_assert("error in test_SQUARE 3\n", 1 == solve_square_eqation(1.0, 0.0, 0.000000, sPoint));
    mu_assert("error in test_SQUARE 4\n", 1 == solve_square_eqation(1.0, 0.0, 0.000, sPoint));
    mu_assert("error in test_SQUARE 5\n", 1 == solve_square_eqation(1.0, 0.0, 0.0, sPoint));
    mu_assert("error in test_SQUARE 6\n", 1 == solve_square_eqation(1.0, 0.0, 999999.0, sPoint));
    mu_assert("error in test_SQUARE 7\n", 3 == solve_square_eqation(1.0, 0.0, -999999.0, sPoint));
    //Vector * vector2 = create_vector(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
    //SpecialPoint * sPoint2 = create_SpecialPoint(vector);
    mu_assert("error in test_SQUARE 8\n", 2 == solve_square_eqation(1.0, 2.0, 1, sPoint));
    //printf("%lf %lf %lf %lf %lf %lf %lf %lf", get_y0(sPoint2), get_x0(sPoint2), get_y1(sPoint2), get_x1(sPoint2), get_y2(sPoint2), get_x2(sPoint2), get_y3(sPoint2), get_x3(sPoint));
    mu_assert("error in test_SQUARE 9\n", 2 == solve_square_eqation(1.0, -2.0, 1, sPoint));
    mu_assert("error in test_SQUARE 10\n", 2 == solve_square_eqation(-1.0, -2.0, -1, sPoint));
    mu_assert("error in test_SQUARE 11\n", 2 == solve_square_eqation(-1.0, 2.0, -1, sPoint));
    mu_assert("error in test_SQUARE 12\n", 2 == solve_square_eqation(1.0, 188.0, 9081, sPoint));
    mu_assert("error in test_SQUARE 13\n", 1 == solve_square_eqation(1.0, 188.0, 9082, sPoint));
    printf(MAGENTA("[ %s ] - ended\n\n"), __func__);
    return 0;
}

static char * test_solve_cubic_eqation()
{
    printf(MAGENTA("[ %s ]- started\n"), __func__);
    Vector * vector = create_vector(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
    SpecialPoint * sPoint = create_SpecialPoint(vector);
    mu_assert("[ERROR]: in solve_CUBIC 1\n", 2 == solve_cubic_eqation(8.0, 7.0, -4.0, 1.0, sPoint));
    mu_assert("[ERROR]: in solve_CUBIC 2\n", 2 == solve_cubic_eqation(1.0, 2.0, 1.0, 0.0, sPoint));
    mu_assert("[ERROR]: in solve_CUBIC 3\n", 2 == solve_cubic_eqation(8.0, 7.0, -4.0, 1.0, sPoint));
    mu_assert("[ERROR]: in solve_CUBIC 4\n", 2 == solve_cubic_eqation(8.0, 7.0, -4.0, 1.0, sPoint));
    mu_assert("[ERROR]: in solve_CUBIC 5\n", 2 == solve_cubic_eqation(8.0, 7.0, -4.0, 1.0, sPoint));
    mu_assert("[ERROR]: in solve_CUBIC 6\n", 2 == solve_cubic_eqation(8.0, 7.0, -4.0, 1.0, sPoint));
    printf(MAGENTA("[ %s ] - ended\n\n"), __func__);
    return 0;
}

static char * all_tests()
{
    mu_run_test(test_solve_linear_eqation);
    mu_run_test(test_solve_square_eqation);
    mu_run_test(test_solve_cubic_eqation);
    return 0;
}

void Test_SpecialPoints( void )
{
    char *result = all_tests();
    if (result != 0) {
        printf("%s\n", result);
    }
    else {
        if(correct_tests == count_t)
            printf(GREEN("ALL TESTS PASSED\n"));
    }
    printf("Tests run: %d\n", tests_run);
}