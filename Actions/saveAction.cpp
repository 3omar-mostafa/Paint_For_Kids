#include "SaveAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"



SaveAction::SaveAction(ApplicationManager * pApp) :Action(pApp)
{}

void SaveAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Save Figures, click on the icon again to save to FigureList.txt");
	ThisAction = pIn->GetUserAction();
	pOut->ClearStatusBar();
}

void SaveAction::Execute()
{
	ReadActionParameters();
	if (ThisAction != SAVE)
		return;
	ofstream OutFile;
	OutFile.open("FigureList.txt");
	pManager->WriteFigures(OutFile);	
	OutFile << 0;
	OutFile.close();
	pManager->GetOutput()->PrintMessage("Saved Successfully! Open FigureList.txt for further instructions.");
}

SaveAction::~SaveAction()
{}
