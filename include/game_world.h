#ifndef GAME_WORLD_H
#define GAME_WORLD_H

#include <allegro5/allegro.h>
#include <vector>
#include "unit.h"
#include "player.h"
#include "def_ennemy.h"
#include "map.h"

class Game_world
{
    std::vector <Unit*> units;
    Map mapa;

public:
    Game_world();
    virtual ~Game_world();

    void load_content();
    void update(ALLEGRO_EVENT ev);
    void draw(ALLEGRO_DISPLAY *disp);
    void unload_content();
};

#endif // GAME_WORLD_H
