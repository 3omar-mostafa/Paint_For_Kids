#include "ClearAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"


ClearAction::ClearAction(ApplicationManager * pApp) : Action(pApp)
{}

void ClearAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Clear Drawing Area, click on the icon again to clear.");
	ThisAction = pIn->GetUserAction();
	pOut->ClearStatusBar();
}

void ClearAction::Execute()
{
	ReadActionParameters();
	if (ThisAction == CLEAR)
		pManager->ClearFigures();
	Output* pOut = pManager->GetOutput();
	pOut->ClearDrawArea();
}