//
// Created by 16102 on 30.09.2026.
//

#ifndef ASSIGNMENT01_SHAPE_H
#define ASSIGNMENT01_SHAPE_H
#include <string>

#include "Board.h"


class Shape {
protected:
    int id;
    int x;
    int y;
    int z;
    std::string color;
    bool filled;
    Board* board;
    public:
    void draw(Board* board);
    void edit_filled(bool filled);
    void move(int new_x, int new_y);
    void set_color(std::string color);
    int get_ID();
    int get_x();
    int get_y();
};


#endif //ASSIGNMENT01_SHAPE_H
