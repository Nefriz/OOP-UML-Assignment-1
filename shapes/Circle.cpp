//
// Created by 16102 on 01.10.2026.
//

#include "Circle.h"
Circle::Circle(int radius, int x, int y,int z, bool filled, Board* board,std::string color)
{
    this->radius = radius;
    this->x = x;
    this->y = y;
    this->z = z;
    this->filled = filled;
    this->color = color;
    this->board = board;
};
void Circle::draw(Board* board) {
    int N = 2 * this->radius + 1;
    int outer_radius = this->radius * this->radius;
    int inner_radius = (this->radius - 1) * (this->radius - 1);
    for (int i = 0; i < N; i++) { // x
        for (int j = 0; j < N; j++) { // y
            int dx = i - this->radius;
            int dy = j - this->radius;
            int distance = dx *dx + dy *dy;
            if (distance <= outer_radius) {
                if (!filled) {
                    if  (distance >= inner_radius && distance <= outer_radius) {
                        board->set_pixel(x + i, y + j, this->color, this->z, "C" );
                    }
                } else {
                    board->set_pixel(x + i, y + j, this->color, this->z, "C" );
                }
            }
        }
    }
};