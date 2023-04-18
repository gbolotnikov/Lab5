#include <iostream>
#include "graphics_page.hpp"
#include "graphics_shapes.hpp"

Page::Page(std::string_view name):
    _name(name)
{

}

std::string Page::name() const {
    return _name;
}

const Page::Shapes& Page::data() const {
    return _shapes;
}

void Page::createSquare(std::pair<size_t, size_t> coordinate, size_t params) {
    auto pair = std::make_pair(coordinate, std::make_unique<Square>(params));
    _shapes.insert(std::move(pair));
}

void Page::createСircle(std::pair<size_t, size_t> coordinate, size_t params) {
    auto pair = std::make_pair(coordinate, std::make_unique<Сircle>(params));
    _shapes.insert(std::move(pair));
}

void Page::createTriangle(std::pair<size_t, size_t> coordinate, size_t sizeA, size_t sizeB, size_t sizeC) {
    auto pair = std::make_pair(coordinate, std::make_unique<Triangle>(sizeA, sizeB, sizeC));
    _shapes.insert(std::move(pair));
}

void Page::remove(std::pair<size_t, size_t> coordinate) {
    auto sh = _shapes.find(coordinate);
    if (sh != _shapes.end()) {
        _shapes.erase(sh);
    }
}

bool Page::readFrom(const std::string_view& path) {
    return true;
}

void Page::writeTo(const std::string_view& path) {
    
}
