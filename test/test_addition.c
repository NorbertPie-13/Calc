#include <stdint.h>
#include <stdlib.h>
#include <limits.h>
#include "../includes/operands.h"
#include "test_addition.h"

START_TEST(test_add_overflow)
{
    int32_t num1 = INT32_MAX;
    int32_t num2 = 5;
    ck_assert_int_eq(-1, add(num1, num2));
}END_TEST

START_TEST(test_add_underflow)
{
    int32_t num1 = INT32_MIN;
    int32_t num2 = -5;
    ck_assert_int_eq(-1, add(num1, num2));
}END_TEST

START_TEST(test_add_zeroes)
{
    int32_t num1 = 0;
    int32_t num2 = 0;
    ck_assert_int_eq(0, add(num1, num2));
}END_TEST

START_TEST(test_add)
{
    int32_t num1 = 25;
    int32_t num2 = 367;
    ck_assert_int_eq(25+367, add(num1, num2));
}END_TEST


START_TEST(test_add_doubles)
{
    int32_t num1 = 25.12;
    int32_t num2 = 367.38;
    ck_assert_int_eq(25+367, add(num1, num2));
}END_TEST
Suite * test_addition_suite(void)
{
    Suite * suite = suite_create("Calc_add");
    TCase * tc_core = tcase_create("Core_add");

    tcase_add_test(tc_core, test_add_overflow);
    tcase_add_test(tc_core, test_add_underflow);
    tcase_add_test(tc_core, test_add_zeroes);
    tcase_add_test(tc_core, test_add);
    tcase_add_test(tc_core, test_add_doubles);
    suite_add_tcase(suite, tc_core);
    return suite;
}