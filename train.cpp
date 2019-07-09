#include "train.hpp"
#include <cmath>
#include <iostream>

using namespace std;

Train::Train(string name, Line &_line, float _speed) : Object(name), line(_line) {
    //next_station = line.first_station();
    next_station_iter = line.first();
    distance_to_next_station = 0;
    speed = _speed;
}

void Train::update_next_station(bool dir) {
    prev_station = *next_station_iter;
    if(dir)
        next_station_iter++;
    else
        next_station_iter--;
    distance_to_next_station = prev_station->dist_to(*next_station_iter);
}

void Train::init() {
        cout << "Train " << name_ << " starting at " << (*next_station_iter)->name() << "; ";
    update_next_station(FORWARD);
        cout << "next station --> " << (*next_station_iter)->name() << endl;
}

void Train::update(float time_step) {
    if(do_update) {
        distance_to_next_station -= speed*time_step;
        if(distance_to_next_station < speed*time_step) { // Distance resolution = speed*time_step
            if(*next_station_iter == line.last_station() || *next_station_iter == line.first_station()) {
                cout << "Train " << name_ << " reached end station " << (*next_station_iter)->name() << " of line " << line.name() << ". ";
                //do_update = false;
                dir = !dir;
                update_next_station(dir);
                cout << "Returning to ";
                if(dir == FORWARD)
                    cout << line.last_station()->name();
                else
                    cout << line.first_station()->name();
                cout << ". Next --> " << (*next_station_iter)->name() << endl;
            }
            else {
                cout << "Train " << name_ << " arrived at " << (*next_station_iter)->name() << ". ";
                update_next_station(dir);
                cout << "Next --> " << (*next_station_iter)->name() << endl;
            }
            
            
        }
    }
    
}