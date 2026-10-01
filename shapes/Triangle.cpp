//
// Created by 16102 on 30.09.2026.
//

#include "Triangle.h"
#include "../framework/Board.h"

Triangle::Triangle(int height, bool filled, int x, int y, Board* board, int z, std::string color) {
    this->height = height;
    this->x = x;
    this->y = y;
    this->z = z;
    this->filled = filled;
    this->color = color;
    this->board = board;
}

void Triangle::draw(Board* board) {
    for (int row = 0; row < height; row++) {
        int left_x = x - row;
        int right_x = x + row;
        if (this->filled) {
            for (int change = 0 ; change <= row * 2 + 1; change++) {
                board->set_pixel(left_x + change, row + y, this->color, this->z);
            }
        }
        else {
                board->set_pixel(left_x,row + y, this->color, this->z);
                board->set_pixel(right_x,row + y, this->color, this->z);

        }
    }
}
