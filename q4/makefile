CC=g++
FLAGS=-fprofile-arcs -ftest-coverage

run: demo
	./demo
	gcov gcob_q4.cpp
	cat gcob_q4.cpp.gcov

demo: gcob_q4.o
	$(CC) $(FLAGS) gcob_q4.o -o demo

gcob_q4.o: gcob_q4.cpp
	$(CC) $(FLAGS) -c gcob_q4.cpp 


clean:
	rm *.gcov *.gcno *.gcda *.o