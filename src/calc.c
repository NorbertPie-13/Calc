#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../includes/operands.h"

int32_t evaluate_equation(int32_t (*function)(int32_t, int32_t), int32_t num_1, int32_t num_2)
{
    int32_t result = (*function)(num_1, num_2);
    return result;
}

int main(int argc, char ** argv)
{
    int exit_status = EXIT_SUCCESS;
    if (4 != argc)
    {
        fprintf(stderr, "Incorrect amount of arguments, 3 needed.\n");
        exit_status = EXIT_FAILURE;
        goto EXIT;
    } else if (strlen(argv[2]) > 2)
    {
        fprintf(stderr, "Operator is in incorrect format.\n");
        exit_status = EXIT_FAILURE;
        goto EXIT;
    }
    
    char operand = argv[2][0];
    
    int32_t num_1 = 0;
    int32_t num_2 = 0;
    char * garbage_bin = NULL;
    num_1 = strtol(argv[1], &garbage_bin, 10);
    num_2 = strtol(argv[3], &garbage_bin, 10);

    switch (operand)
    {
    case '+':
        
        printf("%d + %d = %d\n", num_1, num_2, evaluate_equation(add, num_1, num_2));
        break;
    case '-':
        printf("%d - %d = %d\n", num_1, num_2, evaluate_equation(subtract, num_1, num_2));
        break;
    case '/':
        printf("%d / %d = %d\n", num_1, num_2, evaluate_equation(divide, num_1, num_2));
        break;

    case '%':
        if (num_2 == 0 && -1 == evaluate_equation(modulo, num_1, num_2))
        {
            exit_status = EXIT_FAILURE;
        } else
        {
            printf("%d %% %d = %d\n", num_1, num_2, evaluate_equation(modulo, num_1, num_2));
        }
        
        break; 
    default:
        printf("Invalid Operand. %c\n", operand);
        break;
    }

    EXIT:
        return exit_status;
}