all: station line train util event

test: all test.cpp
	g++ -g station.o line.o train.o util.o event.o test.cpp -o test

test2: all test2.cpp
	g++ -g station.o line.o train.o util.o event.o test2.cpp -o test2

station: station.cpp
	g++ -g -c station.cpp

line: line.cpp
	g++ -g -c line.cpp

train: train.cpp
	g++ -g -c train.cpp

util: util.cpp
	g++ -g -c util.cpp

event: event.cpp
	g++ -g -c event.cpp

run-test: test
	./test

run-test2: test2
	./test2

clean:
	rm *.o test test2
