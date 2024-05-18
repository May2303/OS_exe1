CC = gcc
CFLAGS = -Wall -g

all: dividedByZero outOfStack undefinedMemory

dividedByZero: dividedByZero.o
	$(CC) $(CFLAGS) dividedByZero.o -o dividedByZero $(LDFLAGS)

dividedByZero.o: dividedByZero.c
	$(CC) $(CFLAGS) -c dividedByZero.c

outOfStack: outOfStack.o
	$(CC) $(CFLAGS) outOfStack.o -o outOfStack $(LDFLAGS)

outOfStack.o: outOfStack.c
	$(CC) $(CFLAGS) -c outOfStack.c

undefinedMemory: undefinedMemory.o
	$(CC) $(CFLAGS) undefinedMemory.o -o undefinedMemory $(LDFLAGS)

undefinedMemory.o: undefinedMemory.c
	$(CC) $(CFLAGS) -c undefinedMemory.c


clean:
	rm -f *.o dividedByZero outOfStack undefinedMemory