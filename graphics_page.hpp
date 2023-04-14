#ifndef __GRAPHICS_PAGE_HPP_
#define __GRAPHICS_PAGE_HPP_

#include <string>
#include "interfaces/IPage.hpp"


class Page: public IPage {
private:
    std::string _name;
    Shapes _shapes;
public:
    Page(std::string_view name); 
    const Shapes& data() const override;
    std::string name() const override;
    void create(ShapeType shape, std::pair<size_t, size_t> coordinate) override;
    void remove(ShapeType shape, std::pair<size_t, size_t> coordinate) override;
    bool readFrom(const std::string_view& path) override;
    void writeTo(const std::string_view& path) override;
};


#endif