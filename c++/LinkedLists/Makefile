CXXFLAGS = -g -Wall --pedantic

main: main.o LinkedList.o
	g++ $(CXXFLAGS) main.o LinkedList.o -o main

main.o: main.cpp
	g++ -c $(CXXFLAGS) main.cpp

LinkedList.o: LinkedList.cpp LinkedList.h
	g++ -c $(CXXFLAGS) LinkedList.cpp

clean: 
	rm *.o main