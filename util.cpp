#include "util.hpp"

Object::Object(std::string name) {
    name_ = name;
}

std::string Object::name() const {
    return name_;
}

float dist(Coord *a, Coord *b) {
    return sqrt(pow(b->x - a->x, 2) + pow(b->y - a->y, 2));
}