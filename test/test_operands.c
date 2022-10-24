#include <check.h>
#include <stdint.h>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include "../includes/operands.h"
#include "test_addition.h"
#include "test_subtraction.h"
#include "test_multiply.h"



int main(void)
{
  int no_failed = 0;
  Suite *addition_suite = test_addition_suite();                   
  SRunner *addition_runner = srunner_create(addition_suite);          
  printf("Addition tests:\n");
  srunner_run_all(addition_runner, CK_NORMAL);  
  no_failed = srunner_ntests_failed(addition_runner); 
  srunner_free(addition_runner);                      
  

  Suite *subtraction_suite = test_subtraction_suite();                   
  SRunner *subtraction_runner = srunner_create(subtraction_suite);          
  printf("\n\nSubtraction tests:\n");
  srunner_run_all(subtraction_runner, CK_NORMAL);  
  no_failed = srunner_ntests_failed(subtraction_runner); 
  srunner_free(subtraction_runner);

  Suite *multiplication_suite = test_multiplication_suite();                   
  SRunner *multiplication_runner = srunner_create(multiplication_suite);          
  printf("\n\nMultiplication tests:\n");
  srunner_run_all(multiplication_runner, CK_NORMAL);
 
  no_failed = srunner_ntests_failed(multiplication_runner); 
  srunner_free(multiplication_runner);                        
  return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}