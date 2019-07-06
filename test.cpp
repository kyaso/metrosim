#include <iostream>
#include <time.h>
#include "station.hpp"
#include "line.hpp"
#include "train.hpp"

int main() {
    cout << "<<< Building stations... >>>" << endl;
    Station aachen("Aachen", 0, 0);
    Station koeln("Köln", 50, 0);
    Station siegen("Siegen", 150, 0);
    Station we("Welschen-Ennest", 150, 20);

    cout << "<<< Drawing lines... >>>" << endl;
    Line re9("RE9/RE16");
    re9.add_station(aachen);
    re9.add_station(koeln);
    re9.add_station(siegen);
    re9.add_station(we);


    cout << "<<< Assembling trains... >>>" << endl << endl;
    Train rsx("RSX", re9, 1);

    cout << "<<< STARTING SIMULATION... >>>" << endl << endl;
    rsx.init();
    timespec time;
    time.tv_sec = 0;
    time.tv_nsec = 1000000000L;
    float cur_time = 0;
    while(1) {
        nanosleep(&time, NULL);
        //cout << "Current time: " << ++cur_time << endl;
        rsx.update(1.0f);
        
    }
    return 0;
}