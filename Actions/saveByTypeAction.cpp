#include "saveByTypeAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"


saveByTypeAction::saveByTypeAction(ApplicationManager * pApp) :Action(pApp)
{}

void saveByTypeAction::readActionParameters()
{
	Output* pOut = pManager->getOutput();
	Input* pIn = pManager->getInput();
	pOut->printMessage("Save by Figure Type, Click on any of the Figure Icons.");
	confirm = pIn->getUserAction();
}

void saveByTypeAction::execute()
{
	Output* pOut = pManager->getOutput();
	Input* pIn = pManager->getInput();

	// Confirming the action:
	readActionParameters();
	FigureType SavedType = setSavedType();
	if (SavedType == EMPTY_TYPE)
	{
		pOut->printMessage("Cancelled!");
		return;
	}
	
	// Reading and setting the name of the destination file:
	pOut->printMessage("Enter the name of the file including the extension  OR  Press [ENTER] to save to " + storeType(SavedType) + ".txt");
	string FileName = pIn->getString(pOut);
	FileName = !FileName.empty() ? FileName : storeType(SavedType) + ".txt";
	
	// Saving to the file:
	ofstream OutFile;
	OutFile.open(FileName);
	pManager->writeFigures(OutFile, SavedType);
	
	// Finishing up:
	OutFile.close();
	pManager->getOutput()->printMessage("Saved Successfully to " + FileName + "!");
}

FigureType saveByTypeAction::setSavedType() const
{
	switch (confirm)
	{
	case DRAW_RECT:
		return RECTANGLE;

	case DRAW_TRI:
		return TRIANGLE;

	case DRAW_ELLIPSE:
		return ELLIPSE;

	case DRAW_RHOMBUS:
		return RHOMBUS;

	case DRAW_LINE:
		return LINE;

	default:
		return EMPTY_TYPE;
	}
}
