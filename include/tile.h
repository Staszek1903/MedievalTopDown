#ifndef TILE_H
#define TILE_H

#include <allegro5/allegro.h>
#include "event_trans.h"
#include "event_rec.h"
#include <conio.h>

class Tile
{
    std::pair <int,int> position;
    ALLEGRO_BITMAP *sprite;
    Event_rec reciever;
    Event_trans transmiter;

public:
    Tile();
    virtual ~Tile();

    void load_content(std::pair <int,int>);
    void update(ALLEGRO_EVENT ev);
    void draw(ALLEGRO_DISPLAY *disp);
    void unload_content();
    std::vector <Event> get_event_list();
    void take_event_list(std::vector <Event>);
};

#endif // TILE_H
