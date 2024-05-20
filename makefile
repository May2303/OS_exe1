CC = gcc
CXX = g++
CFLAGS = -Wall -Wextra -std=c99
CXXFLAGS = -Wall -Wextra
LDFLAGS = -lm

.PHONY: all clean

all: q1/dividedByZero q1/outOfStack q1/undefinedMemory q2/poisson q3/libpoisson.so q5/q5 q6/add2PB q6/findPhone q4/demo

q1/dividedByZero: q1/dividedByZero.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

q1/dividedByZero.o: q1/dividedByZero.c
	$(CC) $(CFLAGS) -c -o $@ $<

q1/outOfStack: q1/outOfStack.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

q1/outOfStack.o: q1/outOfStack.c
	$(CC) $(CFLAGS) -c -o $@ $<

q1/undefinedMemory: q1/undefinedMemory.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

q1/undefinedMemory.o: q1/undefinedMemory.c
	$(CC) $(CFLAGS) -c -o $@ $<

q2/poisson: q2/poisson.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

q2/poisson.o: q2/poisson.c 
	$(CC) $(CFLAGS) -c -o $@ $<

q3/libpoisson.so: q3/poisson.h
	$(CC) $(CFLAGS) -shared -o $@ $< $(LDFLAGS)

q5/q5: q5/main5.o q5/maxSubArraySum.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

q5/main5.o: q5/main5.c q5/q5.h
	$(CC) $(CFLAGS) -c -o $@ $<

q5/maxSubArraySum.o: q5/maxSubArraySum.c q5/q5.h
	$(CC) $(CFLAGS) -c -o $@ $<

q6/add2PB: q6/add2PB.c
	$(CC) -o $@ $<

q6/findPhone: q6/findPhone.c
	$(CC) -o $@ $<

q4/demo: q4/gcob_q4.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

q4/gcob_q4.o: q4/gcob_q4.cpp 
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f q1/dividedByZero q1/outOfStack q1/undefinedMemory q2/poisson q3/libpoisson.so q5/q5 q6/add2PB q6/findPhone q4/demo /.o
