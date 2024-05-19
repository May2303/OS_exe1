CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -pg
TARGET = q5
OBJS = main5.o maxSubArraySum.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

main5.o: main5.c q5.h
	$(CC) $(CFLAGS) -c main5.c

maxSubArraySum.o: maxSubArraySum.c q5.h
	$(CC) $(CFLAGS) -c maxSubArraySum.c

clean:
	rm -f $(TARGET) $(OBJS) gmon.out

.PHONY: all clean
