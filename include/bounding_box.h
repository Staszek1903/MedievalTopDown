#ifndef BOUNDING_BOX_H
#define BOUNDING_BOX_H

#include <utility>
#include <iostream>
#include <vector>
#include <conio.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_primitives.h>
#include "camera.h"

class Bounding_box
{
    int type,
        size;
    std::pair <int, int> pos;

    float cross_product(std::pair <int,int> a, std::pair <int, int> v1, std::pair <int, int> v2);
    bool is_inside(std::pair <int, int> v2, std::vector <std::pair <int, int> > &p);

    bool box_coli(Bounding_box &b);
    bool vect_coli(Bounding_box &b);

    int up, down, left, right;
    std::vector <std::pair <int, int> > bounding_points;

public:
    enum Type
    {
        BOX,
        CUSTOM,
        POINT
    };

    Bounding_box();
    ~Bounding_box();

    void load_content(std::pair <int, int> pos, int size, Type type);
    void update(std::pair <int, int> pos);
    bool is_coliding(Bounding_box &b);
    void get_real_points(std::vector <std::pair <int, int> > &v);
    void clear_points();
    void new_point(std::pair <int,int>);

    void draw_box(ALLEGRO_DISPLAY*);

};

#endif // BOUNDING_BOX_H
