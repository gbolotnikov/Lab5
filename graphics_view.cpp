#include <algorithm>
#include "graphics_view.hpp"

// по-хорошему нужна еще одна абстракция форма, но пока так
// и View - должен хранить массив форм

void View::subscribe(std::shared_ptr<ViewSubscriber> sub) {
    _subscriber = sub;
}

void View::update(const IPageData* pageData) {
    if (pageData) {
        std::cout << "Обновляю форму " << pageData->name() << std::endl;
        std::cout << "Рисую фигуры:" << std::endl;
        for (const auto& data: pageData->data()) {
            data.second->draw();
        }
    }
}

void View::onCreateClick(std::string_view name) {
    auto ptr = _subscriber.lock();
    if (ptr) {
        ptr->create(name);
    }
}

void View::onInportClick(std::string_view path) {
    auto ptr = _subscriber.lock();
    if (ptr) {
        ptr->inportFrom(path);
    }
}

void View::onExportClick(std::string_view name, std::string_view path) {
    auto ptr = _subscriber.lock();
    if (ptr) {
        auto page = ptr->page(name);
        if (page) {
            page->save(path);
        }
    }
}


void View::createSquare(std::string_view name, std::pair<size_t, size_t> coordinate, size_t width) {
    auto ptr = _subscriber.lock();
    if (ptr) {
        auto page = ptr->page(name);
        if (page) {
            page->createSquare(coordinate, width);
        }
    }
}

void View::createСircle(std::string_view name, std::pair<size_t, size_t> coordinate, size_t radius) {
    auto ptr = _subscriber.lock();
    if (ptr) {
        auto page = ptr->page(name);
        if (page) {
            page->createСircle(coordinate, radius);
        }
    }
}

void View::createTriangle(std::string_view name, std::pair<size_t, size_t> coordinate, size_t sizeA, size_t sizeB, size_t sizeC) {
    auto ptr = _subscriber.lock();
    if (ptr) {
        auto page = ptr->page(name);
        if (page) {
            page->createTriangle(coordinate, sizeA, sizeB, sizeC);
        }
    }
}

void View::removeShape(std::string_view name, std::pair<size_t, size_t> coordinate) {
    auto ptr = _subscriber.lock();
    if (ptr) {
        auto page = ptr->page(name);
        if (page) {
            page->remove(coordinate);
        }
    }
}


