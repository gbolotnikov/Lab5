#include <algorithm>
#include "graphics_view.hpp"

// по-хорошему нужна еще одна абстракция форма, но пока так
// и View - должен хранить массив форм

void View::subscribe(std::shared_ptr<ViewSubscriber> sub) {
    _subscriber = sub;
}

void View::update(std::pair<size_t, const IPageData*> pageData) {
    if (pageData.second) {
        auto result1 = std::find(_pageId.begin(), _pageId.end(), pageData.first);
        if (result1 != _pageId.end()) {
            std::cout << "Вытаскиваю форму по Id " << *result1 << std::endl;
            draw(*pageData.second);
        } else {
            _pageId.push_back(pageData.first);
            std::cout << "Создаю форму " << pageData.second->name() << std::endl;
            std::cout << "Сохраняю его Id " << pageData.first << std::endl;
            draw(*pageData.second);
        }
    }
}

void View::draw(const IPageData& page) {
    std::cout << "Обновляю форму " << page.name() << std::endl;
    std::cout << "Рисую фигуры:" << std::endl;
    for (const auto& data: page.data()) {
        data.second->draw();
    }
}

void View::onCreateClick(std::string_view name) {
    std::cout << "Создание документа с именем "<< name << std::endl;
    auto ptr = _subscriber.lock();
    if (ptr) {
        ptr->create(name);
    }
}

void View::onInportClick(std::string_view path) {
    std::cout << "Импорт документа из "<< path << std::endl;
    auto ptr = _subscriber.lock();
    if (ptr) {
        ptr->inportFrom(path);
    }
}

void View::onExportClick(std::string_view path) {
    std::cout << "Экспорт документа в "<< path << std::endl;
    // берем всегда первый документ, хз как сделать выбор в тесте
    auto pageId = _pageId[0];
    std::cout << "Получаем id документа "<< pageId << std::endl;
    auto ptr = _subscriber.lock();
    if (ptr) {
        ptr->exportTo(pageId, path);
    }
}


void View::createSquare(std::pair<size_t, size_t> coordinate, size_t width) {
    auto pageId = _pageId[0];
    auto ptr = _subscriber.lock();
    if (ptr) {
        ptr->createSquare(pageId, coordinate, width);
    }
}

void View::createСircle(std::pair<size_t, size_t> coordinate, size_t radius) {
    auto pageId = _pageId[0];
    auto ptr = _subscriber.lock();
    if (ptr) {
        ptr->createСircle(pageId, coordinate, radius);
    }
}

void View::createTriangle(std::pair<size_t, size_t> coordinate, size_t sizeA, size_t sizeB, size_t sizeC) {
    auto pageId = _pageId[0];
    auto ptr = _subscriber.lock();
    if (ptr) {
        ptr->createTriangle(pageId, coordinate, sizeA, sizeB, sizeC);
    }
}

void View::removeShape(std::pair<size_t, size_t> coordinate) {
    auto pageId = _pageId[0];
    auto ptr = _subscriber.lock();
    if (ptr) {
        ptr->removeShape(pageId, coordinate);
    }
}


