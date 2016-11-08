#include "player.h"

Player::Player()
{

}

Player::~Player()
{
    //dtor
}

void Player::load_content()
{
    position.first = 100;
    position.second = 100;
    move_speed = 1;
    direction = 0;
    move_dir = 0;
    is_moving = 0;

    bounding.load_content(position, 32, Bounding_box::SQUARE);


    sprite = al_load_bitmap("def_unit.png");

    cout<<"spierdalaj"<<endl;

    if(!sprite){
        cout<<"ni mo bitmapy"<<endl;
        system("PAUSE");
    }
}

void Player::update(ALLEGRO_EVENT ev)
{
    if(ev.type == ALLEGRO_EVENT_MOUSE_AXES)
    {
        mouse_pos.first = ev.mouse.x;
        mouse_pos.second = ev.mouse.y;
    }
    else if(ev.type == ALLEGRO_EVENT_KEY_DOWN)
    {
        switch(ev.keyboard.keycode)
        {
        case ALLEGRO_KEY_A:
            is_moving++;
            move_dir = M_PI;
            break;
        case ALLEGRO_KEY_W:
            is_moving++;
            move_dir = -M_PI_2;
            break;
        case ALLEGRO_KEY_S:
            is_moving++;
            move_dir = M_PI_2;
            break;
        case ALLEGRO_KEY_D:
            is_moving++;
            move_dir = 0;
            break;
        }
    }
    else if(ev.type == ALLEGRO_EVENT_KEY_UP)
    {
        switch(ev.keyboard.keycode)
        {
        case ALLEGRO_KEY_A:
        case ALLEGRO_KEY_W:
        case ALLEGRO_KEY_S:
        case ALLEGRO_KEY_D:
            is_moving--;
            break;
        }
    }
    else if(ev.type == ALLEGRO_EVENT_TIMER)
    {
        float y = mouse_pos.second - position.second,
              x = mouse_pos.first -position.first;
        this->direction = atan2(y, x) + M_PI_2;

        if(is_moving>0)
        {
            position.first = position.first +cos(direction + move_dir);
            position.second = position.second + sin(direction+ move_dir);
        }
    }

    bounding.update(position);
}

void Player::draw(ALLEGRO_DISPLAY * disp)
{
    al_draw_rotated_bitmap(sprite, 16,16, position.first, position.second, direction, NULL);
}

void Player::unload_content()
{

}

