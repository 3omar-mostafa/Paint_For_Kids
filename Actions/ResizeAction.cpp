#include "ResizeAction.h"

ResizeAction::ResizeAction(ApplicationManager * pApp) :Action(pApp)
{
	Ratio = 1;
}

void ResizeAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	
	// Getting the Ratio:
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

	// Resizing the Selected Figure:
	toResize = pManager->getSelectedFigure();

	if (toResize == NULL)
	{
		pOut->PrintMessage("Please Select a Figure first");
		return;
	}
	
	ReadActionParameters();

	if (toResize->Resize(Ratio))	//The function returns false if the resizing fails or was cancelled and returns true if the Resizing was successful
	{
		pOut->ClearStatusBar();
		pManager->setSelectedFigure(NULL);
	}
	else
		pOut->PrintMessage("Please Select a Valid Size");
}
