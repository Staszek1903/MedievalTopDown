#ifndef SCREEN_MANAGER_H
#define SCREEN_MANAGER_H

#include <allegro5/allegro.h>
#include "screen.h"
#include "game_screen.h"

class Screen_manager
{
    Screen *current_screen;

public:
    Screen_manager();
    virtual ~Screen_manager();

    void load_content();
    void update(ALLEGRO_EVENT ev);
    void draw(ALLEGRO_DISPLAY *disp);
    void unload_content();
};

#endif // SCREEN_MANAGER_H
