/* This is the reference implementation for "Optimized Implementation of SM4 on
   AVR Microcontrollers and ARM Processors" by Hyeokdong Kwon, Hyunjun Kim, Eum
   Si Woo, Minjoo Shim, Wai-Kong Lee, Zhi Hu, Hwajeong Seo,
   https://eprint.iacr.org/2021/667 */

#include "print.h"
#include <stdio.h>

void
print_bytes (unsigned int *buf, int n)
{
  unsigned char *ptr = (unsigned char *)buf;
  int i, j;

  for (i = 0; i <= n / 4; i++)
    {
      if (i > 0 && i % 8 == 0)
        {
          debug_print ("\n");
        }
      for (j = 1; j <= 4; j++)
        {
          if ((i * 4 + 4 - j) < n)
            {
              debug_print ("%.2X", ptr[(i * 4) + 4 - j]);
            }
        }
      debug_print (" ");
    }
  debug_print ("\n");
}
