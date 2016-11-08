#include "def_ennemy.h"

Def_ennemy::Def_ennemy()
{
    //ctor
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
}

void Def_ennemy::update(ALLEGRO_EVENT ev)
{

}

void Def_ennemy::draw(ALLEGRO_DISPLAY * disp)
{
    al_draw_rotated_bitmap(sprite, 16,16, position.first,position.second, direction, NULL);
}

void Def_ennemy::unload_content()
{

}
