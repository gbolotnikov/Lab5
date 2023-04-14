#include <utility>
#include "graphics_page.hpp"
#include "graphics_model.hpp"


void Model::subscribe(const std::shared_ptr<ModelSubscriber>& sub) {
    _subscriber = sub;
}

void Model::notify(std::pair<size_t, const IPageData*> pageData) {
    auto ptr = _subscriber.lock();
    if (ptr) {
        ptr->update(pageData);
    }
}

void Model::fcreate(std::string_view name) {
    auto pair = std::make_pair(++pageId, std::make_unique<Page>(name));
    _pages.insert(std::move(pair));
    notify(std::make_pair(pageId, _pages[pageId].get()));
}

void Model::fopen(std::string_view path) {
    if (isExist(path)) {
        auto pair = std::make_pair(++pageId, std::make_unique<Page>(fileName(path)));
        if (pair.second->readFrom(path)) {
            _pages.insert(std::move(pair));
            notify(std::make_pair(pageId, _pages[pageId].get()));
        }
    }
}

void Model::fsave(size_t pageId, std::string_view path) {
    if (isValid(path)) {
        auto page = _pages.find(pageId);
        if (page != _pages.end()) {
            page->second->writeTo(path);          
            notify(std::make_pair(pageId, _pages[pageId].get()));
        }
    }
}

void Model::createShape(size_t pageId, ShapeType shape, std::pair<size_t, size_t> coordinate) {
    auto page = _pages.find(pageId);
    if (page != _pages.end()) {
        page->second->create(shape, coordinate);
        notify(std::make_pair(pageId, _pages[pageId].get()));
    }
}   

void Model::removeShape(size_t pageId, ShapeType shape, std::pair<size_t, size_t> coordinate) {
    auto page = _pages.find(pageId);
    if (page != _pages.end()) {
        page->second->remove(shape, coordinate);
        notify(std::make_pair(pageId, _pages[pageId].get()));
    }
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