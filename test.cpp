#include <iostream>
#include <time.h>
#include "station.hpp"
#include "line.hpp"
#include "train.hpp"
#include "event.hpp"

using namespace std;

#define TIME_STEP 1.0f

EventList* events;

#define SLEEP 250000000L
#define TIME_STEP 1.0f

using namespace std;

int main() {
    events = new EventList();

    cout << "<<< Building stations... >>>" << endl;
    Station aachen(0, "Aachen", 0, 0);
    Station koeln(1, "Köln", 50, 0);
    Station siegen(2, "Siegen", 150, 0);
    Station we(3, "Welschen-Ennest", 150, 20);
    Station dus(4, "Düsseldorf", 50, 40);
    Station fra(5, "Frankfurt", 180, -50);

    cout << "<<< Drawing lines... >>>" << endl;
    Line re9(0, "RE9");
    re9.add_station(&aachen);
    re9.add_station(&koeln);
    re9.add_station(&siegen);
    
    Line rb91(1, "RB91");
    rb91.add_station(&siegen);
    rb91.add_station(&fra);

    Line re16(2, "RE16");
    re16.add_station(&siegen);
    re16.add_station(&we);

    Line rrx(3, "RRX");
    rrx.add_station(&aachen);
    rrx.add_station(&koeln);
    rrx.add_station(&dus);



    cout << "<<< Assembling trains... >>>" << endl << endl;
    Train train_1(0, "RSX", re9, 1);
    Train train_2(1, "91", rb91, 1);
    Train train_3(2, "16", re16, 1);
    Train train_4(3, "RRX", rrx, 1);

    cout << "<<< STARTING SIMULATION... >>>" << endl << endl;
    train_1.init();
    train_2.init();
    train_3.init();
    train_4.init();
    timespec time;
    time.tv_sec = 0;
    time.tv_nsec = 200000000;
    float cur_time = 0;
    while(1) {
        nanosleep(&time, NULL);
        //cout << "Current time: " << cur_time << endl;
        events->handle(cur_time);
        cur_time += TIME_STEP;;
        
    }

    delete events;

    return 0;
}