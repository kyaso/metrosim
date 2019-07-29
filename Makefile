all: station line train util event router routing_table

test: all test.cpp
	g++ -g station.o line.o train.o util.o event.o test.cpp -o test

test2: all test2.cpp
	g++ -g station.o line.o train.o util.o event.o test2.cpp -o test2

test-router: router test_router.cpp
	g++ -g router.o test_router.cpp -o test_router
	./test_router

test_passengers: all test_passengers.cpp
	g++ -g  station.o line.o train.o util.o event.o router.o routing_table.o test_passengers.cpp -o test_passengers

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

router: router.cpp
	g++ -g -c router.cpp

routing_table: routing_table.cpp
	g++ -g -c routing_table.cpp

run-test: test
	./test

run-test2: test2
	./test2

clean:
	rm *.o test test2
