#pragma once

#include "util.hpp"
#include <string>

class Station : public Object {
    private:
        Coord location;

    public:
        Station(std::string name, int _x, int _y);
        Coord loc();
};