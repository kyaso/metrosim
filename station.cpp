#include "station.hpp"

Station::Station(std::string name, int _x, int _y) {
    name_ = name;
    location.x = _x;
    location.y = _y;
}

Coord Station::loc() {
    return location;
}