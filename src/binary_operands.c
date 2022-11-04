#include "../includes/binary_operands.h"
#include "../includes/common.h"
#include <stdint.h>
#include <limits.h>

#define UINT_SZ sizeof(uint32_t) * 8


uint32_t shift_left(int32_t number, int32_t placement)
{
    if (check_for_zero(number, placement))
    {
        fprintf(stderr, "Cannot perform binary left shift with negatives.\n");
        return UINT32_MAX;
    }

    uint32_t result = number << placement
    return result;

}

uint32_t shift_right(int32_t number, int32_t placement)
{
    if (check_for_zero(number, placement))
    {
        fprintf(stderr, "Cannot perform binary left shift with negatives.\n");
        return UINT32_MAX;
    }

    uint32_t result = number >> placement
    return result;

}

uint32_t and(int32_t num_1, int32_t num_2)
{
    if (check_for_zero(num_1, num_2))
    {
        fprintf(stderr, "Cannot perform binary AND with negatives.\n");
        return UINT32_MAX;
    }
    uint32_t result = num_1 & num_2;
    return result;
}

uint32_t or(int32_t num_1, int32_t num_2)
{
    if (check_for_zero(num_1, num_2))
    {
        fprintf(stderr, "Cannot perform binary OR with negatives.\n");
        return UINT32_MAX;
    }
    uint32_t result = num_1 | num_2;
    return result;
}

uint32_t xor(int32_t num_1, int32_t num_2)
{
     if (check_for_zero(num_1, num_2))
    {
        fprintf(stderr, "Cannot perform binary XOR with negatives.\n");
        return UINT32_MAX;
    }
    uint32_t result = num_1 ^  num_2;
    return result;
}

uint32_t rotate_left(int32_t, int32_t)
{
     if (check_for_zero(num_1, num_2))
    {
        fprintf(stderr, "Cannot perform binary ROL with negatives.\n");
        return UINT32_MAX;
    }

    uint32_t result  = (num_1 << num_2) | (num_1 >> (UINT_SZ - num_2));
    return result;
}

uint32_t rotate_right(int32_t, int32_t)
{
     if (check_for_zero(num_1, num_2))
    {
        fprintf(stderr, "Cannot perform binary ROL with negatives.\n");
        return UINT32_MAX;
    }

    uint32_t result  = (num_1 >> num_2) | (num_1 << (UINT_SZ - num_2));
    return result;
}
