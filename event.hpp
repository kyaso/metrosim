#pragma once

#include <set>
#include "train.hpp"

class Event {
    private:
        float m_time;
    
    public:
        Event(float _time);
        void handle(float current_time);
        bool operator<(const Event &other) const;
        float time() const {return m_time;};
};

class TrainArrivalEvent : public Event {
    private:
        Train* m_train;

    public:
        TrainArrivalEvent(Train *train, float arrival_time);
        void handle(float current_time);
};

class EventList {
    private:
        std::set<Event*> event_list;
        void pop(std::set<Event*>::iterator it);

    public:
        void insert(Event* event);
        void handle(float current_time);
        void pop();
};