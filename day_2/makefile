all: day_2

day_2: main.o
	clang++ -std=c++1z bin/main.o -o bin/day_2

main.o: main.cpp
	clang++ -std=c++1z -c main.cpp -o bin/main.o

clean:
	rm bin/*
