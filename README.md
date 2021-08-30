# Reference implementation for SM4

This is as used in "Optimized Implementation of SM4 on AVR Microcontrollers and ARM Processors" by Hyeokdong Kwon, Hyunjun Kim, Eum Si Woo, Minjoo Shim, Wai-Kong Lee, Zhi Hu, Hwajeong Seo, [eprint.iacr.org/2021/667](https://eprint.iacr.org/2021/667).

The actual code is taken from Appendix B of the [IETF data tracker](https://datatracker.ietf.org/doc/html/draft-ribose-cfrg-sm4-10#page-56).

## Errors and warnings

### Errors

The main program uses an undeclared variable, `debug`, which appears to be intended to force enable/disable `debug_print`.  In order for this program to compile, we have replaced this with `#define DEBUG 1` and `#define DEBUG 0` as appopriate.

### Warnings

Numerous warnings about correct `printf` flags, due to the `SM4_ROUNDS` macro.
