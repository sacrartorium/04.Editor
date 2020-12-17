#pragma once

/**
 @file
 @brief Заголовочный файл, содержащий объявления паттерна Издатель\Подписчик.
 */

#include <memory>
#include <string>
#include <unordered_set>

#include "logger.hpp"

/**
 Класс подписчика.
*/
struct ISubscriber {
  virtual ~ISubscriber() = default;
  virtual void update(const std::string &) = 0;
};
using ISubscriberPtr = std::shared_ptr<ISubscriber>;

/**
 Класс издателя.
*/
struct IPublisher {
  void add(ISubscriberPtr pointer);
  void sendForAll(const std::string &message) const;
  void remove(ISubscriberPtr pointer);

protected:
  std::unordered_set<ISubscriberPtr> mSubscribers;
};
using IPublisherPtr = std::shared_ptr<IPublisher>;
