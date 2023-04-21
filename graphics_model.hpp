#ifndef __GRAPHICS_MODEL_HPP_
#define __GRAPHICS_MODEL_HPP_

#include <map>
#include "graphics_page.hpp"
#include "interfaces/IModel.hpp"

class Model : public IModel, public std::enable_shared_from_this<Model> {
private:
    size_t pageId = {0};
    std::weak_ptr<ModelSubscriber> _subscriber;
    std::map<std::string, std::unique_ptr<Page>> _pages; 
public:

    void fcreate(std::string_view name) override;

    void fopen(std::string_view path) override;

    void subscribe(const std::shared_ptr<ModelSubscriber>& sub) override;

    IPage* page(std::string_view name) override;

    void notify(const IPageData*) override;

    static std::shared_ptr<Model> create() {
        auto ptr = std::shared_ptr<Model>(new Model);
        return ptr;
    }

private:
    Model() = default;

    bool isExist(std::string_view path);

    bool isValid(std::string_view path);

    std::string fileName(std::string_view path);
};

#endif