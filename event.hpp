#pragma once

#include <iostream>
#include "util.hpp"
#include "train.hpp"

class Train;

class Event {
    private:
        float m_time;
    
    public:
        Event(float _time);
        virtual ~Event() {DBG("Event destructor");};
        virtual void handle(float current_time) {DBG("Event handler");};
        bool operator<(const Event &other) const;
        float time() const {return m_time;};
};

class TrainArrivalEvent : public Event {
    private:
        Train* m_train;

    public:
        TrainArrivalEvent(Train *train, float arrival_time);
        ~TrainArrivalEvent() {DBG("TrainArrivalEvent destructor");}
        void handle(float current_time);
};

class EventList {
    private:
        std::list<Event*> event_list;
        std::list<Event*>::iterator pop();

    public:
        ~EventList();
        void insert(Event *event);
        void handle(float current_time);
};