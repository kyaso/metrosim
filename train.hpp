#pragma once

#include "util.hpp"
#include "line.hpp"
#include "station.hpp"
#include "event.hpp"

#define DEFAULT_SPEED 1
#define FORWARD true
#define BACKWARD false

class EventList;
extern EventList* events;

class Train : public Object {
    private:
        Line &line;
        //Station& next_station;
        std::list<Station*>::iterator next_station_iter;
        Station* prev_station;
        float distance_to_next_station;
        float speed;
        float next_station_arrival_time;
        bool dir = FORWARD;
        bool do_update = true;

        void update_next_station(bool dir);
        void update_next_station(float current_time, bool dir);
        

    public:
        Train(std::string name, Line &_line, float _speed=DEFAULT_SPEED);
        ~Train() {DBG("Train destructor");}
        void init();
        void update(float time_step);
        void arrival_handler(float current_time);
        
};