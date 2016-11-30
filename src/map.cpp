#include "map.h"

Map::Map()
{
    //ctor
}

Map::~Map()
{
    //dtor
}

void Map::load_content()
{
    map.resize(19);

    for(int i=0; i <map.size(); i++)
    {
        map[i].resize(25);
        for(int j=0; j<map[i].size(); j++)
        {
             map[i][j].load_content({j*32, i*32});
        }
    }
}

void Map::update(ALLEGRO_EVENT ev)
{
    for(int i=0; i<map.size(); i++)
        for(int j=0; j<map[i].size(); j++)
            map[i][j].update(ev);
}

void Map::draw(ALLEGRO_DISPLAY *disp)
{
    for(int i=0; i<map.size(); i++)
        for(int j=0; j<map[i].size(); j++)
            map[i][j].draw(disp);
}

void Map::unload_content()
{
    //std::cout<<"mapa unload"<<std::endl;
    for(int i=0; i<map.size(); i++)
        for(int j=0; j<map[i].size(); j++)
            map[i][j].unload_content();
}
