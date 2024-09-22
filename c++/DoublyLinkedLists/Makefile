CXXFLAGS = -g -Wall --pedantic

all: main test

main: main.o
	g++ $(CXXFLAGS) main.o -o main

test: test.o DoublyLinkedList.o
	g++ $(CXXFLAGS) test.o DoublyLinkedList.o -o test

main.o: main.cpp DoublyLinkedListTemplate.hpp
	g++ -c $(CXXFLAGS) main.cpp

test.o: test.cpp
	g++ -c $(CXXFLAGS) test.cpp

DoublyLinkedList.o: DoublyLinkedList.cpp DoublyLinkedList.h
	g++ -c $(CXXFLAGS) DoublyLinkedList.cpp

clean: 
	rm *.o main test

valgrind: main
	valgrind --leak-check=full ./main