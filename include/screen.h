#ifndef SCREEN_H
#define SCREEN_H

#include <allegro5/allegro.h>

class Screen
{
public:
    Screen();
    virtual ~Screen();

    virtual void load_content();
    virtual void update(ALLEGRO_EVENT ev);
    virtual void draw(ALLEGRO_DISPLAY *disp);
    virtual void unload_content();
};

#endif // SCREEN_H
