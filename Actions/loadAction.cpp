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
	ThisAction = pIn->GetUserAction();
	pOut->ClearStatusBar();
}

void LoadAction::ReadFigures(ifstream& InFile)
{
	while (!InFile.eof())
	{
		CFigure* NewFig;
		string Cast;
		InFile >> Cast;
		FigureType FIG_TYPE = ReadType(Cast);
		if (FIG_TYPE == EMPTY_TYPE) break;
		SetFigType(NewFig, FIG_TYPE);
		NewFig->Load(InFile);
		pManager->AddFigure(NewFig);
	}
}

void LoadAction::Execute()
{
	ReadActionParameters();
	if (ThisAction != LOAD)
		return;
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	
	pOut->PrintMessage("Enter the name of the file  OR  Press [ENTER] to load from FigureList.txt");
	string FileName = pIn->GetString(pOut);
	FileName = (FileName != "") ? FileName : "FigureList.txt";
	ifstream InFile;
	InFile.open(FileName);
	
	color DrawClr = ReadColor(InFile);
	color FillClr = ReadColor(InFile);
	pOut->changeDrawColorIcon(DrawClr);
	pOut->changeFillColorIcon(FillClr, (FillClr != NOFILL) ? 1 : 0);
	
	int NoOfFigures; InFile >> NoOfFigures;	
	ReadFigures(InFile);	
	
	InFile.close();
	pOut->PrintMessage("Loaded Successfully!");
}

void LoadAction::QuickLoad()
{
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
