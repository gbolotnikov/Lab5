#include "graphics_controller.hpp"

void Controller::update(const IPageData* pageData) const {
    checkAndCall(_view, &IView::update, pageData);
}
void Controller::create(std::string_view path) const {
    checkAndCall(_model, &IModel::fcreate, path);
}
void Controller::inportFrom(std::string_view name) const {
    checkAndCall(_model, &IModel::fopen, name);
}

IPage* Controller::page(std::string_view name) {
    auto ptr = _model.lock();
    if (ptr) {
        return ptr->page(name);
    }
    return nullptr;
}