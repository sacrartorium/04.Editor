#pragma once

/**
 @file
 @brief Заголовочный файл, содержащий объявления модели и вида для векторного
 объекта.
 */

#include "interface/icontroller.hpp"
#include "interface/imodel.hpp"
#include "interface/iview.hpp"

/**
 Модель данных для векторного объекта.
*/
struct MVectoralObject : public IModel,
                         public std::enable_shared_from_this<MVectoralObject> {
  MVectoralObject();
  ~MVectoralObject();

  void changeColor(const std::string &newColor);
};
using MVectoralObjectPtr = std::shared_ptr<MVectoralObject>;

/**
 Пользовательский интерфейс для векторного объекта.
*/
struct VVectoralObject : public IView,
                         public std::enable_shared_from_this<VVectoralObject> {

  void clear() const override;
  void draw() const override;
  void update(const std::string &message) override;
};
using VVectoralObjectPtr = std::shared_ptr<VVectoralObject>;
