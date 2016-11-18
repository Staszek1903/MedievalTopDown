#include "unit.h"

Unit::Unit()
{
    //ctor
}

Unit::~Unit()
{
    //dtor
}

void Unit::load_content()
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
