#include <limits.h>
#include <stdio.h>
#include <stdbool.h>
#include "../includes/operands.h"
#include "../includes/common.h"





int32_t add(int32_t num_1, int32_t num_2)
{
    int32_t sum = num_1 + num_2;
    if ((true == check_both_positive(num_1, num_2)) && 0 > sum)
    {
        fprintf(stderr, "Overflow error.\n");
        sum = -1;
    } else if ((true == check_both_negative(num_1, num_2)) && 0 < sum)
    {
        fprintf(stderr, "Underflow error.\n");
        sum = -1;
    }
    return sum;
}

int32_t subtract(int32_t num_1, int32_t num_2)
{
    int32_t lesser = find_smaller(num_1, num_2);
    int32_t greater = find_greater(num_1, num_2);
    int32_t quotient = num_1 - num_2;
    if (true == check_both_positive(num_1, num_2) && quotient > lesser)
    {   
        fprintf(stderr, "Overflow occured.\n");
        return -1;
    } else if (quotient > greater && (num_1 == lesser && 0 < num_2))
    {
        fprintf(stderr, "Underflow occured.\n");
        return -1;
    }
    return  quotient;  
}

int32_t multiply(int32_t num_1, int32_t num_2)
{
    int32_t product = 0;
    if (check_for_zero(num_1, num_2))
    {
        fprintf(stderr, "Multiplcation with 0.\n");
        product = -1;
    }
    if (num_1 > INT32_MAX || num_2 > INT32_MAX)
    {
        fprintf(stderr, "Number too large for int32.\n");
        return -1;
    }
    product = num_1 * num_2;
    if (check_both_negative(num_1, num_2) && 0 > product)
    {
        fprintf(stderr, "Overflow with two negatives.\n");
        product = -1;
    }
    if ((0 < product && (0 > num_1 || 0 > num_2)) && (product / num_2) != num_1)
    {
        fprintf(stderr, "Underflow occured.\n");
        product = -1;
    }
    if (product / num_2 != num_1)
    {
        fprintf(stderr, "Overflow occured.\n");
        return -1;
    }
    
    return product;
}
int32_t divide(int32_t num_1, int32_t num_2)
{   
    int32_t quotient = 0;
    if (check_for_zero(num_1, num_2))
    {
        fprintf(stderr, "Division with 0.\n");
        quotient = -1;
        return quotient;
    }
    quotient = num_1 / num_2;
    return quotient;
}
int32_t modulo(int32_t num_1, int32_t num_2)
{
    if (check_for_zero)
    {
        fprintf(stderr, "Modulo with 0.\n");
        return -1;
    }
    int32_t result = num_1 % num_2;
    return result;
}
