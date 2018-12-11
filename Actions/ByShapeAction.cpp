#include "ByShapeAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

ByShapeAction::ByShapeAction(ApplicationManager * pApp) :Action(pApp)
{
	Correct = 0;
	Wrong = 0;
	FIG_TYPE = EMPTY_TYPE;
	Terminate = 0;

	// Auto-saving:
	SaveAction* Save = new SaveAction(pManager);
	Save->QuickSave();
}

void ByShapeAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	Point P;
	if (pIn->GetUserAction(P) == COL_SHP)
	{
		Terminate = 1;
		return;
	}
	CFigure* Clicked = pManager->GetFigure(P.x, P.y);
	if (!Clicked)
		return;
	if (Clicked->getType() == FIG_TYPE)
	{
		Correct++;
		pManager->DeleteFigure(Clicked);
		pManager->UpdateInterface();
	}
	else
		Wrong++;
}

bool ByShapeAction::Play()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	FIG_TYPE = pManager->RandomFigure();
	pOut->PrintMessage("Pick " + Display(FIG_TYPE) + ", Click to start!");
	pIn->GetUserAction();
	pOut->PrintMessage("Correct: " + to_string(Correct) + "    Wrong: " + to_string(Wrong));
	while (pManager->HasFigure(FIG_TYPE))
	{
		ReadActionParameters();
		if (Terminate)
			return false;
		pOut->PrintMessage("Correct: " + to_string(Correct) + "    Wrong: " + to_string(Wrong));
	}
	return true;
}

void ByShapeAction::Reset()
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Game Restarted!");
	pManager->ClearFigures();
	LoadAction* Load = new LoadAction(pManager);
	Load->QuickLoad();
}

void ByShapeAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->playOnToolbar("images\\MenuItems\\col_shp_selected.jpg", ITM_COL_SHP);
	while (!pManager->Empty())
		if (!Play())
		{
			Reset();
			return;
		}
	pOut->PrintMessage("Game Over! Final Score ==> Correct: " + to_string(Correct) + "    Wrong: " + to_string(Wrong));

	// Auto-Loading:
	LoadAction* Load = new LoadAction(pManager);
	Load->QuickLoad();
}