#pragma once

#include "util.hpp"
#include "line.hpp"
#include "station.hpp"

#define DEFAULT_SPEED 1
#define FORWARD true
#define BACKWARD false

class Train : public Object {
    private:
        Line &line;
        //Station& next_station;
        std::list<Station*>::iterator next_station_iter;
        Station* prev_station;
        float distance_to_next_station;
        float speed;
        bool dir = FORWARD;
        bool do_update = true;

        void update_next_station(bool dir);
        

    public:
        Train(std::string name, Line &_line, float _speed=DEFAULT_SPEED);
        void init();
        void update(float time_step);
        
};