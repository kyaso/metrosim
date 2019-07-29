#include "router.hpp"

Router::Router(uint num_trains, uint num_stations) {
    train_mat = Matrix(num_trains, num_stations);
    station_mat = Matrix(num_stations, num_stations);
}

Router::~Router() {
    DBG("Router destructor");
}

void Router::set_passengers(uint start_id, uint dest_id, uint8_t num) {
    station_mat.set_val(start_id, dest_id, num);
}

void Router::transfer_passengers(Train* train, Station* cur_station) {
    uint train_id = train->id();
    uint cur_station_id = cur_station->id();

    // Release passengers who have cur_station as final destination
    if(train_mat.get_val(train_id, cur_station_id) != 0) {
        DBG("Train " << train_id << " delivered " << train_mat.get_val(train_id, cur_station_id) << " passengers to station " << cur_station_id << ".");
        train_mat.reset_val(train_id, cur_station_id);
    }

    // Board all passengers who can take <train> to reach their destination
    DBG("Boarding passengers to");
    vec_size_t dests = cur_station->routing_table.get_destinations(train->line_id(), train->get_dir());
    for(int i = 0; i < dests.second; i++) {
        uint dest_id = (*dests.first)[i];
        uint num_pas = station_mat.get_val(cur_station_id, dest_id);
        DBG(dest_id << ": " << num_pas);
        train_mat.add_val(train_id, dest_id, num_pas);
        station_mat.reset_val(cur_station_id, dest_id);
    }
    // Release all other destinations
    DBG("Releasing passengers to");
    for(int id = 0; id < train_mat.get_dim_x(); id++) {
        if(std::find(dests.first->begin(), dests.first->end(), id) != dests.first->end()) {
            continue;
        }
        uint num_pas = train_mat.get_val(train_id, id);
        DBG(id << ": " << num_pas);
        station_mat.add_val(cur_station_id, id, num_pas);
        train_mat.reset_val(train_id, id);
    }
}