#ifndef __IVIEW_HPP_
#define __IVIEW_HPP_

#include <memory>
#include <string>
#include "IPage.hpp"

class ViewSubscriber {
public:
    virtual ~ViewSubscriber() = default;
    virtual IPage* page(std::string_view name) = 0;
    virtual void create(std::string_view name) const = 0;
    virtual void inportFrom(std::string_view name) const = 0;
};

class IView {
public:
    virtual ~IView() = default;
    virtual void update(const IPageData* pageData) = 0;
    virtual void subscribe(std::shared_ptr<ViewSubscriber> sub) = 0;
};

#endif