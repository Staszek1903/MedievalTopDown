#ifndef ANIMATION_H
#define ANIMATION_H

#include <allegro5/allegro.h>
#include <utility>
#include <vector>
#include <string>
#include <iostream>
#include "camera.h"

class Animation
{
    ALLEGRO_BITMAP * sheet;         //przechowuje ca³¹ bitmape animacji
    std::vector <ALLEGRO_BITMAP*> frames;   //przechowuje poszczegolne framy

    std::pair <int,int> frame_dim;  //dimention jednege frama
    std::vector<std::vector <int> > sequences;  //vector kombinacji framow

    int sequence =0, stage =0;
    int time_counter =0, fps =2;

public:
    Animation();
    virtual ~Animation();

    bool load_content(std::string, std::pair <int,int>, int fps);
    void update(ALLEGRO_EVENT);
    void draw(ALLEGRO_DISPLAY *disp, std::pair<int,int> pos, float angle, int flags);
    void unload_content();

    void add_sequence(std::vector <int>);
    void set_cut_sequence(int);
};

#endif // ANIMATION_H
