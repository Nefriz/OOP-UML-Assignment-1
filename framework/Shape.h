//
// Created by 16102 on 30.09.2026.
//

#ifndef ASSIGNMENT01_SHAPE_H
#define ASSIGNMENT01_SHAPE_H
#include <string>
#include <vector>

class Board;

class Shape {
protected:
    int id;
    int x;
    int y;
    int z;
    std::string color;
    bool filled;
    Board* board;
    std::string type;
    public:
    virtual bool edit(const std::vector<int>& params) = 0;
    virtual void draw(Board* board) = 0;;
    void edit_filled(bool filled);
    void move(int new_x, int new_y, int new_z);
    void set_color(std::string color);
    int get_id();
    int get_x();
    int get_y();
    void set_id(int id);
    std::string get_type();
    std::string get_color();
};


#endif //ASSIGNMENT01_SHAPE_H
