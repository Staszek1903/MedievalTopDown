#include "event.h"

Event::Event(Type type, int val)
:type(type), value(val), pos({0,0})
{}

Event::Event(const Event& ev)
:type(ev.get_type()), value(ev.value), pos(ev.pos)
{}

Event::~Event()
{
    //dtor
}

Event::Type Event::get_type() const
{ return type; }
