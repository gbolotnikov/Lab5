#ifndef __IMODEL_HPP_
#define __IMODEL_HPP_

#include <string>
#include <memory>
#include "IPage.hpp"

class ModelSubscriber {
public:
    virtual ~ModelSubscriber() = default;
    virtual void update(const IPageData* pageData) const = 0;
};

class IModel : public INotifier {
public: 
    virtual ~IModel() = default;
    virtual IPage* page(std::string_view name) = 0;
    virtual void fopen(std::string_view path) = 0;
    virtual void fcreate(std::string_view name) = 0;
    virtual void subscribe(const std::shared_ptr<ModelSubscriber>& sub) = 0;
};

#endif