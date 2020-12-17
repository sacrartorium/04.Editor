#pragma once

/**
 @file
 @brief Заголовочный файл, содержащий объявление контроллера.
 */

#include "imodel.hpp"
#include "interface.hpp"

/**
 Базовый интерфейс для контроллера.
 */
struct IController {

  virtual ~IController() = default;
  virtual void send(IModelPtr pointer, std::string message) = 0;
};
