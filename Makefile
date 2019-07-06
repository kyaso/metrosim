all: station line train util test.cpp
	g++ station.o line.o train.o util.o test.cpp -o test

station: station.cpp
	g++ -c station.cpp

line: line.cpp
	g++ -c line.cpp

train: train.cpp
	g++ -c train.cpp

util: util.cpp
	g++ -c util.cpp

clean:
	rm *.o
