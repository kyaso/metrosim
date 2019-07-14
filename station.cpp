#include "station.hpp"

Station::Station(unsigned int id, std::string name, int _x, int _y) : Object(id, name) {
    location.x = _x;
    location.y = _y;
}

Coord Station::loc() {
    return location;
}

float Station::dist_to(Station *target) {
    Coord target_loc = target->loc();
    return dist(&location, &target_loc);
}