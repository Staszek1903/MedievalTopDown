#include "def_ennemy.h"

Def_ennemy::Def_ennemy()
{
    transmiter.add_event(Event::SOLID,0);
}

Def_ennemy::~Def_ennemy()
{
    //dtor
}

void Def_ennemy::load_content()
{
    position.first = 500;
    position.second = 500;
    direction = 0;

    sprite = al_load_bitmap("enemy_def.png");
    bounding.load_content(position, 32, Bounding_box::BOX);
}

void Def_ennemy::update(ALLEGRO_EVENT ev)
{
    bounding.update(position);
}

void Def_ennemy::draw(ALLEGRO_DISPLAY * disp)
{
    al_draw_rotated_bitmap(sprite, 16,16, position.first,position.second, direction, 0);
}

void Def_ennemy::unload_content()
{

}
