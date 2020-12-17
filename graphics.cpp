#include "graphics.hpp"

/**
 Создать векторный объект.
 */
MVectoralObject::MVectoralObject() {
  logger::log("VectoralObject->Model", "Creating vectoral object!");
}

/**
 Уничтожить векторный объект.
 */
MVectoralObject::~MVectoralObject() {
  logger::log("VectoralObject->Model", "Removing vectoral object!");

  mPointer->send(nullptr, "Destroying vectoral object!");
}

/**
 Экспортировать документ.
 @param path Путь к документу.
 */
void MVectoralObject::changeColor(const std::string &newColor) {
  logger::log("VectoralObject->Model",
              "Changing color of vector object to " + newColor);

  mPointer->send(shared_from_this(), "Changing color of vector object");
  sendForAll("Changing color of vector object");
}

/**
 Отобразить пользовательский интерфейс векторного объекта.
 */
void VVectoralObject::draw() const {
  logger::log("VectoralObject->View", "Drawing vectoral object!");
}

/**
 Обновить пользовательский интерфейс векторного объекта.
 */
void VVectoralObject::update(const std::string &message) {
  logger::log("VectoralObject->View",
              "Update vectoral object <- " + message + "!");

  draw();
}
/**
 Очистить векторный объект.
 */
void VVectoralObject::clear() const {
  logger::log("VectoralObject->View", "Clear vectoral object!");
}
