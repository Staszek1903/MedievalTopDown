#include "camera.h"

Camera::Camera()
{
    //ctor
}

Camera::~Camera()
{
    //dtor
}

Camera & Camera::get()
{
    static Camera instatnt;
    return instatnt;
}

void Camera::set_camera_ref(std::pair <float, float> *pos)
{
    camera_pos = pos;
}

void Camera::draw_sprite(ALLEGRO_BITMAP * sprite, std::pair <int, int> sprite_center,std::pair<int,int> pos,float angle,int flags)
{
    pos.first -= camera_pos->first-400;
    pos.second -= camera_pos->second-300;
    al_draw_rotated_bitmap(sprite, 16,16, pos.first,pos.second, angle, flags);
}

void Camera::draw_line(std::pair<int,int> p1, std::pair <int,int> p2, ALLEGRO_COLOR color, int thickness)
{
    p1.first -= camera_pos->first-400;
    p1.second -= camera_pos->second-300;
    p2.first -= camera_pos->first-400;
    p2.second -= camera_pos->second-300;

    al_draw_line(p1.first, p1.second, p2.first, p2.second, color, thickness);
}

void Camera::draw_circle(std::pair <int,int> pos,int radius,ALLEGRO_COLOR color)
{
    pos.first -= camera_pos->first-400;
    pos.second -= camera_pos->second-300;

    al_draw_filled_circle(pos.first, pos.second, radius,color);
}
