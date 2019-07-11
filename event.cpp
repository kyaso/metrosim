#include "event.hpp"

Event::Event(float _time) {
    m_time = _time;
}

bool Event::operator<(const Event &other) const {
    return time < other.time; // Does this work? Cause time is private
};

TrainArrivalEvent::TrainArrivalEvent(Train *train, float arrival_time) : Event(arrival_time) {
    m_train = train;
}

void TrainArrivalEvent::handle(float current_time) {
    m_train->arrival_handler(current_time);
}

void EventList::pop(std::set<Event*>::iterator it) {
    Event* evt_ptr = (*it);
    event_list.erase(it);
    delete evt_ptr; // Delete event object from heap
}

void EventList::insert(Event *event) {
    event_list.insert(event);
}

void EventList::handle(float current_time) {
    std::set<Event*>::iterator it = event_list.begin();
    while((*it)->time() == current_time) {
        (*it)->handle(current_time);
        pop(it++);
    }
}