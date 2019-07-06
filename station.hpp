#pragma once

#include "util.hpp"
#include <string>

class Station {
    private:
        std::string name_;
        Coord location;

    public:
        Station(std::string name, int _x, int _y);
        Coord loc();
        std::string name() { return name_; };
};