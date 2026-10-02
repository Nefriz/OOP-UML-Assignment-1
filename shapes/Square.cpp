//
// Created by 16102 on 01.10.2026.
//

#include "Square.h"
#include "../framework/Board.h"
Square::Square(int height, int width, int x, int y,int z, bool filled, Board* board,std::string color) {
    this->height = height;
    this->width = width;
    this->x = x;
    this->y = y;
    this->z = z;
    if (filled >= 1) {this->filled = true;} else {this->filled = false;}
    this->color = color;
    this->board = board;
    this->type = "Square";
}

void Square::draw(Board *board) {
    for (int row = 0; row < height; row++) {
        if (row == 0 || row == height - 1 || this->filled) {
            for (int column = 0; column < width; column++) {
                board->set_pixel(column + x, row + y, this->color, this->z, "Q", this->id);
            }
        } else {
            int left_x = this->x;
            int right_x = this->x + this->width - 1;
            for (int column = 1; column < height - 1; column++) {
                board->set_pixel(left_x, column + y, this->color, this->z, "Q", this->id);
                board->set_pixel(right_x, column + y, this->color, this->z, "Q", this->id);
            }
        }
    }
}
bool Square::edit(const std::vector<int>& params) {
    if (params.size() != 2) {return false;}
    this->height = params[0];
    this->width = params[1];
    return true;
}