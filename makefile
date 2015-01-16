PathInt: main.o Harmonic.o Random.o Harmonics.o
	g++ -g -o PathInt main.o Harmonic.o Random.o Harmonics.o
	
main.o: main.cpp Harmonic.h Random.h Harmonics.h
	g++ -g -c main.cpp

Harmonics.o: Harmonics.cpp Harmonics.h Random.h Harmonic.h
	g++ -g -c Harmonics.cpp

Harmonic.o: Harmonic.cpp Harmonic.h Random.h
	g++ -g -c Harmonic.cpp
	
Random.o: Random.cpp Random.h
	g++ -g -c Random.cpp
