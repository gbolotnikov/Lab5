#include <utility>
#include "graphics_page.hpp"
#include "graphics_model.hpp"


void Model::subscribe(const std::shared_ptr<ModelSubscriber>& sub) {
    _subscriber = sub;
}

void Model::notify(const IPageData* pageData) {
    auto ptr = _subscriber.lock();
    if (ptr) {
        ptr->update(pageData);
    }
}

void Model::fcreate(std::string_view name) {
    auto [it, wasInserted] = _pages.emplace(std::make_pair(std::string(name.data()), std::make_unique<Page>(name, *this)));
    if (wasInserted) {
        notify(it->second.get());
    }
}

void Model::fopen(std::string_view path) {
    if (isExist(path)) {
        auto name = fileName(path);
        fcreate(name);
    }
}

IPage* Model::page(std::string_view name) {
    auto it = _pages.find(name.data());
    if (it != _pages.end()) {
        return it->second.get();
    }
    return nullptr;
}

bool Model::isExist(std::string_view path) {
    return true;
}   

bool Model::isValid(std::string_view path) {
    return true;
} 

std::string Model::fileName(std::string_view path) {
    auto nameStart = path.find_last_of("/\\") + 1;
    return std::string(path.data() + nameStart);
}