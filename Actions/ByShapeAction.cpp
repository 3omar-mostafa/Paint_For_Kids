#include "ByShapeAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

ByShapeAction::ByShapeAction(ApplicationManager * pApp) :Action(pApp)
{
	Correct = 0;
	Wrong = 0;
	FIG_TYPE = EMPTY_TYPE;
	
	// Auto-saving:
	ofstream OutFile;
	OutFile.open("Current.txt");
	pManager->WriteFigures(OutFile);
	OutFile << 0;
	OutFile.close();

	//Action* Save = new SaveAction(pManager);
	//Save->Execute();
	//pOut = pManager->GetOutput();
	//pIn = pManager->GetInput();
}

void ByShapeAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	int x, y;
	pIn->GetPointClicked(x, y);
	CFigure* Clicked = pManager->GetFigure(x, y);
	if (!Clicked)
		return;
	if (Clicked->getID() == FIG_TYPE)
	{
		Correct++;
		pManager->DeleteFigure(Clicked);
		pManager->UpdateInterface();
	}
	else
		Wrong++;
}

void ByShapeAction::Play()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	FIG_TYPE = pManager->RandomFigure();
	pOut->PrintMessage("Pick " + to_string(FIG_TYPE));
	pIn->GetUserAction();
	pOut->PrintMessage("Correct: " + to_string(Correct) + "    Wrong: " + to_string(Wrong));
	while (pManager->HasFigure(FIG_TYPE))
	{
		ReadActionParameters();
		pOut->PrintMessage("Correct: " + to_string(Correct) + "    Wrong: " + to_string(Wrong));
	}
}

void ByShapeAction::Execute()
{
	//ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	
	pOut->playOnToolbar("images\\MenuItems\\col_shp_selected.jpg", ITM_COL_SHP);	
	while(!pManager->Empty())
		Play();
	pOut->PrintMessage("Game Over! Final Score ==> Correct: " + to_string(Correct) + "    Wrong: " + to_string(Wrong));
	
	// Auto-Loading:
	//pIn->GetUserAction();
	ifstream InFile;
	InFile.open("Current.txt");
	pManager->ReadFigures(InFile);
	InFile.close();
}