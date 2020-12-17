#pragma once

/**
 @file
 @brief Заголовочный файл, содержащий объявление интерфейса для
 стандартизированной инкапсуляции.
 */

#include <iostream>
#include <memory>

template <class T> struct interface {
  /*!
 Инкапсулирует указатель на T класс.
 @param pointer Указатель на класс.
 */
  void setPointer(T pointer) { mPointer = pointer; }
  T mPointer;
};

struct IController;
struct IModel;
struct IView;
using IViewPtr = std::shared_ptr<IView>;
using IModelPtr = std::shared_ptr<IModel>;
using IControllerPtr = std::shared_ptr<IController>;
