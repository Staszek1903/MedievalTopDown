#include "event_rec.h"

Event_rec::Event_rec()
{
    //ctor
}

Event_rec::~Event_rec()
{
    //dtor
}

void Event_rec::set_pos_ref(std::pair <float, float> &pos, std::pair <float, float> &prev_pos)
{
    prev_position = &prev_pos;
    position = &pos;
}

void Event_rec::rec_event_list(std::vector <Event> ev_list)
{
    for(unsigned int i=0; i <ev_list.size(); i++)
    {
        switch(ev_list[i].get_type())
        {
        case Event::SOLID:
            *position = *prev_position;
           // std::cout<<"SOLID KURWA"<<std::endl;
        break;
        }
    }
}
