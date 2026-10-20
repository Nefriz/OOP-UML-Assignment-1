//
// Created by 16102 on 30.09.2026.
//

#ifndef ASSIGNMENT01_BOARD_H
#define ASSIGNMENT01_BOARD_H
#include <vector>
#include "../framework/Pixel.h"


class Shape;

class Board {
protected:
    std::vector<std::vector<Pixel>> board;
    std::vector<Shape*> object_list;
    Shape* selected_object;
    int width, height = 0;
    int pixel_ratio;
    int object_count;
    void reshuffle_id();
    void clear_buffer();
public:
    Board(int width, int height);
    bool edit(const std::vector<int>& params);
    void clear();
    void draw();
    void set_ratio(int new_ratio);
    void set_pixel(int x, int y, std::string color, int depth, std::string symbol, int id);
    void show_list();
    void add_object(Shape* object);
    bool remove_object();
    bool select_object_id(int id);
    bool select_object(int x, int y);
    bool paint(std::string color);
    bool move(int x, int y, int z);
    void shapes();
    bool is_inside(int x, int y);
};


#endif //ASSIGNMENT01_BOARD_H
