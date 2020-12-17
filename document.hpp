#pragma once

/**
 @file
 @brief Заголовочный файл, содержащий объявления модели и вида для графического
 документа.
 */

#include "interface/imodel.hpp"
#include "interface/iview.hpp"

/**
 Модель данных для графического документа.
*/
struct MDocument : public IModel,
                   public std::enable_shared_from_this<MDocument> {
  MDocument();

  void doImport(const std::string &path);
  void doExport(const std::string &path);
};
using MDocumentPtr = std::shared_ptr<MDocument>;

/**
 Пользовательский интерфейс для графического документа.
*/
struct VDocument : public IView,
                   public std::enable_shared_from_this<VDocument> {
  void clear() const override;
  void draw() const override;
  void update(const std::string &message) override;
};
using VDocumentPtr = std::shared_ptr<VDocument>;
