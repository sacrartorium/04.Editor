#include "controller.hpp"

/**
 Оповестить векторные объекты о событии.
 @param modelPtr Указатель на документ.
 @param event Событие.
 */
void CController::send([[maybe_unused]] IModelPtr pointer, std::string event) {
  logger::log("Application->Controller", event);
}

/**
 Создать векторный объект.
 @return Указатель на векторный объект.
 */
MVectoralObjectPtr CController::newVectoralObject() {
  mVectoralObjectPtr = std::make_shared<MVectoralObject>();
  mVectoralObjectPtr->setPointer(shared_from_this());
  send(mVectoralObjectPtr, "Creating vectoral object");
  return mVectoralObjectPtr;
}

/**
 Удалить векторный объект.
 @param pointer Указатель на векторный объект.
 */
void CController::removeVectoralObject(MVectoralObjectPtr pointer) {
  if (mVectoralObjectPtr == pointer) {
    mVectoralObjectPtr.reset();
  }
}

/**
 Создать документ.
 @return Указатель на документ.
 */
MDocumentPtr CController::newDocument() {
  mDocumentPtr = std::make_shared<MDocument>();
  mDocumentPtr->setPointer(shared_from_this());
  send(mDocumentPtr, "Creating document");
  return mDocumentPtr;
}

/**
 Создать пользовательский интерфейс документа.
 */
VDocumentPtr CController::newVDocument() {
  VDocumentPtr view = std::make_shared<VDocument>();
  view->setPointer(mDocumentPtr);
  mDocumentPtr->add(view);
  return view;
}

/**
 Создать пользовательский интерфейс векторного объекта.
 */
VVectoralObjectPtr CController::newVVectoralObject() {
  VVectoralObjectPtr view = std::make_shared<VVectoralObject>();
  view->setPointer(mVectoralObjectPtr);
  mVectoralObjectPtr->add(view);
  return view;
}
