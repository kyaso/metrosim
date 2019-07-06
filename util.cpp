#include "util.hpp"

float dist(Coord a, Coord b) {
        return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}