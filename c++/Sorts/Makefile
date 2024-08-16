CXXFLAGS = -g -Wall --pedantic

main: main.o Base.o
	g++ $(CXXFLAGS) main.o Base.o -o main


main.o: main.cpp
	g++ -c $(CXXFLAGS) main.cpp

Base.o: Base.cpp Base.h
	g++ -c $(CXXFLAGS) Base.cpp

clean: 
	rm *.o main