#pragma once

#include "util.hpp"
#include "station.hpp"
#include "train.hpp"
#include <utility>
#include <vector>
#include <map>
#include <algorithm>

//extern std::vector<Station*> station_list;
//extern std::vector<Train*> train_list;

//typedef std::pair<uint, bool> line_dir_key_t; // Line-dir key
typedef std::vector<uint> dest_vec_t;
typedef std::pair<dest_vec_t*, uint> vec_size_t; // Vector + size of vector

class Train;

class Router {
    private:
        Matrix train_mat;
        Matrix station_mat;

    public:
        Router(uint num_trains, uint num_stations);
        ~Router();
        void set_passengers(uint start_id, uint dest_id, uint8_t num);
        void transfer_passengers(Train* train, Station* cur_station);
};