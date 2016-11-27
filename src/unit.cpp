#include "unit.h"

Unit::Unit()
{
    reciever.set_pos_ref(position,prev_position);
}

Unit::~Unit()
{
    //dtor
}

void Unit::load_content(std::pair <int,int> pos)
{

}

void Unit::update(ALLEGRO_EVENT ev)
{

}

void Unit::draw(ALLEGRO_DISPLAY * disp)
{

}

void Unit::unload_content()
{

}

bool Unit::is_coliding(Unit *b)
{
    return bounding.is_coliding(b->get_bounding());
}

Bounding_box& Unit::get_bounding()
{
    return bounding;
}


std::vector <Event> Unit::get_event_list()
{
    return transmiter.get_list(position);
}

void Unit::take_event_list(std::vector <Event> event_list)
{
    reciever.rec_event_list(event_list);
}
