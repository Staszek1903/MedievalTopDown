#ifndef EVENT_TRANS_H
#define EVENT_TRANS_H

#include <vector>
#include <utility>
#include "event.h"

class Event_trans
{
    std::vector <Event> ev_list;

public:
    Event_trans();
    virtual ~Event_trans();

    void add_event(Event::Type, int);
    std::vector <Event> get_list(std::pair <float, float>);
};

#endif // EVENT_TRANS_H
