#include "util.hpp"

Object::Object(unsigned int id, std::string name) {
    name_ = name;
    id_ = id;
}

unsigned int Object::id() const {
    return id_;
}

std::string Object::name() const {
    return name_;
}

float dist(Coord *a, Coord *b) {
    return sqrt(pow(b->x - a->x, 2) + pow(b->y - a->y, 2));
}