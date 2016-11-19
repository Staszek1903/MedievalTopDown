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
    move_speed = 5;
    direction = 0;
    //move_dir = 0;
    is_moving = 0;


    sprite = al_load_bitmap("def_unit.png");

    bounding.load_content(position, 32, Bounding_box::CUSTOM);

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
            case ALLEGRO_KEY_W:
                up_dir = 1;
                //dir_y = -acc;
                break;
            case ALLEGRO_KEY_S:
                down_dir = 1;
                //dir_y = acc;
                break;
            case ALLEGRO_KEY_A:
                left_dir = 1;
                //dir_y = -acc;
                break;
            case ALLEGRO_KEY_D:
                right_dir = 1;
                //dir_y = acc;
                break;
        }
    }
    else if(ev.type == ALLEGRO_EVENT_KEY_UP)
    {
        switch(ev.keyboard.keycode)
        {
        case ALLEGRO_KEY_A:
            left_dir = 0;
            break;
        case ALLEGRO_KEY_W:
            up_dir = 0;
            break;
        case ALLEGRO_KEY_S:
            down_dir = 0;
            break;
        case ALLEGRO_KEY_D:
            right_dir = 0;
            break;
        }
    }
    else if(ev.type == ALLEGRO_EVENT_TIMER)
    {
        float y = mouse_pos.second - position.second,
              x = mouse_pos.first -position.first;
        this->direction = atan2(y, x) + M_PI_2;

        if(up_dir)
        {
            if(dir_y>0) dir_y = 0;
            dir_y -= acc;
            if(dir_y<-1) dir_y = -1;
        }
        else if(down_dir)
        {
            if(dir_y<0) dir_y = 0;
            dir_y += acc;
            if(dir_y>1) dir_y = 1;
        }

        if(!down_dir && !up_dir && dir_y != 0)
        {
            if(dir_y<0)
            {
                dir_y += brake;
                if(dir_y>0) dir_y=0;
            }
            else
            {
                dir_y -= brake;
                if(dir_y<0) dir_y = 0;
            }
        }

        if(left_dir)
        {
            if(dir_x>0) dir_x = 0;
            dir_x -= acc;
            if(dir_x<-1) dir_x = -1;
        }
        else if (right_dir)
        {
            if(dir_x<0) dir_x = 0;
            dir_x += acc;
            if(dir_x>1) dir_x = 1;
        }

        if(!left_dir && !right_dir && dir_x != 0)
        {
            if(dir_x<0)
            {
                dir_x += brake;
                if(dir_x>0) dir_x = 0;
            }
            else
            {
                dir_x -= brake;
                if(dir_x<0) dir_x = 0;
            }
        }




        position.first += move_speed*dir_x;
        position.second += move_speed*dir_y;
    }
}

void Player::draw(ALLEGRO_DISPLAY * disp)
{
    al_draw_rotated_bitmap(sprite, 16,16, position.first, position.second, direction, NULL);
}

void Player::unload_content()
{

}
