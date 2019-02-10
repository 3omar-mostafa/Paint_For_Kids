#include "SaveAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"



SaveAction::SaveAction(ApplicationManager * pApp) :Action(pApp)
{}

void SaveAction::readActionParameters()
{
	Output* pOut = pManager->getOutput();
	Input* pIn = pManager->getInput();
	pOut->printMessage("Save Figures, click on the icon again to confirm.");
	Confirm = pIn->getUserAction();
	pOut->clearStatusBar();
}

void SaveAction::execute()
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

	savetoFile(FileName);

	pManager->getOutput()->printMessage("Saved Successfully to " + FileName + "!");
}

void SaveAction::savetoFile(string filename ) const
{
	// Saving to the file:
	ofstream OutFile;
	OutFile.open(filename);
	pManager->writeFigures(OutFile);

	// Finishing up:
	OutFile.close();
}

void SaveAction::quickSave() const
{
	savetoFile("SaveGame.txt");
}