//
// Created by 16102 on 01.10.2026.
//

#include "Circle.h"
#include "../framework/Board.h"
Circle::Circle(int radius, int x, int y,int z, bool filled, Board* board,std::string color)
{
    this->radius = radius;
    this->x = x;
    this->y = y;
    this->z = z;
    if (filled >= 1) {this->filled = true;} else {this->filled = false;}
    this->color = color;
    this->board = board;
    this->type = "Circle";
};
void Circle::draw(Board* board) {
    int N = 2 * this->radius + 1;

    int outer_radius = this->radius * this->radius;
    int inner_radius = (this->radius - 1) * (this->radius - 1);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {

            int dx = i - this->radius;
            int dy = j - this->radius;

            int distance = dx * dx + dy * dy;

            if (distance <= outer_radius) {

                if (!filled) {
                    if (distance >= inner_radius) {
                        board->set_pixel(
                            x + i - radius,
                            y + j - radius,
                            this->color,
                            this->z,
                            "C",
                            this->id
                        );
                    }
                }
                else {
                    board->set_pixel(
                        x + i - radius,
                        y + j - radius,
                        this->color,
                        this->z,
                        "C",
                        this->id
                    );
                }
            }
        }
    }
}
bool Circle::edit(const std::vector<int>& params) {
    if (params.size() != 1) {return false;}
    this->radius = params[0];
    return true;
}