# pragma once

#include <list>
#include "util.hpp"
#include "station.hpp"
#include <string>

class Line : public Object {
    private:
        std::list<Station*> station_list;
        
        
    public:
        Line(std::string _name);
        void add_station(Station* s);
        Station* first_station();
        Station* last_station();
        std::list<Station*>::iterator first();
        int num_stations();

};