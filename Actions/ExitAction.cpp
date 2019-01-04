#include "ExitAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\Output.h"


ExitAction::ExitAction(ApplicationManager * pApp) : Action(pApp)
{}

void ExitAction::readActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->getOutput();
	pOut->printMessage("Exit");
	pOut->clearStatusBar();
}

void ExitAction::execute()
{
	readActionParameters();
	pManager->exit();
}
