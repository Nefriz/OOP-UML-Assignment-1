//
// Created by 16102 on 30.09.2026.
//
#include "Pixel.h"
#include "Board.h"
#include "Shape.h"
#include <iostream>
#include <ostream>
#include <vector>

using namespace std;

Board::Board(int width, int height) {
    this->width = width;
    this->height = height;
    this->object_count = 0;
    for (int y = 0; y < height; y++) {

        std::vector<Pixel> row;

        for (int x = 0; x < width; x++) {
            row.push_back(Pixel(-1));
        }

        board.push_back(row);
    }
}
void Board::clear() {
    object_list.clear();
    object_count = 0;
    selected_object = nullptr;

    for (auto& row : board) {
        for (auto& pixel : row) {
            pixel.clear();
        }
    }

    std::cout << "Clear" << std::endl;
}

void Board::set_pixel(int x, int y, std::string color, int depth, std::string symbol, int object_id) {

    if (x >= width || x < 0 || y >= height || y < 0) {
        return;
    }

    Pixel& current_pixel = board[y][x];


    current_pixel.set_color(color, depth);
    current_pixel.set_symbol(color, depth);
    current_pixel.set_obj_id(object_id, depth);
}
void Board::set_ratio(int new_ratio) {this->pixel_ratio = new_ratio;}

void Board::draw() {
    clear_buffer();
    for (Shape* shape : object_list) {
        shape->draw(this);
    }
    for (int i = 0; i < width; i++) {
        std::cout << "-";
    }
    std::cout << std::endl;
    for (int y = 0; y < height; y++) {
        for (Pixel& pixel : board[y]) {
            pixel.draw();
            pixel.draw();
        }
        std::cout << '\n';
    }
    for (int i = 0; i < width; i++) {
        std::cout << "-";
    }
    std::cout << std::endl;
}

void Board::add_object(Shape* object) {
    object_list.push_back(object);
    object_count++;
    object->set_id(object_count);
}
void Board::reshuffle_id() {
    for (int i = 1; i <= object_count; i++) {
        object_list[i]->set_id(i);
    }
}

void Board::remove_object() {
    if (selected_object == nullptr) {
        std::cout << "No object selected" << std::endl;
        return;
    }

    int id = selected_object->get_id();
    for (int i = 0; i < object_list.size(); i++) {
        if (object_list[i]->get_id() == id) {
            delete object_list[i];
            object_list.erase(object_list.begin() + i);
            selected_object = nullptr;
            object_count = object_list.size();
            reshuffle_id();
            std::cout << "Object removed" << std::endl;
            return;
        }
    }
}

void Board::show_list() {
    if (object_count == 0) {
        std::cout << "There is no objects" << std::endl;
    } else {
        for (Shape* object : object_list) {
            std::cout <<object->get_color() << " " << object->get_type() << " "<< object->get_id() << '\n';
        }
    }
}

void Board::select_object(int x, int y) {
    int id = this->board[y][x].get_obj_id();
    if (id == -1) {
        std::cout << "No object selected" << std::endl;
        return;
    }
    this->selected_object = object_list[id - 1];
    std::cout << "Selected object: " << id << std::endl;
}

void Board::select_object_id(int id) {
    if (object_count == 0) { std::cout << "There are no objects" << std::endl; this->selected_object = nullptr; }
    if (id > object_count || id <= 0) {std::cout <<"vrong id"<< id << std::endl; this->selected_object = object_list[0];};
    this->selected_object = object_list[id - 1];
    std::cout << "Selected object: " << id << std::endl;
}
void Board::paint(std::string color) {
    if (selected_object == nullptr) {
        std::cout << "No object selected" << std::endl;
        return;
    }
    selected_object->set_color(color);
}

void Board::clear_buffer() {
    for (auto& row : board) {
        for (auto& pixel : row) {
            pixel.clear();
        }
    }
}

void Board::move(int x, int y, int z) {
    selected_object->move(x, y, z);
}

void Board::shapes() {
    std::cout << "triangle height filled x y z color" << "\n"
              << "circle radius filled x y z color" << "\n"
              << "square height width filled x y z color"<< std::endl;

}

void Board::edit(const std::vector<int> &params) {
    if (selected_object == nullptr) {
        std::cout << "No object selected" << std::endl; return;
    }
    if (selected_object->edit(params)) {
        std::cout << "Object Edited" << std::endl;
        return;
    } else {
        std::cout << "Edit failed" << std::endl;
        return;
    }
}
