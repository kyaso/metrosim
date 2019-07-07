# pragma once

#include <list>
#include "station.hpp"
#include <string>

using namespace std;

class Line {
    private:
        string name_;
        list<Station*> station_list;
        
        
    public:
        Line(string _name);
        void add_station(Station* s);
        Station* first_station();
        Station* last_station();
        list<Station*>::iterator first();
        int num_stations();
        string name() { return name_; };

};