#include "ClearAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"


clearAction::clearAction(ApplicationManager * pApp) : Action(pApp)
{}

void clearAction::readActionParameters()
{
	Output* pOut = pManager->getOutput();
	Input* pIn = pManager->getInput();
	pOut->printMessage("Clear Drawing Area, click on the icon again to clear.");
	Confirm = pIn->getUserAction();
	pOut->clearStatusBar();
}

void clearAction::execute()
{
	Output* pOut = pManager->getOutput();
	
	// Confirming the action:
	readActionParameters();
	if (Confirm != CLEAR)
	{
		pOut->printMessage("Cancelled!");
		return;
	}

	// Deleting all figures and clearing the Drawing Area:
	pManager->clearFigures();	
	pOut->clearDrawArea();
}