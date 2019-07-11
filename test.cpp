#include <iostream>
#include <time.h>
#include "station.hpp"
#include "line.hpp"
#include "train.hpp"

#define SLEEP 250000000L
#define TIME_STEP 1.0f

using namespace std;

int main() {
    cout << "<<< Building stations... >>>" << endl;
    Station aachen("Aachen", 0, 0);
    Station koeln("Köln", 50, 0);
    Station siegen("Siegen", 150, 0);
    Station we("Welschen-Ennest", 150, 20);
    Station dus("Düsseldorf", 50, 40);
    Station fra("Frankfurt", 180, -50);

    cout << "<<< Drawing lines... >>>" << endl;
    Line re9("RE9");
    re9.add_station(&aachen);
    re9.add_station(&koeln);
    re9.add_station(&siegen);
    
    Line rb91("RB91");
    rb91.add_station(&siegen);
    rb91.add_station(&fra);

    Line re16("RE16");
    re16.add_station(&siegen);
    re16.add_station(&we);

    Line rrx("RRX");
    rrx.add_station(&aachen);
    rrx.add_station(&koeln);
    rrx.add_station(&dus);



    cout << "<<< Assembling trains... >>>" << endl << endl;
    Train train_1("RSX", re9, 1);
    Train train_2("91", rb91, 3);
    Train train_3("16", re16, 1);
    Train train_4("RRX", rrx, 1);

    cout << "<<< STARTING SIMULATION... >>>" << endl << endl;
    train_1.init();
    // train_2.init();
    // train_3.init();
    // train_4.init();
    timespec time;
    time.tv_sec = 0;
    time.tv_nsec = SLEEP;
    float cur_time = 0;
    while(1) {
        nanosleep(&time, NULL);
        cout << "Current time: " << ++cur_time << endl;
        train_1.update(TIME_STEP);
        // train_2.update(TIME_STEP);
        // train_3.update(TIME_STEP);
        // train_4.update(TIME_STEP);
        
    }
    return 0;
}