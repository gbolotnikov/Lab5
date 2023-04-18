#ifndef __IMODEL_HPP_
#define __IMODEL_HPP_

#include <string>
#include <memory>
#include "IPage.hpp"

class ModelSubscriber {
public:
    virtual ~ModelSubscriber() = default;
    virtual void update(std::pair<size_t, const IPageData*> pageData) const = 0;
};

class IModel {
public: 
    virtual void fopen(std::string_view path) = 0;
    virtual void fcreate(std::string_view name) = 0;
    virtual void fsave(size_t pageId, std::string_view path) = 0;
    virtual void subscribe(const std::shared_ptr<ModelSubscriber>& sub) = 0;
    virtual void createSquare(size_t pageId, std::pair<size_t, size_t> coordinate, size_t params) = 0;
    virtual void createСircle(size_t pageId, std::pair<size_t, size_t> coordinate, size_t params) = 0;
    virtual void createTriangle(size_t pageId, std::pair<size_t, size_t> coordinate, size_t sizeA, size_t sizeB, size_t sizeC) = 0;
    virtual void removeShape(size_t pageId, std::pair<size_t, size_t> coordinate) = 0;
};

#endif