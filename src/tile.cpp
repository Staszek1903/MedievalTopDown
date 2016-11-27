#include "tile.h"

Tile::Tile()
{
    //ctor
}

Tile::~Tile()
{
    //dtor
}

void Tile::load_content(std::pair <int,int> pos)
{
    position = pos;
    sprite = al_load_bitmap("Tile.png");
    if(!sprite)
    {
        std::cout<<"nie mozna zaladowac tajla"<<std::endl;
        getch();
    }
}

void Tile::update(ALLEGRO_EVENT ev)
{

}

void Tile::draw(ALLEGRO_DISPLAY *disp)
{
    Camera::get().draw_sprite(sprite,{16,16},position,0, 0);
}

void Tile::unload_content()
{

}

std::vector <Event> Tile::get_event_list()
{

}

void Tile::take_event_list(std::vector <Event>)
{

}
