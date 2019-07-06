#include "line.hpp"

Line::Line(string name) : name_(name) {}

void Line::add_station(Station &s) {
    station_list.push_back(&s);
}

Station* Line::first_station() {
    return station_list.front();
}

Station* Line::last_station() {
    return station_list.back();
}

list<Station*>::iterator Line::first() {
    return station_list.begin();
}

int Line::num_stations() {
    return (int)station_list.size();
}