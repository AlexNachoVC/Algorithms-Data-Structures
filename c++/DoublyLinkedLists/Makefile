CXXFLAGS = -g -Wall --pedantic

main: main.o DoublyLinkedList.o
	g++ $(CXXFLAGS) main.o DoublyLinkedList.o -o main

main.o: main.cpp
	g++ -c $(CXXFLAGS) main.cpp

DoublyLinkedList.o: DoublyLinkedList.cpp DoublyLinkedList.h
	g++ -c $(CXXFLAGS) DoublyLinkedList.cpp

clean: 
	rm *.o main

valgrind: main
	valgrind --leak-check=full ./main