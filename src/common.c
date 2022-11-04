#include "../includes/common.h"
#include <stdbool.h>
#include <stdint.h>

bool check_both_positive(int32_t num_1, int32_t num_2)
{
    return  0 < num_1 && 0 < num_2 ? true : false;
}

bool check_both_negative(int32_t num_1, int32_t num_2)
{
    return 0 > num_1 && 0 > num_2 ? true : false;
}

bool check_for_negative(int32_t num_1, int32_t num_2)
{
    return 0 > num_1 || 0  > num_2 ? true : false;
}

int32_t find_smaller(int32_t num_1, int32_t num_2)
{
    return num_1 < num_2 ? num_1 : num_2;
}

int32_t find_greater(int32_t num_1, int32_t num_2)
{
    return num_1 > num_2 ? num_1 : num_2;
}

bool check_for_zero(int32_t num_1, int32_t num_2)
{
    return (0 == num_2) ? true : false;
}