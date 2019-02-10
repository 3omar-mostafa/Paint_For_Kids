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

void SaveAction::saveForUndo()
{
	Output* pOut = pManager->getOutput();
	string filename = UndoRedoAction::getNextFileName();
	UndoRedoAction::incrementUndoList();

	// if we made some UNDOs and made a new action previous REDOs will be removed
	UndoRedoAction::eraseRedoList();
	pOut->drawUndoRedoIcons(UndoRedoAction::MODE_REDO, false);

	pOut->drawUndoRedoIcons(UndoRedoAction::MODE_UNDO, UndoRedoAction::isUndoAvailable());

	savetoFile(filename);
}