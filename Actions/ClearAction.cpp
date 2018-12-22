#include "ClearAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"


ClearAction::ClearAction(ApplicationManager * pApp) : Action(pApp)
{}

void ClearAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Clear Drawing Area, click on the icon again to clear.");
	Confirm = pIn->GetUserAction();
	pOut->ClearStatusBar();
}

void ClearAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	
	// Confirming the action:
	ReadActionParameters();
	if (Confirm != CLEAR)
	{
		pOut->PrintMessage("Cancelled!");
		return;
	}

	// Deleting all figures and clearing the Drawing Area:
	pManager->ClearFigures();	
	pOut->ClearDrawArea();
}