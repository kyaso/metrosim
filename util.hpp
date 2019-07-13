#pragma once

#include <cmath>
#include <string>
#include <iostream>

#define DEBUG 0
#if DEBUG
#define DBG(str) do { std::cout << str << std::endl; } while(0)
#else
#define DBG(str) do { } while(0)
#endif

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