#include "graphics_view.hpp"
#include "graphics_model.hpp"
#include "graphics_controller.hpp"

extern View view;
extern Model model;
extern Controller controller;

int main() {
    // View view(controller);
    auto view = View::create();
    auto model = Model::create();
    auto controller = Controller::create(view, model);
    view->subscribe(controller);
    model->subscribe(controller);
    // тесты
    std::cout << "=====Teст на создание файла=====" << std::endl;
    view->onCreateClick("Test1");
    std::cout << "=====Teст на сохранение файла=====" << std::endl;
    view->onExportClick("Path/");
    std::cout << "=====Teст на открытие файла=====" << std::endl;
    view->onInportClick("Path/Test2");
    std::cout << "=====Teст на создание фигуры=====" << std::endl;
    view->createShape(ShapeType::Square, std::make_pair(0, 0));
    std::cout << "=====Teст на удаление фигуры=====" << std::endl;
    view->removeShape(ShapeType::Square, std::make_pair(0, 0));
    return 0;
}