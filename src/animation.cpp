#include "animation.h"

Animation::Animation()
{
    //ctor
}

Animation::~Animation()
{
    //dtor
}

bool Animation::load_content(std::string dir, std::pair <int,int> frame, int fps)
{
    frame_dim = frame;
    sheet = al_load_bitmap(dir.c_str());
    if(!sheet)
    {
        std::cout<<"brak anim"<<std::endl;
        return false;
    }

    std::cout<<"dalo rade :)"<<std::endl;

    std::pair <int, int> dims=  //okresla ile framow jest sheecie
    {
        al_get_bitmap_width(sheet)/frame_dim.first,
        al_get_bitmap_height(sheet)/frame_dim.second
    };

    for(int i=0; i<dims.second; i++)    //dzielenia sheeta na framy
    {
        for(int j=0; j<dims.first; j++)
        {
            frames.push_back(al_create_sub_bitmap(sheet, j*frame.first, i*frame.second, frame.first, frame.second));
        }
    }

    sequences.push_back(std:: vector <int> ());
    for(int i=0; i<frames.size(); i++)
        sequences[0].push_back(i);  //tworzy podstawowa kombinacje (po kolei)

    this->fps = fps;
}

void Animation::update(ALLEGRO_EVENT ev)
{
    if(ev.type == ALLEGRO_EVENT_TIMER)
    {
        time_counter++;

        if(time_counter%(100/fps) == 0)
            stage ++;
        if(stage >= sequences[sequence].size())
            stage =0;
    }
}

void Animation::draw(ALLEGRO_DISPLAY *disp, std::pair<int,int> pos, float angle, int flags)
{
    std::pair <int,int> center = {frame_dim.first/2, frame_dim.second/2};
    Camera::get().draw_sprite(frames[sequences[sequence][stage]], center, pos, angle, flags);
}

void Animation::unload_content()
{
    al_destroy_bitmap(sheet);
}

void Animation::add_sequence(std::vector <int> seq)
{
    sequences.push_back(seq);
}

void Animation::set_cut_sequence(int seq)
{
    sequence = seq;
    if(stage >= sequences[sequence].size())
        stage = 0;
    //std::cout<<sequence<<std::endl;
}
