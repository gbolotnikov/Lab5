#include "graphics_controller.hpp"

void Controller::update(std::pair<size_t, const IPageData*> pageData) const {
    checkAndCall(_view, &IView::update, pageData);
}
void Controller::create(std::string_view path) const {
    checkAndCall(_model, &IModel::fcreate, path);
}
void Controller::inportFrom(std::string_view name) const {
    checkAndCall(_model, &IModel::fopen, name);
}
void Controller::exportTo(size_t pageId, std::string_view path) const {
    checkAndCall(_model, &IModel::fsave, pageId, path);
}
void Controller::createShape(size_t pageId, ShapeType shape, std::pair<size_t, size_t> coordinate) const {
    checkAndCall(_model, &IModel::createShape, pageId, shape, coordinate);
}
void Controller::removeShape(size_t pageId, ShapeType shape, std::pair<size_t, size_t> coordinate) const {
    checkAndCall(_model, &IModel::removeShape, pageId, shape, coordinate);
}
