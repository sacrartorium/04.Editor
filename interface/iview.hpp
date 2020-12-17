#pragma once

/**
 @file
 @brief Заголовочный файл, содержащий объявление представления.
 редактором.
 */

#include "../publisher_subscriber.hpp"
#include "imodel.hpp"
#include "interface.hpp"

/**
 Базовый интерфейс для представления. Инкапсулирует указатель на модель данных.
 */
struct IView : public interface<IModelPtr>, public ISubscriber {
  virtual ~IView() = default;
  virtual void clear() const = 0;
  virtual void draw() const = 0;
};
