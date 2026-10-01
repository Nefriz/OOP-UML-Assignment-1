//
// Created by 16102 on 30.09.2026.
//

#ifndef ASSIGNMENT01_BOARD_H
#define ASSIGNMENT01_BOARD_H
#include <vector>
#include "Pixel.h"

class Board {
protected:
    std::vector<std::vector<Pixel>> board;
    int width, height;
    int pixel_ratio;
    public:
    Board(int width, int height, int pixel_ratio);
    void clear();
    void draw();
    void set_ratio(int new_ratio);
    void set_pixel(int x, int y, std::string color, int depth);
};


#endif //ASSIGNMENT01_BOARD_H
