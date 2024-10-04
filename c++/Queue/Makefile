CXXFLAGS = -g -Wall --pedantic

main: main.o Queue.o
	g++ $(CXXFLAGS) main.o Queue.o -o main

main.o: main.cpp
	g++ -c $(CXXFLAGS) main.cpp

Queue.o: Queue.cpp Queue.h
	g++ -c $(CXXFLAGS) Queue.cpp

clean: 
	rm *.o main

valgrind: main
	valgrind --leak-check=full ./main