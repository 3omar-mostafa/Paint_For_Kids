#include "ClearAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"


ClearAction::ClearAction(ApplicationManager * pApp) : Action(pApp)
{}

void ClearAction::readActionParameters()
{
	Output* pOut = pManager->getOutput();
	Input* pIn = pManager->getInput();
	pOut->printMessage("Clear Drawing Area, click on the icon again to clear.");
	Confirm = pIn->getUserAction();
	pOut->clearStatusBar();
}

void ClearAction::execute()
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

	SaveAction save(pManager);
	save.saveForUndo();
}