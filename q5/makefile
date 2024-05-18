CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -pg

all: max_subarray_n max_subarray_n2 max_subarray_n3

max_subarray_n: max_subarray_n.c
	$(CC) $(CFLAGS) -o $@ $< -lm

max_subarray_n2: max_subarray_n2.c
	$(CC) $(CFLAGS) -o $@ $< -lm

max_subarray_n3: max_subarray_n3.c
	$(CC) $(CFLAGS) -o $@ $< -lm

clean:
	rm -f max_subarray_n max_subarray_n2 max_subarray_n3 gmon.out
