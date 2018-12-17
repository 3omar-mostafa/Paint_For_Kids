#include "saveByTypeAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"


SaveByTypeAction::SaveByTypeAction(ApplicationManager * pApp) :Action(pApp)
{}

void SaveByTypeAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Save by Figure Type, Click on any of the Figure Icons.");
	Confirm = pIn->GetUserAction();
}

void SaveByTypeAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	// Confirming the action:
	ReadActionParameters();
	FigureType SavedType = SetSavedType();
	if (SavedType == EMPTY_TYPE)
	{
		pOut->PrintMessage("Cancelled!");
		return;
	}
	
	// Reading and setting the name of the destination file:
	pOut->PrintMessage("Enter the name of the file including the extension  OR  Press [ENTER] to save to " + StoreType(SavedType) + ".txt");
	string FileName = pIn->GetString(pOut);
	FileName = (FileName != "") ? FileName : StoreType(SavedType) + ".txt";
	
	// Saving to the file:
	ofstream OutFile;
	OutFile.open(FileName);
	pManager->WriteFigures(OutFile, SavedType);
	
	// Finishing up:
	OutFile.close();
	pManager->GetOutput()->PrintMessage("Saved Successfully to " + FileName + "!");
}

FigureType SaveByTypeAction::SetSavedType()
{
	switch (Confirm)
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

SaveByTypeAction::~SaveByTypeAction()
{}
