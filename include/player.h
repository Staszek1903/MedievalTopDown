#ifndef PLAYER_H
#define PLAYER_H

#include "unit.h"
#include <conio.h>
#include <iostream>
#include <cmath>
using std::cout;
using std::endl;


class Player : public Unit
{
    std::pair <int,int> mouse_pos;
    int is_moving;
    float move_dir;

public:
    Player();
    virtual ~Player();

    void load_content();
    void update(ALLEGRO_EVENT ev);
    void draw(ALLEGRO_DISPLAY * disp);
    void unload_content();
};

#endif // PLAYER_H
