#include "publisher_subscriber.hpp"

/**
 Добавить подписчика.
 @param pointer Указатель на подписчика.
 */
void IPublisher::add(ISubscriberPtr pointer) { mSubscribers.insert(pointer); }

/**
 Отправить сообщение всем подписчикам.
 @param message Сообщение, рассылаемое подписчикам.
 */
void IPublisher::sendForAll(const std::string &message) const {
  for (const ISubscriberPtr &pointer : mSubscribers) {
    pointer->update(message);
  }
}

/**
 Удалить подписчика.
 @param pointer Указатель на подписчика.
 */
void IPublisher::remove(ISubscriberPtr pointer) { mSubscribers.erase(pointer); }
