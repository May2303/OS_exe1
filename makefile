CC = gcc
CXX = g++
CFLAGS = -Wall -Wextra -std=c99
CXXFLAGS = -Wall -Wextra
LDFLAGS = -lm

.PHONY: all clean

all: dividedByZero outOfStack undefinedMemory poisson libpoisson.so q5 add2PB findPhone demo

dividedByZero: dividedByZero.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

dividedByZero.o: dividedByZero.c
	$(CC) $(CFLAGS) -c -o $@ $<

outOfStack: outOfStack.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

outOfStack.o: outOfStack.c
	$(CC) $(CFLAGS) -c -o $@ $<

undefinedMemory: undefinedMemory.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

undefinedMemory.o: undefinedMemory.c
	$(CC) $(CFLAGS) -c -o $@ $<

poisson: poisson.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

poisson.o: poisson.c 
	$(CC) $(CFLAGS) -c -o $@ $<

libpoisson.so: poisson.h
	$(CC) $(CFLAGS) -shared -o $@ poisson.h $(LDFLAGS)

q5: main5.o maxSubArraySum.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

main5.o: main5.c q5.h
	$(CC) $(CFLAGS) -c -o $@ $<

maxSubArraySum.o: maxSubArraySum.c q5.h
	$(CC) $(CFLAGS) -c -o $@ $<

add2PB: add2PB.c
	$(CC) -o $@ $<

findPhone: findPhone.c
	$(CC) -o $@ $<

demo: gcob_q4.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

gcob_q4.o: gcob_q4.cpp 
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f dividedByZero outOfStack undefinedMemory poisson libpoisson.so q5 add2PB findPhone demo *.o
