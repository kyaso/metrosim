#include "train.hpp"
#include <cmath>
#include <iostream>

using namespace std;

Train::Train(string name, Line &_line, float _speed) : line(_line) {
    name_ = name;
    //next_station = line.first_station();
    next_station_iter = line.first();
    distance_to_next_station = 0;
    speed = _speed;
}

void Train::update_next_station() {
    prev_station = *next_station_iter;
    next_station_iter++;
    distance_to_next_station = dist(prev_station->loc(), (*next_station_iter)->loc());
}

void Train::init() {
        cout << "Train " << name_ << " starting at " << (*next_station_iter)->name() << "; ";
    update_next_station();
        cout << "next station --> " << (*next_station_iter)->name() << endl;
}

void Train::update(float time_step) {
    if(do_update) {
        distance_to_next_station -= speed*time_step;
        if(fabs(distance_to_next_station) < 0.0001) {
            if(*next_station_iter == line.last_station()) {
                cout << "Train " << name_ << " reached last station " << line.last_station()->name() << " of line " << line.name() << "." << endl;
                do_update = false;
            }
            else {
                cout << "Train " << name_ << " arrived at " << (*next_station_iter)->name() << ". ";
                update_next_station();
                cout << "Next --> " << (*next_station_iter)->name() << endl;
            }
            
            
        }
    }
    
}