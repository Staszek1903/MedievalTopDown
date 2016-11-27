#ifndef UNIT_H
#define UNIT_H

#include <allegro5/allegro.h>
#include <utility>

#include "bounding_box.h"
#include "event_trans.h"
#include "event_rec.h"

class Unit
{
protected:
    std::pair <float,float> position, prev_position;
    float move_speed;
    std::pair <float, float> dir_speed;
    double direction; // radian angle

    ALLEGRO_BITMAP * sprite;
    Bounding_box bounding;
    Event_trans transmiter;
    Event_rec reciever;

public:
    Unit();
    virtual ~Unit();

    virtual void load_content(std::pair <int,int> pos);
    virtual void update(ALLEGRO_EVENT ev);
    virtual void draw(ALLEGRO_DISPLAY * disp);
    virtual void unload_content();
    bool is_coliding(Unit *b);
    Bounding_box& get_bounding();
    std::vector <Event> get_event_list();
    void take_event_list(std::vector <Event>);

};

#endif // UNIT_H
