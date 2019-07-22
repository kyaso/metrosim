#pragma once

#include "util.hpp"
#include <utility>
#include <vector>
#include <map>

typedef std::pair<uint, bool> line_dir_key_t; // Line-dir key
typedef std::vector<uint> dest_vec_t;
typedef std::pair<dest_vec_t*, uint> vec_size_t; // Vector + size of vector

class RoutingTable {
    private:
        std::map<line_dir_key_t, dest_vec_t* > routing_table;

        bool line_dir_key_exists(uint line_id, bool dir);
        void add_line_dir_key(uint line_id, bool dir);
    
    public:
        ~RoutingTable();
        void add_destination(uint line_id, bool dir, uint destination_id);
        vec_size_t get_destinations(uint line_id, bool dir);
    
};