#include <iostream>
#include <time.h>
#include "station.hpp"
#include "line.hpp"
#include "train.hpp"
#include "event.hpp"

#define NUM_TRAINS 3
#define NUM_STATIONS 6
#define TIME_STEP 1.0f

using namespace std;

EventList* events;
Router* router;

int main() {
    events = new EventList();
    router = new Router(NUM_TRAINS, NUM_STATIONS);

    cout << "<<< Building stations... >>>" << endl;
    Station zero    (0, "0",    0, 3);
    Station one     (1, "1",    4, 3);
    Station two     (2, "2",    8, 3);
    Station three   (3, "3",    4, 0);
    Station four    (4, "4",    8, 6);

    cout << "<<< Drawing lines... >>>" << endl;
    Line blue(0, "Blue");
    blue.add_station(&zero);
    blue.add_station(&one);
    blue.add_station(&two);
    
    Line red(1, "Red");
    red.add_station(&three);
    red.add_station(&one);

    Line green(2, "Green");
    green.add_station(&four);
    green.add_station(&two);

    cout << "<<< Calculating optimal routes... >>>" << endl;
    zero.routing_table.add_destination(0, FORWARD, 1);
    zero.routing_table.add_destination(0, FORWARD, 2);
    zero.routing_table.add_destination(0, FORWARD, 3);
    zero.routing_table.add_destination(0, FORWARD, 4);

    one.routing_table.add_destination(0, FORWARD, 2);
    one.routing_table.add_destination(0, FORWARD, 4);
    one.routing_table.add_destination(0, BACKWARD, 0);
    one.routing_table.add_destination(1, BACKWARD, 3);

    two.routing_table.add_destination(0, BACKWARD, 0);
    two.routing_table.add_destination(0, BACKWARD, 1);
    two.routing_table.add_destination(0, BACKWARD, 3);
    two.routing_table.add_destination(2, BACKWARD, 4);

    three.routing_table.add_destination(1, FORWARD, 0);
    three.routing_table.add_destination(1, FORWARD, 1);
    three.routing_table.add_destination(1, FORWARD, 2);
    three.routing_table.add_destination(1, FORWARD, 4);

    four.routing_table.add_destination(2, FORWARD, 0);
    four.routing_table.add_destination(2, FORWARD, 1);
    four.routing_table.add_destination(2, FORWARD, 2);
    four.routing_table.add_destination(2, FORWARD, 3);



    cout << "<<< Assembling trains... >>>" << endl;
    Train blue_train(0, "0", blue);
    Train red_train(1, "1", red);
    Train green_train(2, "2", green);

    cout << "<<< Waiting for passengers... >>>" << endl;
    router->set_passengers(0, 1, 2);
    router->set_passengers(0, 3, 4);
    router->set_passengers(3, 0, 5);
    router->set_passengers(3, 1, 10);
    router->set_passengers(4, 1, 3);
    router->set_passengers(4, 3, 8);

    cout << "<<< STARTING SIMULATION... >>>" << endl << endl;
    blue_train.init();
    red_train.init();
    green_train.init();

    timespec time;
    time.tv_sec = 1;
    time.tv_nsec = 0;
    float cur_time = 0;
    while(1) {
        nanosleep(&time, NULL);
        cout << "Current time: " << cur_time << endl;
        events->handle(cur_time);
        cur_time += TIME_STEP;
    }

}