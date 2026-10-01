//
// Created by 16102 on 01.10.2026.
//

#include "Square.h"

Square::Square(int height, int width, int x, int y,int z, bool filled, Board* board,std::string color) {
    this->height = height;
    this->width = width;
    this->x = x;
    this->y = y;
    this->z = z;
    this->filled = filled;
    this->color = color;
    this->board = board;
}

void Square::draw(Board *board) {
    for (int row = 0; row < height; row++) {
        if (row == 0 || row == height - 1 || this->filled) {
            for (int column = 0; column < width; column++) {
                board->set_pixel(column + x, row + y, this->color, this->z, "Q");
            }
        } else {
            int left_x = this->x;
            int right_x = this->x + this->width - 1;
            for (int column = 1; column < height - 1; column++) {
                board->set_pixel(left_x, column + y, this->color, this->z, "Q");
                board->set_pixel(right_x, column + y, this->color, this->z, "Q");
            }
        }
    }
}
