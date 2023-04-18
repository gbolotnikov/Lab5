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
void Controller::createSquare(size_t pageId, std::pair<size_t, size_t> coordinate, size_t params) const {
    checkAndCall(_model, &IModel::createSquare, pageId, coordinate, params);
}
void Controller::createСircle(size_t pageId, std::pair<size_t, size_t> coordinate, size_t params) const {
    checkAndCall(_model, &IModel::createСircle, pageId, coordinate, params);
}
void Controller::createTriangle(size_t pageId, std::pair<size_t, size_t> coordinate, size_t sizeA, size_t sizeB, size_t sizeC) const {
    checkAndCall(_model, &IModel::createTriangle, pageId, coordinate, sizeA, sizeB, sizeC);
}
void Controller::removeShape(size_t pageId, std::pair<size_t, size_t> coordinate) const {
    checkAndCall(_model, &IModel::removeShape, pageId, coordinate);
}
