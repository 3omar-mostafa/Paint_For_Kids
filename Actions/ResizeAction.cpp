#include "ResizeAction.h"

ResizeAction::ResizeAction(ApplicationManager * pApp) :Action(pApp)
{
	Ratio = 1;
}

void ResizeAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	
	Point P;
	pOut->drawResizeMenu();
	Confirm = pIn->GetUserAction(P);
	Ratio = pOut->selectSize(P);
}

void ResizeAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Resize Figure, Select a Ratio");
	pOut->drawOnActionbar("images\\MenuItems\\Menu_Resize_Selected.jpg", ITM_RESIZE);

	toResize = pManager->getSelectedFigure();

	if (toResize == NULL)
	{
		pOut->PrintMessage("Please Select a Figure first");
		return;
	}
	
	ReadActionParameters();

	if (toResize->Resize(Ratio))
	{
		pOut->ClearStatusBar();
		pManager->setSelectedFigure(NULL);
	}
	else
		pOut->PrintMessage("Please select a valid size");
}
