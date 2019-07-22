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

Matrix::Matrix(unsigned _dim_y, unsigned _dim_x) : dim_y(_dim_y), dim_x(_dim_x) {
    DBG("Matrix constructor");
    mat = new uint[dim_y * dim_x];
}

Matrix::~Matrix() {
    DBG("Matrix destructor");
    delete [] mat;
}

uint Matrix::get_val(unsigned y, unsigned x) {
    if(y >= dim_y || x >= dim_x) {
        std::cerr << "ERROR (get_val): Invalid matrix indices: y = " << y << ", x = " << x << ". Matrix has dim (" << dim_y << ", " << dim_x << ")" << std::endl;
        return 0;
    }
    return mat[y*dim_x + x];
}

void Matrix::set_val(unsigned y, unsigned x, uint val) {
    if(y >= dim_y || x >= dim_x) {
        std::cerr << "ERROR (set_val): Invalid matrix indices: y = " << y << ", x = " << x << ". Matrix has dim (" << dim_y << ", " << dim_x << ")" << std::endl;
        return;
    }
    mat[y*dim_x + x] = val;
}