#include <stdio.h>
#include <stdlib.h>
#include "../includes/operands.h"

int main(int argc, char ** argv)
{
    int exit_status = EXIT_SUCCESS;
    if (4 != argc)
    {
        fprintf(stderr, "Incorrect amount of arguments, 3 needed.\n");
        exit_status = EXIT_FAILURE;
        goto EXIT;
    }

    EXIT:
        return exit_status;
}