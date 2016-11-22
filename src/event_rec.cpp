#include "event_rec.h"

Event_rec::Event_rec()
{
    //ctor
}

Event_rec::~Event_rec()
{
    //dtor
}

void Event_rec::set_speed_ref(std::pair <float, float> &ds)
{
    dir_speed = &ds;
}

void Event_rec::rec_event_list(std::vector <Event> ev_list)
{
    for(unsigned int i=0; i <ev_list.size(); i++)
    {
        switch(ev_list[i].get_type())
        {
        case Event::SOLID:
<<<<<<< HEAD
            dir_speed->first = 0;
            dir_speed->second = 0;
=======
            dir_speed->first = -(dir_speed->first*0.25);
            dir_speed->second = -(dir_speed->second*0.25);
>>>>>>> f6d7b97bd63074d6870cb0764ddc0267f299e23a
            std::cout<<"SOLID KURWA"<<std::endl;
        break;
        }
    }
}
