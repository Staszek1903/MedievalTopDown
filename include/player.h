
#ifndef PLAYER_H
#define PLAYER_H

#include "unit.h"
#include "event_rec.h"
#include <conio.h>
#include <iostream>
#include <cmath>
using std::cout;
using std::endl;


class Player : public Unit
{
    std::pair <int,int> mouse_pos;
    int is_moving;
    bool up_dir=0, down_dir=0, right_dir=0, left_dir=0;
    const double brake = 0.04;
    const double acc = 0.04; //acceleration
    Event_rec reciever;

    //float move_dir;

public:
    Player();
    virtual ~Player();

    void load_content();
    void update(ALLEGRO_EVENT ev);
    void draw(ALLEGRO_DISPLAY * disp);
    void unload_content();
};

#endif // PLAYER_H
