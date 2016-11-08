#include "..\include\game_screen.h"

Game_screen::Game_screen()
{
    //ctor
}

Game_screen::~Game_screen()
{
    //dtor
}

void Game_screen::load_content()
{
    world.load_content();
}

void Game_screen::update(ALLEGRO_EVENT ev)
{
    world.update(ev);
}

void Game_screen::draw(ALLEGRO_DISPLAY *disp)
{
    al_clear_to_color(al_map_rgb(0,0,0));
    world.draw(disp);
}

void Game_screen::unload_content()
{
    world.unload_content();
}
