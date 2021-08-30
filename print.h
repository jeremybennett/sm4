/* This is the reference implementation for "Optimized Implementation of SM4 on
   AVR Microcontrollers and ARM Processors" by Hyeokdong Kwon, Hyunjun Kim, Eum
   Si Woo, Minjoo Shim, Wai-Kong Lee, Zhi Hu, Hwajeong Seo,
   https://eprint.iacr.org/2021/667 */

#ifndef SM4PRINT_H
#define SM4PRINT_H

#define DEBUG 0
#define debug_print(...)                                                       \
  do                                                                           \
    {                                                                          \
      if (DEBUG)                                                               \
        fprintf (stderr, __VA_ARGS__);                                         \
    }                                                                          \
  while (0)

#include <stdio.h>

void print_bytes (unsigned *buf, int n);

#endif
