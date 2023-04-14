#include "graphics_page.hpp"
#include "graphics_shapes.hpp"

std::ostream& operator<<(std::ostream& os, ShapeType shape) {
    switch(shape) {
        case ShapeType::Square:
            os << "Квадрат";
            break;
        case ShapeType::Сircle:
            os << "Круг";
            break;
        case ShapeType::Triangle:
            os << "Треугольник";
            break;    
        default:
            os << "Неизвестно";
            break;
    }
    return os;
}

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

void Page::create(ShapeType shape, std::pair<size_t, size_t> coordinate) {
    auto pair = std::make_pair(std::make_pair(coordinate, shape), ShapeFactory::createShape(shape));
    _shapes.insert(std::move(pair));
}

void Page::remove(ShapeType shape, std::pair<size_t, size_t> coordinate) {
    auto pairKey = std::make_pair(coordinate, shape);
    auto sh = _shapes.find(pairKey);
    if (sh != _shapes.end()) {
        _shapes.erase(sh);
    }
}

bool Page::readFrom(const std::string_view& path) {
    return true;
}

void Page::writeTo(const std::string_view& path) {
    
}
