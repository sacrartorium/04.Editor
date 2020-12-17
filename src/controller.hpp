#pragma once

/**
 @file
 @brief Заголовочный файл, содержащий объявления контроллера для управления
 редактором.
 */

#include "document.hpp"
#include "graphics.hpp"
#include "interface/icontroller.hpp"

struct CController : public IController,
                     public std::enable_shared_from_this<CController> {
  void send(IModelPtr pointer, std::string event) override;

  MDocumentPtr newDocument();
  VDocumentPtr newVDocument();
  MVectoralObjectPtr newVectoralObject();
  VVectoralObjectPtr newVVectoralObject();
  void removeVectoralObject(MVectoralObjectPtr pointer);

private:
  MVectoralObjectPtr mVectoralObjectPtr;
  MDocumentPtr mDocumentPtr;
  logger mLogger;
};

using CControllerPtr = std::shared_ptr<CController>;
