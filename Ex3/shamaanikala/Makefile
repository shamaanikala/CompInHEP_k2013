all:
	@${MAKE} Measurement
	@${MAKE} main

Measurement: Measurement.hpp Measurement.cpp
	g++ -c Measurement.cpp

main: Measurement.o main.cpp
	g++ Measurement.o main.cpp -o main
