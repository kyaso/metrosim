all: station line train util test.cpp
	g++ -g station.o line.o train.o util.o test.cpp -o test

station: station.cpp
	g++ -g -c station.cpp

line: line.cpp
	g++ -g -c line.cpp

train: train.cpp
	g++ -g -c train.cpp

util: util.cpp
	g++ -g -c util.cpp

run-test: all
	./test

clean:
	rm *.o test
