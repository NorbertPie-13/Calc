#ifndef COMMON_H
#define COMMON_H
#include <stdint.h>
#include <stdbool.h>


bool check_both_positive(int32_t num_1, int32_t num_2);

bool check_both_negative(int32_t num_1, int32_t num_2);


int32_t find_smaller(int32_t num_1, int32_t num_2);


int32_t find_greater(int32_t num_1, int32_t num_2);


bool check_for_zero(int32_t num);

bool check_for_negative(int32_t num_1, int32_t num_2);


#endif