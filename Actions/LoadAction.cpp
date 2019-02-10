#include "LoadAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"


LoadAction::LoadAction(ApplicationManager * pApp) :Action(pApp)
{}

void LoadAction::readActionParameters()
{
	Output* pOut = pManager->getOutput();
	Input* pIn = pManager->getInput();
	pOut->printMessage("Load Figures, click on the icon again to confirm.");
	confirm = pIn->getUserAction();
	pOut->clearStatusBar();
}

void LoadAction::execute()
{
	Output* pOut = pManager->getOutput();
	Input* pIn = pManager->getInput();
	
	// Confirming the action:
	readActionParameters();
	if (confirm != LOAD)
	{
		pOut->printMessage("Cancelled!");
		return;
	}	
	
	// Reading and setting the name of the source file:
	pOut->printMessage("Enter the name of the file  OR  Press [ENTER] to load from FigureList.txt");
	string FileName = pIn->getString(pOut);
	FileName = !FileName.empty() ? FileName : "FigureList.txt";

	loadFromFile(FileName);

	pOut->printMessage("Loaded Successfully!");
}

void LoadAction::readFigures(ifstream& InFile) const
{
	while (!InFile.eof())
	{
		CFigure* NewFig;
		string SavedType;	//The Figure's type
		InFile >> SavedType;	//Reading the type
		FigureType FIG_TYPE = readType(SavedType);	//Setting the type
		if (FIG_TYPE == EMPTY_TYPE) break;
		setFigType(NewFig, FIG_TYPE);	//Creating a dummy object of that type
		NewFig->load(InFile);	//Calling its Load function
		pManager->addFigure(NewFig);	//Adding it to the list
	}
}

void LoadAction::quickLoad() const
{
	loadFromFile("SaveGame.txt");
	Output* pOut = pManager->getOutput();
	pOut->createPlayToolBar(); // to redraw play mode toolbar to remove color icons
}

void LoadAction::loadFromFile(string filename) const
{
	Output* pOut = pManager->getOutput();
	pManager->clearFigures();
	ifstream InFile;
	InFile.open(filename);

	// Reading the draw and fill colors and changing their icons:
	color DrawColor = readColor(InFile);
	color FillColor = readColor(InFile);
	pOut->changeDrawColorIcon(DrawColor);
	pOut->changeFillColorIcon(FillColor, FillColor != NOFILL);

	// Reading Figure Information from the file:
	int NoOfFigures; 
	InFile >> NoOfFigures;
	
	readFigures(InFile);

	// Finishing up:
	InFile.close();
}