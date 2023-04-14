#ifndef __GRAPHICS_CONTROLLER_HPP_
#define __GRAPHICS_CONTROLLER_HPP_

#include <functional>
#include "interfaces/IView.hpp"
#include "interfaces/IModel.hpp"

class Controller : public ViewSubscriber, public ModelSubscriber {
private:
    std::weak_ptr<IView> _view;
    std::weak_ptr<IModel> _model;       

    template<typename Interface, typename ...Args, typename Func = void (Interface::*)(Args&&... args)>
    void checkAndCall(std::weak_ptr<Interface> weakPtr, Func func, Args&&... args) const {
        auto ptr = weakPtr.lock();
        if (ptr) {
            std::invoke(func, *ptr, std::forward<Args>(args)...);
        }
    }

    Controller(std::weak_ptr<IView> view, std::weak_ptr<IModel> model): 
        _view(view),
        _model(model)
    {

    }

public: 

    static std::shared_ptr<Controller> create(std::weak_ptr<IView> view, std::weak_ptr<IModel> model) {
        auto ptr = std::shared_ptr<Controller>(new Controller(view, model));
        return ptr;
    }

    void update(std::pair<size_t, const IPageData*> pageData) const override;
    void create(std::string_view path) const override;
    void inportFrom(std::string_view name) const override;
    void exportTo(size_t pageId, std::string_view path) const override;
    void createShape(size_t pageId, ShapeType shape, std::pair<size_t, size_t> coordinate) const override;
    void removeShape(size_t pageId, ShapeType shape, std::pair<size_t, size_t> coordinate) const override;


};

#endif