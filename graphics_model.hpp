#ifndef __GRAPHICS_MODEL_HPP_
#define __GRAPHICS_MODEL_HPP_

#include <map>
#include "graphics_page.hpp"
#include "interfaces/IModel.hpp"

class Model : public IModel, public std::enable_shared_from_this<Model> {
private:
    size_t pageId = {0};
    std::weak_ptr<ModelSubscriber> _subscriber;
    std::map<size_t, std::unique_ptr<IPage>> _pages;   
public:

    void fcreate(std::string_view name) override;

    void fopen(std::string_view path) override;

    void fsave(size_t pageId, const std::string_view path) override;

    void subscribe(const std::shared_ptr<ModelSubscriber>& sub) override;

    void createShape(size_t pageId, ShapeType shape, std::pair<size_t, size_t> coordinate) override;

    void removeShape(size_t pageId, ShapeType shape, std::pair<size_t, size_t> coordinate) override;

    static std::shared_ptr<Model> create() {
        auto ptr = std::shared_ptr<Model>(new Model);
        return ptr;
    }

private:
    Model() = default;

    void notify(std::pair<size_t, const IPageData*>);

    bool isExist(std::string_view path);

    bool isValid(std::string_view path);

    std::string fileName(std::string_view path);
};

#endif