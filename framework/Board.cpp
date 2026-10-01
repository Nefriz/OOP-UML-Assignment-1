//
// Created by 16102 on 30.09.2026.
//
#include "Pixel.h"
#include "Board.h"
#include <vector>

using namespace std;

Board::Board(int width, int height, int pixel_ratio) {
    this->width = width;
    this->height = height;
    this->pixel_ratio = pixel_ratio;
}
void Board::clear() {
    for (vector<Pixel> row : board) {
        for (Pixel pixel : row) {
            pixel.set_symbol(' ');
            pixel.set_color("\033[0m");
        }
    }
}
void Board::set_pixel(int x, int y, std::string color, int depth) {
    Pixel& current_pixel = board[y][x];


    current_pixel.set_depth(depth);
    current_pixel.set_color(color);
}
void Board::set_ratio(int new_ratio) {this->pixel_ratio = new_ratio;}

void Board::draw() {
    //TODO
}

