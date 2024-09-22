CXXFLAGS = -g -Wall --pedantic

main: main.o DoublyLinkedList.o
	g++ $(CXXFLAGS) main.o DoublyLinkedList.o -o main

test: test.o DoublyLinkedList.o
	g++ $(CXXFLAGS) test.o DoublyLinkedList.o -o test

test.o: test.cpp
	g++ -c $(CXXFLAGS) test.cpp

DoublyLinkedList.o: DoublyLinkedList.cpp DoublyLinkedList.h
	g++ -c $(CXXFLAGS) DoublyLinkedList.cpp

clean: 
	rm *.o main

valgrind: main
	valgrind --leak-check=full ./main