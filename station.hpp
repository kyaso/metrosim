#pragma once

#include "util.hpp"
#include <string>

class Station : public Object {
    private:
        Coord location;

    public:
        Station(unsigned int id, std::string name, int _x, int _y);
        ~Station() {DBG("Station destructor");}
        Coord loc();
        float dist_to(Station *target);
};