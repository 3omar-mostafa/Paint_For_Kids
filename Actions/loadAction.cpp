#include "LoadAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"


loadAction::loadAction(ApplicationManager * pApp) :Action(pApp)
{}

void loadAction::readActionParameters()
{
	Output* pOut = pManager->getOutput();
	Input* pIn = pManager->getInput();
	pOut->printMessage("Load Figures, click on the icon again to confirm.");
	confirm = pIn->getUserAction();
	pOut->clearStatusBar();
}

void loadAction::execute()
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
	
	// Opening the file:
	ifstream InFile;
	InFile.open(FileName);
	
	// Reading the draw and fill colors and changing their icons:
	color DrawClr = readColor(InFile);
	color FillClr = readColor(InFile);
	pOut->changeDrawColorIcon(DrawClr);
	pOut->changeFillColorIcon(FillClr, (FillClr != NOFILL) ? 1 : 0);
	
	// Reading Figure Information from the file:
	int NoOfFigures; InFile >> NoOfFigures;	
	readFigures(InFile);	
	
	// Finishing up:
	InFile.close();
	pOut->printMessage("Loaded Successfully!");
}

void loadAction::readFigures(ifstream& InFile) const
{
	while (!InFile.eof())
	{
		cFigure* NewFig;
		string SavedType;	//The Figure's type
		InFile >> SavedType;	//Reading the type
		FigureType FIG_TYPE = readType(SavedType);	//Setting the type
		if (FIG_TYPE == EMPTY_TYPE) break;
		setFigType(NewFig, FIG_TYPE);	//Creating a dummy object of that type
		NewFig->load(InFile);	//Calling its Load function
		pManager->addFigure(NewFig);	//Adding it to the list
	}
}

void loadAction::quickLoad() const
{
	// Open >> Set Draw & Fill Colors >> Load Figures >> Close:
	ifstream qin;
	qin.open("SaveGame.txt");
	UI.DrawColor = readColor(qin);
	UI.FillColor = readColor(qin);
	int NoOfFigures; qin >> NoOfFigures;
	readFigures(qin);
	qin.close();
}
