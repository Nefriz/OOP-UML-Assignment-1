//
// Created by 16102 on 30.09.2026.
//

#include "Shape.h"

void Shape::set_color(std::string color) {
    this->color = color;
};
int Shape::get_ID() {return this->id;}
int Shape::get_x() {return this->x;}
int Shape::get_y() {return this->y;}

void Shape::move(int new_x, int new_y) {this->x = new_x;this->y = new_y;}

void Shape::edit_filled(bool filled) {this->filled = filled;}
