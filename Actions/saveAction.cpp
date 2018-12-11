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
	ThisAction = pIn->GetUserAction();
	pOut->ClearStatusBar();
}

void SaveAction::Execute()
{
	ReadActionParameters();
	if (ThisAction != SAVE)
		return;
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Enter the name of the file including the extension  OR  Press [ENTER] to save to FigureList.txt");
	string FileName = pIn->GetString(pOut);
	FileName = (FileName != "") ? FileName : "FigureList.txt";
	ofstream OutFile;
	OutFile.open(FileName);
	pManager->WriteFigures(OutFile);
	OutFile.close();
	pManager->GetOutput()->PrintMessage("Saved Successfully to " + FileName + "!");
}

void SaveAction::QuickSave()
{
	ofstream qout;
	qout.open("SaveGame.txt");
	pManager->WriteFigures(qout);
	qout.close();
}

SaveAction::~SaveAction()
{}
