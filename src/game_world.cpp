#include "game_world.h"

Game_world::Game_world()
{
    //ctor
}

Game_world::~Game_world()
{
    //dtor
}

void Game_world::load_content()
{
    units.push_back(new Player);
    units.push_back(new Def_ennemy);

    for(int i=0; i<units.size(); i++)
        units[i]->load_content();
}

void Game_world::update(ALLEGRO_EVENT ev)
{
    for(int i=0; i<units.size(); i++)
        units[i]->update(ev);
}

void Game_world::draw(ALLEGRO_DISPLAY *disp)
{
    for(int i=0; i<units.size(); i++)
        units[i]->draw(disp);
}

void Game_world::unload_content()
{
    for(int i=0; i<units.size(); i++)
        delete units[i];
}
