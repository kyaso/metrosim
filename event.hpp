#pragma once

#include <iostream>
#include "train.hpp"

class Train;

class Event {
    private:
        float m_time;
    
    public:
        Event(float _time);
        virtual ~Event() {/*std::cout << "Destructor for Event called" << std::endl;*/};
        virtual void handle(float current_time) = 0;
        bool operator<(const Event &other) const;
        float time() const {return m_time;};
};

class TrainArrivalEvent : public Event {
    private:
        Train* m_train;

    public:
        TrainArrivalEvent(Train *train, float arrival_time);
        ~TrainArrivalEvent() {/*std::cout << "Destructor for TrainArrivalEvent called" << std::endl;*/}
        void handle(float current_time);
};

class EventList {
    private:
        std::list<Event*> event_list;
        std::list<Event*>::iterator pop();

    public:
        void insert(Event* event);
        void handle(float current_time);
};