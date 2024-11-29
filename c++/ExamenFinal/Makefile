CXXFLAGS = -g -Wall --pedantic

main: main.o catalogo.o colors.o
	g++ $(CXXFLAGS) main.o catalogo.o colors.o -o main

main.o: main.cpp dlinkedlist.h hashtable.h
	g++ -c $(CXXFLAGS) main.cpp

Catalogo.o: catalogo.cpp catalogo.h
	g++ -c $(CXXFLAGS) catalogo.cpp

Colors.o: colors.cpp colors.h
	g++ -c $(CXXFLAGS) colors.cpp

clean: 
	rm *.o main

valgrind: main
	valgrind --leak-check=full ./main