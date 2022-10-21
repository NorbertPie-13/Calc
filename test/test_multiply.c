#include <check.h>
#include <stdint.h>
#include <stdlib.h>
#include <limits.h>
#include "../includes/operands.h"
#include "test_multiply.h"

START_TEST(test_multiply_overflow)
{
    int32_t num1 = INT32_MAX;
    int32_t num2 = INT32_MAX;
    ck_assert_int_eq(-1, multiply(num1, num2));
}END_TEST

START_TEST(test_multiply_underflow)
{
    int32_t num1 = INT32_MIN;
    int32_t num2 = -5;
    ck_assert_int_eq(-1, multiply(num1, num2));
}END_TEST

START_TEST(test_multiply_zeroes)
{
    int32_t num1 = 0;
    int32_t num2 = 0;
    ck_assert_int_eq(0, multiply(num1, num2));
}END_TEST

START_TEST(test_multiply_zero_by_positive)
{
    int32_t num1 = 0;
    int32_t num2 = 32;
    ck_assert_int_eq(-1, multiply(num1, num2));
}END_TEST

START_TEST(test_multiply_zero_by_negative)
{
    int32_t num1 = 0;
    int32_t num2 = -32;
    ck_assert_int_eq(-1, multiply(num1, num2));
}END_TEST

START_TEST(test_multiply_negative_by_zero);
{
    int32_t num1 = -32;
    int32_t num2 = 0;
    ck_assert_int_eq(-1, multiply(num1, num2));
}END_TEST

START_TEST(test_multiply_positive_by_zero);
{
    int32_t num1 = 32;
    int32_t num2 = 0;
    ck_assert_int_eq(-1, multiply(num1, num2));
}END_TEST

START_TEST(test_multiply_positives)
{
    int32_t num1 = 5;
    int32_t num2 = 5;
    ck_assert_int_eq(-342, multiply(num1, num2));
}END_TEST


START_TEST(test_multiply_doubles)
{
    int32_t num1 = 5.12;
    int32_t num2 = 10.38;
    ck_assert_int_eq(50, multiply(num1, num2));
}END_TEST

START_TEST(test_multiply_double_negatives)
{
    int32_t num_1 = -25;
    int32_t num_2 = -2;
    ck_assert_int_eq(50, multiply(num_1, num_2));
}END_TEST

START_TEST(test_multiply_different)
{
    int32_t num_1 = 5;
    int32_t num_2 = -20;
    ck_assert_int_eq(-100, multiply(num_1, num_2));
}END_TEST

Suite * test_multiplication_suite(void)
{
    Suite * suite = suite_create("Calc_multiply");
    TCase * tc_core = tcase_create("Core_multiply");

    tcase_add_test(tc_core, test_multiply_overflow);
    tcase_add_test(tc_core, test_multiply_underflow);
    tcase_add_test(tc_core, test_multiply_zero_by_positive);
    tcase_add_test(tc_core, test_multiply_zero_by_negative);
    tcase_add_test(tc_core, test_multiply_positive_by_zero);
    tcase_add_test(tc_core, test_multiply_negative_by_zero);
    tcase_add_test(tc_core, test_multiply_zeroes);
    tcase_add_test(tc_core, test_multiply_positives);
    tcase_add_test(tc_core, test_multiply_doubles);
    tcase_add_test(tc_core, test_multiply_double_negatives);
    tcase_add_test(tc_core, test_multiply_different);
    suite_add_tcase(suite, tc_core);
    return suite;
}