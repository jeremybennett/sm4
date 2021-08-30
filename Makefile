# Makefile for SM4 compilation

# This is the reference implementation for "Optimized Implementation of SM4 on
# AVR Microcontrollers and ARM Processors" by Hyeokdong Kwon, Hyunjun Kim, Eum
# Si Woo, Minjoo Shim, Wai-Kong Lee, Zhi Hu, Hwajeong Seo,
# https://eprint.iacr.org/2021/667

CC = gcc
CPPFLAGS =
CFLAGS = -O2
LDFLAGS =

OBJS = print.o sm4.o sm4_main.o

CF_STYLE := "{BasedOnStyle: GNU, \
              AllowShortFunctionsOnASingleLine: InlineOnly, \
              ColumnLimit: 80}"

sm4.exe: $(OBJS)
	$(CC) $(CPPFLAGS) $(LDFLAGS) -o $@ $(OBJS)

print.o: print.h
sm4.o: sm4.h

print.o: print.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@
sm4.o: sm4.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@
sm4_main.o: sm4_main.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@


.PHONY: format
format:
	for f in $(wildcard *.c) $(wildcard *.h); \
	do \
		echo $$f; \
		clang-format -i -style=$(CF_STYLE) $$f; \
	done

.PHONY: clean
clean:
	$(RM) *.o sm4.exe
