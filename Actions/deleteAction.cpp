#include "deleteAction.h"

DeleteAction::DeleteAction(ApplicationManager * pApp) :Action(pApp)
{}

void DeleteAction::ReadActionParameters() 
{
	deletedFigure = pManager->getSelectedFigure();
}

void DeleteAction::Execute() 
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();

	pOut->CreateDrawActionToolBar();
	pOut->drawOnActionbar("images\\MenuItems\\Menu_delete_Selected.jpg", ITM_DELETE);

	if (deletedFigure == NULL)
		pOut->PrintMessage("Please Select a Figure to delete");
	else 
		pManager->DeleteFigure(deletedFigure);
}
