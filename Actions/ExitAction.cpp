#include "ExitAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"


exitAction::exitAction(ApplicationManager * pApp) : Action(pApp)
{}

void exitAction::readActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->getOutput();
	pOut->printMessage("Exit");
	pOut->clearStatusBar();
}

void exitAction::execute()
{
	readActionParameters();
	pManager->exit();
}
