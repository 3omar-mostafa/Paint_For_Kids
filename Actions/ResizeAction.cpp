#include "ResizeAction.h"

ResizeAction::ResizeAction(ApplicationManager * pApp) :Action(pApp)
{
	Ratio = 1;
}

void ResizeAction::readActionParameters()
{
	Output* pOut = pManager->getOutput();
	Input* pIn = pManager->getInput();
	
	// Getting the Ratio:
	Point P;
	pOut->drawResizeMenu();
	Confirm = pIn->getUserAction(P);
	Ratio = pOut->selectSize(P);
}

void ResizeAction::execute()
{
	Output* pOut = pManager->getOutput();

	pOut->printMessage("Resize Figure, Select a Ratio");
	pOut->drawOnActionbar("images\\MenuItems\\Menu_Resize_Selected.jpg", ITM_RESIZE);

	// Resizing the Selected Figure:
	toResize = pManager->getSelectedFigure();

	if (toResize == nullptr)
	{
		pOut->printMessage("Please Select a Figure first");
		return;
	}
	
	readActionParameters();

	if (toResize->resize(Ratio))	//The function returns false if the resizing fails or was cancelled and returns true if the Resizing was successful
	{
		pOut->clearStatusBar();
		pManager->setSelectedFigure(nullptr);
	}
	else
		pOut->printMessage("Please Select a Valid Size");
}
