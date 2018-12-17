#include "LoadAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"


LoadAction::LoadAction(ApplicationManager * pApp) :Action(pApp)
{}

void LoadAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Load Figures, click on the icon again to confirm.");
	Confirm = pIn->GetUserAction();
	pOut->ClearStatusBar();
}

void LoadAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	
	// Confirming the action:
	ReadActionParameters();
	if (Confirm != LOAD)
	{
		pOut->PrintMessage("Cancelled!");
		return;
	}	
	
	// Reading and setting the name of the source file:
	pOut->PrintMessage("Enter the name of the file  OR  Press [ENTER] to load from FigureList.txt");
	string FileName = pIn->GetString(pOut);
	FileName = (FileName != "") ? FileName : "FigureList.txt";
	
	// Opening the file:
	ifstream InFile;
	InFile.open(FileName);
	
	// Reading the draw and fill colors and changing their icons:
	color DrawClr = ReadColor(InFile);
	color FillClr = ReadColor(InFile);
	pOut->changeDrawColorIcon(DrawClr);
	pOut->changeFillColorIcon(FillClr, (FillClr != NOFILL) ? 1 : 0);
	
	// Reading Figure Information from the file:
	int NoOfFigures; InFile >> NoOfFigures;	
	ReadFigures(InFile);	
	
	// Finishing up:
	InFile.close();
	pOut->PrintMessage("Loaded Successfully!");
}

void LoadAction::ReadFigures(ifstream& InFile)
{
	while (!InFile.eof())
	{
		CFigure* NewFig;
		string SavedType;	//The Figure's type
		InFile >> SavedType;	//Reading the type
		FigureType FIG_TYPE = ReadType(SavedType);	//Setting the type
		if (FIG_TYPE == EMPTY_TYPE) break;
		SetFigType(NewFig, FIG_TYPE);	//Creating a dummy object of that type
		NewFig->Load(InFile);	//Calling its Load function
		pManager->AddFigure(NewFig);	//Adding it to the list
	}
}

void LoadAction::QuickLoad()
{
	// Open >> Set Draw & Fill Colors >> Load Figures >> Close:
	ifstream qin;
	qin.open("SaveGame.txt");
	UI.DrawColor = ReadColor(qin);
	UI.FillColor = ReadColor(qin);
	int NoOfFigures; qin >> NoOfFigures;
	ReadFigures(qin);
	qin.close();
}

LoadAction::~LoadAction()
{}
