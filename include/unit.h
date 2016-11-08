#ifndef UNIT_H
#define UNIT_H

#include <allegro5/allegro.h>
#include <utility>

class Unit
{
protected:
    std::pair <float,float> position;
    float move_speed;
    double direction; // radian angle

    ALLEGRO_BITMAP * sprite;

public:
    Unit();
    virtual ~Unit();

    virtual void load_content();
    virtual void update(ALLEGRO_EVENT ev);
    virtual void draw(ALLEGRO_DISPLAY * disp);
    virtual void unload_content();

};

#endif // UNIT_H
