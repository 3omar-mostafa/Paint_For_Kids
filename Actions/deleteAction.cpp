#include "deleteAction.h"

DeleteAction::DeleteAction(ApplicationManager * pApp) :Action(pApp)
{}

void DeleteAction::ReadActionParameters() {
	deletedFigure = pManager->getSelectedFigure();
}
void DeleteAction::Execute() {
	ReadActionParameters();

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	if (deletedFigure == NULL)
		pOut->PrintMessage("Please Select a Figure to delete");
	else 
		pManager->DeleteFigure(deletedFigure);
}
