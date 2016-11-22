#ifndef DEF_ENNEMY_H
#define DEF_ENNEMY_H

#include "unit.h"
#include "event_trans.h"
#include <allegro5/allegro.h>


class Def_ennemy : public Unit
{

public:
    Def_ennemy();
    virtual ~Def_ennemy();

    void load_content();
    void update(ALLEGRO_EVENT ev);
    void draw(ALLEGRO_DISPLAY * disp);
    void unload_content();
};

#endif // DEF_ENNEMY_H
