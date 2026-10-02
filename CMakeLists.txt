cmake_minimum_required(VERSION 4.3)
project(Assignment01)

set(CMAKE_CXX_STANDARD 23)

add_executable(Assignment01 main.cpp
        framework/Shape.cpp
        framework/Shape.h
        framework/Shape.h
        framework/Board.cpp
        framework/Board.h
        framework/Pixel.cpp
        framework/Pixel.h
        shapes/Triangle.cpp
        shapes/Triangle.h
        shapes/Square.cpp
        shapes/Square.h
        shapes/Circle.cpp
        shapes/Circle.h
        framework/App.cpp
        framework/App.h)
