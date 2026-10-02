//
// Created by 16102 on 30.09.2026.
//

#include "Triangle.h"
#include "../framework/Board.h"

Triangle::Triangle(int height, bool filled, int x, int y, int z,Board* board, std::string color) {
    this->height = height;
    this->x = x;
    this->y = y;
    this->z = z;
    if (filled >= 1) {this->filled = true;} else {this->filled = false;}
    this->color = color;
    this->board = board;
    this->type = "Triangle";
}
void Triangle::draw(Board* board) {
    for (int row = 0; row < height; row++) {
        int left_x = x - row;
        int right_x = x + row;
        if (this->filled) {
            for (int change = 0; change < row * 2 + 1; change++) {
                board->set_pixel(left_x + change,row + y,this->color,this->z,"R", this->id);
            }
        } else {
            if (row == height - 1) {
                for (int change = 0; change < height * 2 - 1; change++) {
                    board->set_pixel(left_x + change,row + y,this->color,this->z,"R", this->id);
                }
            } else {
                board->set_pixel(left_x, row + y,this->color,this->z,"R", this->id);
                board->set_pixel(right_x,row + y,this->color,this->z,"R", this->id);
            }
        }
    }
}
bool Triangle::edit(const std::vector<int>& params) {
    if (params.size() != 1) {return false;}
    this->height = params[0];
    return true;
}