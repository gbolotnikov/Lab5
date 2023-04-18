#ifndef __GRAPHICS_SHAPES_HPP_
#define __GRAPHICS_SHAPES_HPP_

#include <memory>
#include <iostream>
#include "interfaces/IPage.hpp"

class Square : public IShape {
public:
    Square(size_t params) 
    {
        std::cout << "Создаю квадрат" << std::endl;
    }
    ~Square()
    {
        std::cout << "Удаляю квадрат" << std::endl;
    }
    void draw() override;
};

class Сircle : public IShape {
public:
    Сircle(size_t params)
    {
        std::cout << "Создаю круг" << std::endl;
    }
    ~Сircle()
    {
        std::cout << "Удаляю круг" << std::endl;
    }
    void draw() override;
};

class Triangle : public IShape {
public:
    Triangle(size_t sizeA, size_t sizeB, size_t sizeC)
    {
        std::cout << "Создаю треугольник" << std::endl;
    }
    ~Triangle()
    {
        std::cout << "Удаляю треугольник" << std::endl;
    }
    void draw() override;
};


#endif