#include "event_trans.h"

Event_trans::Event_trans()
{
    //ctor
}

Event_trans::~Event_trans()
{
    //dtor
}


void Event_trans::add_event(Event::Type type, int value)
{
    ev_list.push_back({type,value});
}

std::vector <Event>  Event_trans::get_list(std::pair <float, float> pos)
{
    for(unsigned int i=0; i<ev_list.size(); i++)
        ev_list[i].pos = pos;

    return ev_list;
}
