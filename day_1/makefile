run: all
	./bin/day_1
	
all: day_1

day_1: main.o
	clang++ -std=c++1z bin/main.o -o bin/day_1

main.o: main.cpp
	clang++ -std=c++1z -c main.cpp -o bin/main.o

clean:
	rm bin/*
