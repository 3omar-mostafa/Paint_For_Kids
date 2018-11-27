#include "ExitAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"


ExitAction::ExitAction(ApplicationManager * pApp) : Action(pApp)
{}

void ExitAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Exit");
	pOut->ClearStatusBar();
}

void ExitAction::Execute()
{
	ReadActionParameters();
	pManager->Exit();
}
