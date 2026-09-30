//
// Created by 16102 on 30.09.2026.
//
#include "Pixel.h"
#include "Board.h"
#include <vector>

using namespace std;
void Board::clear() {
    for (vector<Pixel> row : board) {
        for (Pixel pixel : row) {
            pixel.set_symbol(' ');
            pixel.set_color("\033[0m");
        }
    }
}

void Board::set_ratio(int new_ratio) {this->pixel_ratio = new_ratio;}

void Board::draw() {
    //TODO
}

