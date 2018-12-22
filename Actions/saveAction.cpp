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
	pOut->PrintMessage("Save Figures, click on the icon again to confirm.");
	Confirm = pIn->GetUserAction();
	pOut->ClearStatusBar();
}

void SaveAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	
	// Confirming the action:
	ReadActionParameters();
	if (Confirm != SAVE)
	{
		pOut->PrintMessage("Cancelled!");
		return;
	}	
	
	// Reading and setting the name of the destination file:
	pOut->PrintMessage("Enter the name of the file including the extension  OR  Press [ENTER] to save to FigureList.txt");
	string FileName = pIn->GetString(pOut);
	FileName = (FileName != "") ? FileName : "FigureList.txt";
	
	// Saving to the file:
	ofstream OutFile;
	OutFile.open(FileName);
	pManager->WriteFigures(OutFile);
	
	// Finishing up:
	OutFile.close();
	pManager->GetOutput()->PrintMessage("Saved Successfully to " + FileName + "!");
}

void SaveAction::QuickSave()
{
	// Open >> Save >> Close
	ofstream qout;
	qout.open("SaveGame.txt");
	pManager->WriteFigures(qout);
	qout.close();
}

SaveAction::~SaveAction()
{}
