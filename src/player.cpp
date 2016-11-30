#include "player.h"
#include "camera.h"

Player::Player()
{

}

Player::~Player()
{
    //dtor
}

void Player::load_content(std::pair <int,int> pos)
{
    Camera::get().set_camera_ref(&position);
    position = pos;
    move_speed = 5;
    direction = 0;
    //move_dir = 0;
    is_moving = 0;


    sprite = al_load_bitmap("def_unit.png");
    anim.load_content("def_unit_anim.png", {32,32}, 20);
    std::vector <int> seq1 = {0,1,2,3,4,5,6,7},
                      seq2 = {8,9,10,11,10,9,12,13,14,15,14,13};
    anim.add_sequence(seq1);
    anim.add_sequence(seq2);
    anim.set_cut_sequence(1);


    bounding.load_content(position, 32, Bounding_box::CUSTOM);

    cout<<"spierdalaj"<<endl;
    cout<<Bounding_box::POINT<<endl;

    if(!sprite){
        cout<<"ni mo bitmapy"<<endl;
        system("PAUSE");
    }
}

void Player::update(ALLEGRO_EVENT ev)
{
    anim.update(ev);
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
                //dir_speed.second = -acc;
                break;
            case ALLEGRO_KEY_S:
                down_dir = 1;
                //dir_speed.second = acc;
                break;
            case ALLEGRO_KEY_A:
                left_dir = 1;
                //dir_speed.second = -acc;
                break;
            case ALLEGRO_KEY_D:
                right_dir = 1;
                //dir_speed.second = acc;
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
        prev_position = position;
        float y = mouse_pos.second - 300,
              x = mouse_pos.first -400;
        this->direction = atan2(y, x) + 1.57079632679489661923; // M_PI_2 ale nie dziala

        if(up_dir)
        {
            if(dir_speed.second>0) dir_speed.second = 0;
            dir_speed.second -= acc;
            if(dir_speed.second<-1) dir_speed.second = -1;
        }
        else if(down_dir)
        {
            if(dir_speed.second<0) dir_speed.second = 0;
            dir_speed.second += acc;
            if(dir_speed.second>1) dir_speed.second = 1;
        }

        if(!down_dir && !up_dir && dir_speed.second != 0)
        {
            if(dir_speed.second<0)
            {
                dir_speed.second += brake;
                if(dir_speed.second>0) dir_speed.second=0;
            }
            else
            {
                dir_speed.second -= brake;
                if(dir_speed.second<0) dir_speed.second = 0;
            }
        }

        if(left_dir)
        {
            if(dir_speed.first>0) dir_speed.first = 0;
            dir_speed.first -= acc;
            if(dir_speed.first<-1) dir_speed.first = -1;
        }
        else if (right_dir)
        {
            if(dir_speed.first<0) dir_speed.first = 0;
            dir_speed.first += acc;
            if(dir_speed.first>1) dir_speed.first = 1;
        }

        if(!left_dir && !right_dir && dir_speed.first != 0)
        {
            if(dir_speed.first<0)
            {
                dir_speed.first += brake;
                if(dir_speed.first>0) dir_speed.first = 0;
            }
            else
            {
                dir_speed.first -= brake;
                if(dir_speed.first<0) dir_speed.first = 0;
            }
        }



        if(right_dir || left_dir ||down_dir || up_dir)
            anim.set_cut_sequence(2);
        else
            anim.set_cut_sequence(1);

        position.first += move_speed*dir_speed.first;
        position.second += move_speed*dir_speed.second;

        bounding.update(position);


    }
}

void Player::draw(ALLEGRO_DISPLAY * disp)
{
    //Camera::get().draw_sprite(sprite,{16,16},position,direction,0);
    //bounding.draw_box(disp);
    anim.draw(disp,position,direction,0);
}

void Player::unload_content()
{
    al_destroy_bitmap(sprite);
}
