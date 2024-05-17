CC = gcc
CFLAGS = -Wall -Wextra -std=c99
LDFLAGS = -lm

.PHONY: all clean

all: libpoisson.so main

libpoisson.so: poisson.h
	$(CC) $(CFLAGS) -shared -o $@ poisson.h $(LDFLAGS)

main: main.c libpoisson.so
	$(CC) $(CFLAGS) -o $@ main.c -L. -lpoisson $(LDFLAGS)

clean:
	rm -f libpoisson.so main
