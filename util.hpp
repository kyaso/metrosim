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
        unsigned int id_;
        std::string name_;
    public:
        Object(unsigned int id, std::string name);
        unsigned int id() const;
        std::string name() const;
};

struct Coord {
    int x;
    int y;
};

float dist(Coord *a, Coord *b);