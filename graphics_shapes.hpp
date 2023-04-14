#ifndef __GRAPHICS_SHAPES_HPP_
#define __GRAPHICS_SHAPES_HPP_

#include <memory>
#include "interfaces/IPage.hpp"

class Square : public IShape {
public:
    void draw() override;
};

class Сircle : public IShape {
public:
    void draw() override;
};

class Triangle : public IShape {
public:
    void draw() override;
};

class ShapeFactory {
public:
    static std::unique_ptr<IShape> createShape(ShapeType type);
};

#endif