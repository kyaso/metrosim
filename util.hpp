#pragma once

#include <cmath>
#include <string>

class Object {
    protected:
        std::string name_;
    public:
        Object(std::string name);
        std::string name() const;
};

struct Coord {
    int x;
    int y;
};

float dist(Coord *a, Coord *b);