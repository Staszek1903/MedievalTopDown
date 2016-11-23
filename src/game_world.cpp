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
    mapa.load_content();

    units.push_back(new Player);
    units.push_back(new Def_ennemy);

    for(unsigned int i=0; i<units.size(); i++)
        units[i]->load_content();
}

void Game_world::update(ALLEGRO_EVENT ev)
{
    mapa.update(ev);
    for(unsigned int i=0; i<units.size(); i++)
        units[i]->update(ev);

    for(unsigned int i=0; i<units.size(); i++)
    {
        for(unsigned int j =i+1; j <units.size(); j++)
        {
            if(units[i]->is_coliding(units[j]))
            {
                units[i]->take_event_list(units[j]->get_event_list());
                units[j]->take_event_list(units[i]->get_event_list());
            }
        }
    }
}

void Game_world::draw(ALLEGRO_DISPLAY *disp)
{
    mapa.draw(disp);
    for(unsigned int i=0; i<units.size(); i++)
        units[i]->draw(disp);
}

void Game_world::unload_content()
{
    //mapa.unload_content();
    for(unsigned int i=0; i<units.size(); i++)
        delete units[i];
}
