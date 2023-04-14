#ifndef __IPAGE_HPP_
#define __IPAGE_HPP_

#include <map>
#include <string>
#include <memory>
#include <iostream>

enum class ShapeType {
    Square,
    Сircle,
    Triangle
};
std::ostream& operator<<(std::ostream& os, ShapeType shape);


class IShape {
public:
    ~IShape() = default;
    virtual void draw() = 0;
};

class IPageData {
public:
    using Shapes = std::map<std::pair<std::pair<size_t, size_t>, ShapeType>, std::unique_ptr<IShape>>; 
    ~IPageData() = default;
    virtual const Shapes& data() const = 0;
    virtual std::string name() const = 0;
};

class IPage: public IPageData {
public:    
    ~IPage() = default;
    void virtual create(ShapeType shape, std::pair<size_t, size_t> coordinate) = 0;
    void virtual remove(ShapeType shape, std::pair<size_t, size_t> coordinate) = 0;
    bool virtual readFrom(const std::string_view& path) = 0;
    void virtual writeTo(const std::string_view& path) = 0;
};


#endif