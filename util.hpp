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

class Matrix {
    private:
        uint *mat;
        unsigned dim_y;
        unsigned dim_x;
        bool indices_valid(unsigned y, unsigned x);

    public:
        Matrix() {};
        Matrix(unsigned dim_y, unsigned dim_x);
        ~Matrix();
        uint get_val(unsigned y, unsigned x);
        void set_val(unsigned y, unsigned x, uint val);
        void add_val(unsigned y, unsigned x, uint val);
        void reset_val(unsigned y, unsigned x);
        unsigned get_dim_y() { return dim_y; };
        unsigned get_dim_x() { return dim_x; };
};