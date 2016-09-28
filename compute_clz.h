#include <stdio.h>

uint8_t clz_recursive(uint32_t x, int shift_len);
uint8_t clz_harley(uint32_t x);
uint8_t clz_iteration(uint32_t x);
int clz_binary_search(uint32_t x);
int clz_byte_shift(uint32_t x);
