#include "LoadAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"


LoadAction::LoadAction(ApplicationManager * pApp) :Action(pApp)
{}

void LoadAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Load Figures, click on the icon again to load.");
	ThisAction = pIn->GetUserAction();
	pOut->ClearStatusBar();
}

void LoadAction::Execute()
{
	ReadActionParameters();
	if (ThisAction != LOAD)
		return;
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Enter the name of the file.");
	string FileName = pIn->GetString(pOut);
	ifstream InFile;
	InFile.open(FileName);
	pManager->ReadFigures(InFile);
	InFile.close();
	pOut->PrintMessage("Loaded Successfully!");
}

LoadAction::~LoadAction()
{}
