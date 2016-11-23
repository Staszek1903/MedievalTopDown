#ifndef MAP_H
#define MAP_H

#include "tile.h"

class Map
{
    std::vector <std::vector<Tile> > map;

public:
    Map();
    virtual ~Map();

    void load_content();
    void update(ALLEGRO_EVENT ev);
    void draw(ALLEGRO_DISPLAY *disp);
    void unload_content();
};

#endif // MAP_H
