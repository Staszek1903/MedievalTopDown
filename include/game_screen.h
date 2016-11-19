#ifndef GAME_SCREEN_H
#define GAME_SCREEN_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include "screen.h"
#include "game_world.h"


class Game_screen : public Screen
{
    Game_world world;

public:
    Game_screen();
    virtual ~Game_screen();

    void load_content();
    void update(ALLEGRO_EVENT ev);
    void draw(ALLEGRO_DISPLAY *disp);
    void unload_content();
};

#endif // GAME_SCREEN_H
