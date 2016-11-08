#include "bounding_box.h"

Bounding_box::Bounding_box()
{
    //ctor
}

Bounding_box::~Bounding_box()
{
    //dtor
}

bool Bounding_box::square_coli(Bounding_box &b)
{
    if(up < b.down && b.up < down && left < b.right && b.left < right)
        return true;
    return false;
}

bool Bounding_box::diamond_coli(Bounding_box &b)
{
    return false;
}

bool Bounding_box::square_to_diamond_coli(Bounding_box &b)
{
    return false;
}

void Bounding_box::load_content(std::pair <int, int> pos, int size, int type)
{
    this->size = size;
    this->type = type;
    up = pos.second - (size/2);
    down = pos.second + (size/2);
    left = pos.first - (size/2);
    right = pos.first + (size/2);
}

void Bounding_box::update(std::pair <int, int> pos)
{
    up = pos.second - (size/2);
    down = pos.second + (size/2);
    left = pos.first - (size/2);
    right = pos.first + (size/2);
}

int Bounding_box::get_type()
{
    return type;
}

bool Bounding_box::is_coliding(Bounding_box &b)
{

    if((type == SQUARE) && b.get_type() == SQUARE )
        return square_coli(b);
    if((type == DIAMOND)&&(b.get_type() == DIAMOND))
        return diamond_coli(b);
}
