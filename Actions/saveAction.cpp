#include "SaveAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"



saveAction::saveAction(ApplicationManager * pApp) :Action(pApp)
{}

void saveAction::readActionParameters()
{
	Output* pOut = pManager->getOutput();
	Input* pIn = pManager->getInput();
	pOut->printMessage("Save Figures, click on the icon again to confirm.");
	Confirm = pIn->getUserAction();
	pOut->clearStatusBar();
}

void saveAction::execute()
{
	Output* pOut = pManager->getOutput();
	Input* pIn = pManager->getInput();
	
	// Confirming the action:
	readActionParameters();
	if (Confirm != SAVE)
	{
		pOut->printMessage("Cancelled!");
		return;
	}	
	
	// Reading and setting the name of the destination file:
	pOut->printMessage("Enter the name of the file including the extension  OR  Press [ENTER] to save to FigureList.txt");
	string FileName = pIn->getString(pOut);
	FileName = !FileName.empty() ? FileName : "FigureList.txt";
	
	// Saving to the file:
	ofstream OutFile;
	OutFile.open(FileName);
	pManager->writeFigures(OutFile);
	
	// Finishing up:
	OutFile.close();
	pManager->getOutput()->printMessage("Saved Successfully to " + FileName + "!");
}

void saveAction::quickSave() const
{
	// Open >> Save >> Close
	ofstream out;
	out.open("SaveGame.txt");
	pManager->writeFigures(out);
	out.close();
}
