#ifndef CAMERA_H
#define CAMERA_H

#include <utility>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>


class Camera
{
    std::pair <float, float> *camera_pos;
    Camera();
    virtual ~Camera();
public:

    static Camera & get();
    void set_camera_ref(std::pair <float, float> *pos);
    void draw_sprite(ALLEGRO_BITMAP * sprite, std::pair <int, int> sprite_center,std::pair<int,int> pos,float angle,int flags);
    void draw_line(std::pair<int,int> p1, std::pair <int,int> p2, ALLEGRO_COLOR color, int thickness);
    void draw_circle(std::pair <int,int> pos,int radius,ALLEGRO_COLOR color);

};

#endif // CAMERA_H
