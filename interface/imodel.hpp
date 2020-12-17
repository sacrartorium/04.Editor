#pragma once

/**
 @file
 @brief Заголовочный файл, содержащий объявление модели данных.
 */

#include "../src/publisher_subscriber.hpp"
#include "icontroller.hpp"
#include "interface.hpp"

/**
 Базовый интерфейс для модели данных. Инкапсулирует указатель на контроллер.
 */
struct IModel : public interface<IControllerPtr>, public IPublisher {
  virtual ~IModel() = default;
};
