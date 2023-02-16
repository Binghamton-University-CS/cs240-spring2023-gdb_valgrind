FLAGS = -g -Wall -std=c++11

all: use_fractions

use_fractions: Fraction.o FractionUser.o
	g++ $(FLAGS) Fraction.o FractionUser.o -o use_fractions

Fraction.o: Fraction.cpp Fraction.h
	g++ $(FLAGS) -c Fraction.cpp -o Fraction.o

FractionUser.o: FractionUser.cpp Fraction.h
	g++ $(FLAGS) -c FractionUser.cpp -o FractionUser.o

clean:
	rm -f *.o use_fractions
