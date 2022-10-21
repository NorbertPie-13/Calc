#include <check.h>
#include <stdint.h>
#include <stdlib.h>
#include <limits.h>
#include "../includes/operands.h"
#include "test_subtraction.h"

START_TEST(test_subtract_overflow)
{
    int32_t num1 = INT32_MAX;
    int32_t num2 = 5;
    ck_assert_int_eq(-1, subtract(num1, num2));
}END_TEST

START_TEST(test_subtract_underflow)
{
    int32_t num1 = INT32_MIN;
    int32_t num2 = 5;
    ck_assert_int_eq(-1, subtract(num1, num2));
}END_TEST

START_TEST(test_subtract_zeroes)
{
    int32_t num1 = 0;
    int32_t num2 = 0;
    ck_assert_int_eq(0, subtract(num1, num2));
}END_TEST

START_TEST(test_subtract)
{
    int32_t num1 = 25;
    int32_t num2 = 367;
    ck_assert_int_eq(-342, subtract(num1, num2));
}END_TEST


START_TEST(test_subtract_doubles)
{
    int32_t num1 = 25.12;
    int32_t num2 = 367.38;
    ck_assert_int_eq(25-367, subtract(num1, num2));
}END_TEST

START_TEST(test_subtract_double_negatives)
{
    int32_t num_1 = -426;
    int32_t num_2 = -322;
    ck_assert_int_eq(-104, subtract(num_1, num_2));
}END_TEST

START_TEST(test_subtract_larger_negative)
{
    int32_t num_1 = 5;
    int32_t num_2 = -322;
    ck_assert_int_eq(327, subtract(num_1, num_2));
}END_TEST
Suite * test_subtraction_suite(void)
{
    Suite * suite = suite_create("Calc_subtract");
    TCase * tc_core = tcase_create("Core_subtract");

    tcase_add_test(tc_core, test_subtract_overflow);
    tcase_add_test(tc_core, test_subtract_underflow);
    tcase_add_test(tc_core, test_subtract_zeroes);
    tcase_add_test(tc_core, test_subtract);
    tcase_add_test(tc_core, test_subtract_doubles);
    tcase_add_test(tc_core, test_subtract_double_negatives);
    tcase_add_test(tc_core, test_subtract_larger_negative);
    suite_add_tcase(suite, tc_core);
    return suite;
}