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

bool Bounding_box::is_inside(std::vector <std::pair <int, int> > &a, std::vector <std::pair <int, int> > &b)
{
    std::pair <int, int> va,v1,v2;

    for(unsigned int i=0; i<b.size(); i++)        //sprawdzamy czy punkt w b znajduje sie w nas;
    {
        bool inside = true;
        for(unsigned int j=0; j<a.size(); j++)
        {
            va = a[j];
            v2 = b[i];
            if(i == a.size())
                v1 = a[0];
            else
                v1 = a[j+1];

            if(cross_product(va,v1,v2) < 0)
                {inside = false; break;}
        }
        if(inside)
            return true;
    }

    return false;
}

void Bounding_box::make_real_points(std::vector <std::pair <int, int> > &v)
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
    std::vector <std::pair <int, int> > mpoints, bpoints;
    make_real_points(mpoints);
    b.get_real_points(bpoints);

    if(is_inside(mpoints, bpoints) || is_inside(bpoints, mpoints))
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
    if(!box_coli(b))
        return false;

    if(type == CUSTOM || b.type == CUSTOM)
        return vect_coli(b);

    return true;
}

void Bounding_box::get_real_points(std::vector <std::pair <int,int> > &v)
{
    make_real_points(v);
}

void Bounding_box::print_points()
{
    for(int i=0; i<bounding_points.size(); i++)
        std::cout<<bounding_points[i].first<<" "<<bounding_points[i].second<<std::endl;
    getch();
}
