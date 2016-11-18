#ifndef UNIT_H
#define UNIT_H

#include <allegro5/allegro.h>
#include <utility>

#include "bounding_box.h"

class Unit
{
protected:
    std::pair <float,float> position;
    float move_speed;
    double direction; // radian angle

    ALLEGRO_BITMAP * sprite;
    Bounding_box bounding;

public:
    Unit();
    virtual ~Unit();

    virtual void load_content();
    virtual void update(ALLEGRO_EVENT ev);
    virtual void draw(ALLEGRO_DISPLAY * disp);
    virtual void unload_content();
    bool is_coliding(Unit *b);
    Bounding_box& get_bounding();

};

#endif // UNIT_H
