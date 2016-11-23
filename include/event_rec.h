#ifndef EVENT_REC_H
#define EVENT_REC_H

#include "event.h"
#include <vector>
#include <cmath>
#include <iostream>

class Event_rec
{
    std::pair <float, float> *position, *prev_position;
public:
    Event_rec();
    virtual ~Event_rec();

    void set_pos_ref(std::pair <float, float> &, std::pair <float, float> &);
    void rec_event_list(std::vector <Event> ev_list);
};

#endif // EVENT_REC_H
