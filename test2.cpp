#include <iostream>
#include <time.h>
#include "station.hpp"
#include "line.hpp"
#include "train.hpp"
#include "event.hpp"
#include <chrono>

using namespace std;

#define TIME_STEP 1.0f
#define NUM_STEPS 1000000
#define NUM_TRAINS 1000

EventList* events;
Train* trains[NUM_TRAINS];

int main() {
    events = new EventList();

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
    for(int i = 0; i < NUM_TRAINS; i++) {
        trains[i] = new Train("RSX", re9, 1);
    }

    // Start time measure
    auto start = std::chrono::high_resolution_clock::now();

    cout << "<<< STARTING SIMULATION... >>>" << endl << endl;
    for(int i = 0; i < NUM_TRAINS; i++) {
        trains[i]->init();
    }

    timespec time;
    time.tv_sec = 0;
    time.tv_nsec = 200000000;
    float cur_time = 0;
    for(int i = 0; i < NUM_STEPS; i++) {
        //nanosleep(&time, NULL);
        //cout << "Current time: " << cur_time << endl;
        events->handle(cur_time);
        cur_time += TIME_STEP;;
        
    }

    // Stop time measure
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = end - start;
    long long microsecs = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
    cout << "Simulation done. Total time: " << microsecs << endl;
}