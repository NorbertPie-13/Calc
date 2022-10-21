#include <limits.h>
#include <stdio.h>
#include <stdbool.h>
#include "../includes/operands.h"

static bool check_both_positive(int32_t num_1, int32_t num_2)
{
    return  0 < num_1 && 0 < num_2 ? true : false;
}

static bool check_both_negative(int32_t num_1, int32_t num_2)
{
    return 0 > num_1 && 0 > num_2 ? true : false;
}

static int32_t find_smaller(int32_t num_1, int32_t num_2)
{
    return num_1 < num_2 ? num_1 : num_2;
}

static int32_t find_greater(int32_t num_1, int32_t num_2)
{
    return num_1 > num_2 ? num_1 : num_2;
}



int32_t add(int32_t num_1, int32_t num_2)
{
    int32_t lessor = find_smaller(num_1, num_2);
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
    if ((INT32_MAX < num_1 || INT32_MAX < num_2) || (INT32_MIN > num_1 || INT32_MIN > num_2))
    {   
        fprintf(stderr, "Overflow occured.\n");
        return -1;
    }
}
int32_t divide(int32_t num_1, int32_t num_2)
{
    if ((INT32_MAX < num_1 || INT32_MAX < num_2) || (INT32_MIN > num_1 || INT32_MIN > num_2))
    {   
        fprintf(stderr, "Overflow occured.\n");
        return -1;
    }
}
int32_t modulo(int32_t num_1, int32_t num_2)
{
    if ((INT32_MAX < num_1 || INT32_MAX < num_2) || (INT32_MIN > num_1 || INT32_MIN > num_2))
    {   
        fprintf(stderr, "Overflow occured.\n");
        return -1;
    }
}
