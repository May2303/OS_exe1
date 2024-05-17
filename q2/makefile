CC = gcc
CFLAGS = -Wall -Wextra -std=c99
LDFLAGS = -lm

.PHONY: all clean

all: poisson

poisson: poisson.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

poisson.o: poisson.c 
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f poisson *.o
