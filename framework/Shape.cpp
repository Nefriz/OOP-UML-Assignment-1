//
// Created by 16102 on 30.09.2026.
//

#include "Shape.h"

void Shape::set_color(std::string color) {
    this->color = color;
};
int Shape::get_id() {return this->id;}
int Shape::get_x() {return this->x;}
int Shape::get_y() {return this->y;}

void Shape::move(int new_x, int new_y, int new_z) {this->x = new_x;this->y = new_y;this->z = new_z;}

void Shape::edit_filled(bool filled) {this->filled = filled;}

void Shape::set_id(int id){ this->id = id;}
std::string Shape::get_type() {
    return this->type;
}

std::string Shape::get_color() {
    return this->color;
}
