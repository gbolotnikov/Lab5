#include <iostream>
#include "graphics_shapes.hpp"

void Square::draw() {
    std::cout << "Рисую квадрат" << std::endl; 
}

void Сircle::draw() {
    std::cout << "Рисую круг" << std::endl; 
}

void Triangle::draw() {
    std::cout << "Рисую треугольник" << std::endl; 
}

std::unique_ptr<IShape> ShapeFactory::createShape(ShapeType type) {
    switch (type) {
        case ShapeType::Square:
            return std::make_unique<Square>();
        case ShapeType::Сircle:
            return std::make_unique<Сircle>();
        case ShapeType::Triangle:
            return std::make_unique<Triangle>();
    }
    return nullptr;
}