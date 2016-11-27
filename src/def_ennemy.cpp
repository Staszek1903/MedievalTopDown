#include "def_ennemy.h"

Def_ennemy::Def_ennemy()
{
    transmiter.add_event(Event::SOLID,0);
}

Def_ennemy::~Def_ennemy()
{
    //dtor
}

void Def_ennemy::load_content(std::pair <int,int> pos)
{
    position = pos;
    direction = 0;

    sprite = al_load_bitmap("enemy_def.png");
    bounding.load_content(position, 32, Bounding_box::CUSTOM);
    bounding.clear_points();
    bounding.new_point({0,-16});
    bounding.new_point({16,16});
    bounding.new_point({-16,16});
}

void Def_ennemy::update(ALLEGRO_EVENT ev)
{
    bounding.update(position);
}

void Def_ennemy::draw(ALLEGRO_DISPLAY * disp)
{
    Camera::get().draw_sprite(sprite, {16,16}, position, direction, 0);
    //bounding.draw_box(disp);
}

void Def_ennemy::unload_content()
{

}
