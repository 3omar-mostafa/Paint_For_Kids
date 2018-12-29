#include "deleteAction.h"

deleteAction::deleteAction(ApplicationManager * pApp) :Action(pApp)
{}

void deleteAction::readActionParameters() 
{
	deletedFigure = pManager->getSelectedFigure();
}

void deleteAction::execute() 
{
	readActionParameters();
	Output* pOut = pManager->getOutput();

	pOut->createDrawActionToolBar();
	pOut->drawOnActionbar("images\\MenuItems\\Menu_delete_Selected.jpg", ITM_DELETE);

	if (deletedFigure == nullptr)
		pOut->printMessage("Please Select a Figure to delete");
	else 
		pManager->deleteFigure(deletedFigure);
}
