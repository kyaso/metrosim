#include "routing_table.hpp"

RoutingTable::~RoutingTable() {
    DBG("RoutingTable destructor");
    for(std::map<line_dir_key_t, dest_vec_t*>::iterator it = routing_table.begin(); it != routing_table.end(); it++) {
        delete it->second;
    }
    routing_table.clear();
}

bool RoutingTable::line_dir_key_exists(uint line_id, bool dir) {
    line_dir_key_t key(line_id, dir);
    return routing_table.find(key) != routing_table.end();
}

void RoutingTable::add_line_dir_key(uint line_id, bool dir) {
    if(!line_dir_key_exists(line_id, dir)) {
        DBG("Adding line-dir key: (" << line_id << ", " << dir << ")");
        line_dir_key_t key(line_id, dir);
        routing_table[key] = new dest_vec_t;
    }
}

void RoutingTable::add_destination(uint line_id, bool dir, uint destination_id) {
    if(!line_dir_key_exists(line_id, dir)) {
        add_line_dir_key(line_id, dir);
    }
    DBG("Adding destination " << destination_id << " to line-dir-key (" << line_id << ", " << dir << ")");
    line_dir_key_t key(line_id, dir);
    routing_table[key]->push_back(destination_id);
}

vec_size_t RoutingTable::get_destinations(uint line_id, bool dir) {
    vec_size_t ret;
    if(line_dir_key_exists(line_id, dir)) {
        line_dir_key_t key(line_id, dir);
        dest_vec_t* vec = routing_table[key];
        ret.first = vec;
        ret.second = vec->size();
    }
    else {
        ret.first = NULL;
        ret.second = 0;
    }

    return ret;
}