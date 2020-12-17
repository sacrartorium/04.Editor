/*!
\file
\brief
Программа, демонстрирующая пример организации каркаса векторного редактора.
*/

#include "controller.hpp"

/*!
\brief
Точка старта программы.
*/
int main() {
  CControllerPtr ctrl = std::make_shared<CController>();
  {
    MDocumentPtr document = ctrl->newDocument();
    VDocumentPtr view = ctrl->newVDocument();
    document->doImport("document1.txt");
    document->doExport("document2.txt");
    document->sendForAll("Create new page");
    document->sendForAll("Change dpi");
    document->doExport("document3.txt");
  }

  {
    MVectoralObjectPtr vectoralObject = ctrl->newVectoralObject();
    VVectoralObjectPtr view = ctrl->newVVectoralObject();

    vectoralObject->sendForAll("Create child rectangle #1");
    vectoralObject->sendForAll("Create child rectangle #2");
    vectoralObject->sendForAll("Remove child rectangle #1");
    vectoralObject->changeColor("Red");

    ctrl->removeVectoralObject(vectoralObject);
  }

  return 0;
}
