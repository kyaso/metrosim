#pragma once

#include "util.hpp"
#include "routing_table.hpp"
#include <string>
#include <vector>

class Station : public Object {
    private:
        Coord location;

    public:
        RoutingTable routing_table;

        Station(unsigned int id, std::string name, int _x, int _y);
        ~Station() {DBG("Station destructor");}
        Coord loc();
        float dist_to(Station *target);
};