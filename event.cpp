#include "event.hpp"

Event::Event(float _time) {
    m_time = _time;
}

bool Event::operator<(const Event &other) const {
    return m_time < other.m_time; // Does this work? Cause time is private
};

TrainArrivalEvent::TrainArrivalEvent(Train *train, float arrival_time) : Event(arrival_time) {
    m_train = train;
}

void TrainArrivalEvent::handle(float current_time) {
    m_train->arrival_handler(current_time);
}

std::list<Event*>::iterator EventList::pop() {
    Event *evt = event_list.front();
    event_list.pop_front();
    delete evt;
    return event_list.begin();
}

void EventList::insert(Event *event) {
    if(event_list.size() == 0 || event_list.back()->time() <= event->time()) {
        event_list.push_back(event);
    } else {
        auto it = event_list.begin();
        //while((*it)->time() < event->time()) {it++;}
        while(*(*it) < *event) {it++;}
        event_list.insert(it, event);
    }
}

void EventList::handle(float current_time) {
    std::list<Event*>::iterator it = event_list.begin();
    while((*it)->time() == current_time) {
        std::cout << std::endl << "Time: " << current_time << std::endl;
        (*it)->handle(current_time);
        it = pop();
    }
}