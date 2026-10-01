//
// Created by 16102 on 30.09.2026.
//
#include "Pixel.h"
#include "Board.h"

#include <iostream>
#include <ostream>
#include <vector>

using namespace std;

Board::Board(int width, int height, int pixel_ratio) {
    this->width = width;
    this->height = height;
    this->pixel_ratio = pixel_ratio;

    for (int y = 0; y < height; y++) {

        std::vector<Pixel> row;

        for (int x = 0; x < width; x++) {
            row.push_back(Pixel(-1));
        }

        board.push_back(row);
    }
}
void Board::clear() {
    for (vector<Pixel> row : board) {
        for (Pixel pixel : row) {
            pixel.set_symbol(" ", -1);
            pixel.set_color("\033[0m", -1);
        }
    }
}
void Board::set_pixel(int x, int y, std::string color, int depth, std::string symbol) {

    if (x >= width || x < 0 || y >= height || y < 0) {
        return;
    }

    Pixel& current_pixel = board[y][x];


    current_pixel.set_color(color, depth);
    current_pixel.set_symbol(symbol, depth);
}
void Board::set_ratio(int new_ratio) {this->pixel_ratio = new_ratio;}

void Board::draw() {
    for (int y = 0; y < height; y++) {

        for (Pixel& pixel : board[y]) {
            pixel.draw();
            pixel.draw();
        }

        std::cout << '\n';
    }
}

