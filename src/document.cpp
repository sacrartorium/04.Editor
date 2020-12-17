#include "document.hpp"

/**
 Создать новый графический документ.
 */
MDocument::MDocument() {
  logger::log("Document->Model", "Creating new document");
}

/**
 Импортировать документ.
 @param path Путь к документу.
 */
void MDocument::doImport(const std::string &path) {
  logger::log("Document->Model", "Importing document from " + path);

  mPointer->send(shared_from_this(), "Import document");
  sendForAll("Importing document");
}

/**
 Экспортировать документ.
 @param path Путь к документу.
 */
void MDocument::doExport(const std::string &path) {
  logger::log("Document->Model", "Exporting document to " + path);

  mPointer->send(shared_from_this(), "Export document");
  sendForAll("Exporting document");
}

/**
 Очистить графический документ.
 */
void VDocument::clear() const {
  logger::log("Document->View", "Clear document!");
}

/**
 Отобразить пользовательский интерфейс графический документ.
 */
void VDocument::draw() const {
  logger::log("Document->View", "Drawing document!");
}

/**
 Обновить пользовательский интерфейс графического документа.
 */
void VDocument::update(const std::string &message) {
  logger::log("Document->View", "Updating document <- " + message);

  draw();
}
