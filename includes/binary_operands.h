#ifndef BINARY_OPERANDS_H
#define BINARY_OPERANDS_H
#include <stdint.h>

uint32_t shift_left(int32_t number, int32_t placement);

uint32_t shift_right(int32_t number, int32_t placement);

uint32_t and(int32_t num_1, int32_t num_2);

uint32_t or(int32_t num_1, int32_t num_2);

uint32_t xor(int32_t num_1, int32_t num_2);

uint32_t rotate_left(int32_t, int32_t);

uint32_t rotate_right(int32_t, int32_t);

#endif