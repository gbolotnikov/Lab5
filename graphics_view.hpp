#ifndef __GRAPHICS_VIEW_HPP_
#define __GRAPHICS_VIEW_HPP_

#include <vector>
#include <iostream>
#include "interfaces/IView.hpp"

class View : public IView, public std::enable_shared_from_this<View> {
public:
    void subscribe(std::shared_ptr<ViewSubscriber> sub) override; 
    void update(std::pair<size_t, const IPageData*> pageData) override;
    void onCreateClick(std::string_view name);
    void onInportClick(std::string_view path);
    void onExportClick(std::string_view path);
    
    void createSquare(std::pair<size_t, size_t> coordinate, size_t width);
    void createСircle(std::pair<size_t, size_t> coordinate, size_t radius);
    void createTriangle(std::pair<size_t, size_t> coordinate, size_t sizeA, size_t sizeB, size_t sizeC);


    void removeShape(std::pair<size_t, size_t> coordinate);

    static std::shared_ptr<View> create() {
        auto ptr = std::shared_ptr<View>(new View);
        return ptr;
    }

private: 
    void draw(const IPageData& page);
    View() = default;
    std::vector<size_t> _pageId;
    std::weak_ptr<ViewSubscriber> _subscriber;
};

#endif