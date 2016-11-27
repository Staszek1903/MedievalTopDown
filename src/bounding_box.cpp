#include "bounding_box.h"

Bounding_box::Bounding_box()
{
    //ctor
}

Bounding_box::~Bounding_box()
{
    //dtor
}

float Bounding_box::cross_product(std::pair <int,int> a, std::pair <int, int> v1, std::pair <int, int> v2)
{
    std::pair <float, float> l1, l2;
    l1.first = v1.first - a.first;
    l1.second = v1.second - a.second;
    l2.first = v2.first - a.first;
    l2.second = v2.second - a.second;

    return ((l1.first*l2.second)-(l1.second*l2.first));
}

bool Bounding_box::is_inside(std::pair <int, int> v2, std::vector <std::pair <int, int> > &p)
{
    std::pair <int,int> a,v1;

    for(int i =0; i<p.size(); i++)
    {
        a = p[i];
        v1 = p[(i+1)%p.size()];
        if(cross_product(a,v1,v2) < 0 )
            return false;
    }
    return true;
}

void Bounding_box::get_real_points(std::vector <std::pair <int, int> > &v)
{
    v.clear();
    for(unsigned int i=0; i<bounding_points.size(); i++)
    v.push_back({bounding_points[i].first+pos.first, bounding_points[i].second+pos.second});
}

bool Bounding_box::box_coli(Bounding_box &b)
{
    if(up < b.down && b.up < down && left < b.right && b.left < right)
        return true;
    return false;
}

bool Bounding_box::vect_coli(Bounding_box &b)
{
    std::vector <std::pair <int,int> > pb, pm;
    b.get_real_points(pb);
    get_real_points(pm);

    for(int i=0; i<pm.size(); i++)
        if(is_inside(pm[i],pb))
            return true;

    for(int i=0; i<pb.size(); i++)
        if(is_inside(pb[i],pm))
            return true;

    return false;
}

void Bounding_box::load_content(std::pair <int, int> pos, int size, Type type)
{
    this->size = size;
    this->type = type;
    up = pos.second - (size/2);
    down = pos.second + (size/2);
    left = pos.first - (size/2);
    right = pos.first + (size/2);
    this->pos = pos;
    if(type == CUSTOM)
    {
        bounding_points.push_back({0,-(size/2)});
        bounding_points.push_back({(size/2),0});
        bounding_points.push_back({0,(size/2)});
        bounding_points.push_back({-(size/2),0});
    }
    else if(type == BOX)
    {
        bounding_points.push_back({-(size/2),-(size/2)});
        bounding_points.push_back({(size/2),-(size/2)});
        bounding_points.push_back({(size/2),(size/2)});
        bounding_points.push_back({-(size/2),(size/2)});
    }
    else if(type == POINT)
    {
        bounding_points.push_back({5,5});
    }
}

void Bounding_box::update(std::pair <int, int> pos)
{
    up = pos.second - (size/2);
    down = pos.second + (size/2);
    left = pos.first - (size/2);
    right = pos.first + (size/2);
    this->pos = pos;
}

bool Bounding_box::is_coliding(Bounding_box &b)
{
    if(type == BOX && b.type == BOX)
        return box_coli(b);

    if(!box_coli(b))
        return false;

    return vect_coli(b);
}

void Bounding_box::draw_box(ALLEGRO_DISPLAY * disp)
{
    if(bounding_points.size() == 1)
        Camera::get().draw_circle({bounding_points[0].first+pos.first, bounding_points[0].second+pos.second},
                              5, al_map_rgb(255,255,255));
    else
    {
        for(int i=0; i<bounding_points.size(); i++)
        {
            Camera::get().draw_line({bounding_points[i].first+pos.first, bounding_points[i].second+pos.second},
                         {bounding_points[(i+1)%bounding_points.size()].first+pos.first,
                         bounding_points[(i+1)%bounding_points.size()].second+pos.second},
                         al_map_rgb(255,255,255), 1);
        }
    }
}

void Bounding_box::clear_points()
{
    bounding_points.clear();
}

void Bounding_box::new_point(std::pair <int,int> point)
{
    bounding_points.push_back(point);
}
