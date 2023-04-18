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
    virtual ~IShape() = default;
    virtual void draw() = 0;
};

class IPageData {
public:
    using Shapes = std::map<std::pair<size_t, size_t>, std::unique_ptr<IShape>>; 
    virtual ~IPageData() = default;
    virtual const Shapes& data() const = 0;
    virtual std::string name() const = 0;
};

class IPage: public IPageData {
public:    
    virtual ~IPage() = default;
    void virtual createSquare(std::pair<size_t, size_t> coordinate, size_t params) = 0;
    void virtual createСircle(std::pair<size_t, size_t> coordinate, size_t params) = 0;
    void virtual createTriangle(std::pair<size_t, size_t> coordinate, size_t sizeA, size_t sizeB, size_t sizeC) = 0;

    void virtual remove(std::pair<size_t, size_t> coordinate) = 0;
    bool virtual readFrom(const std::string_view& path) = 0;
    void virtual writeTo(const std::string_view& path) = 0;
};


#endif