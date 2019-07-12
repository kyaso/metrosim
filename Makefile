all: station line train util event test.cpp
	g++ -g station.o line.o train.o util.o event.o test.cpp -o test

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

run-test: all
	./test

clean:
	rm *.o test
