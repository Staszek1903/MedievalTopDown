#ifndef BOUNDING_BOX_H
#define BOUNDING_BOX_H

#include <utility>
#include <iostream>

class Bounding_box
{
    int type,
        size;

    bool square_coli(Bounding_box &b);
    bool diamond_coli(Bounding_box &b);
    bool square_to_diamond_coli(Bounding_box &b);

public:
    int up, down, left, right;

    enum
    {
        SQUARE,
        DIAMOND
    };

    Bounding_box();
    ~Bounding_box();

    void load_content(std::pair <int, int> pos, int size, int type);
    void update(std::pair <int, int> pos);
    int get_type();
    bool is_coliding(Bounding_box &b);

};

#endif // BOUNDING_BOX_H
