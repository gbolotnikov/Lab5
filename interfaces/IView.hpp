#ifndef __IVIEW_HPP_
#define __IVIEW_HPP_

#include <memory>
#include <string>
#include "IPage.hpp"

class ViewSubscriber {
public:
    virtual ~ViewSubscriber() = default;
    virtual void create(std::string_view name) const = 0;
    virtual void inportFrom(std::string_view name) const = 0;
    virtual void exportTo(size_t pageId, std::string_view path) const = 0;
    virtual void createShape(size_t pageId, ShapeType shape, std::pair<size_t, size_t> coordinate) const = 0;
    virtual void removeShape(size_t pageId, ShapeType shape, std::pair<size_t, size_t> coordinate) const = 0;
};

class IView {
public:
    virtual ~IView() = default;
    virtual void update(std::pair<size_t, const IPageData*> pageData) = 0;
    virtual void subscribe(std::shared_ptr<ViewSubscriber> sub) = 0;
};

#endif