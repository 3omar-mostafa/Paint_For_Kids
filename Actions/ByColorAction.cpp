#include "ByColorAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

//constructor
ByColorAction::ByColorAction(ApplicationManager * pApp) :Action(pApp)
{
	Correct = 0;
	Wrong = 0;
	Terminate = false;
	FIG_COLOR = NOFILL;
	// Auto-saving:
	SaveAction Save(pManager);
	Save.QuickSave();
}

//function ReadActionParameters gets user actions and analyze them
void ByColorAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	Point P;

	if (pIn->GetUserAction(P) == COL_CLR)
	{
		Terminate = true;
		return;
	}

	CFigure* Clicked = pManager->GetFigure(P.x, P.y);
	if (!Clicked)
		return;

	if (Clicked->getFillColor() == FIG_COLOR || (!Clicked->isFilled() && Clicked->getDrawColor() == FIG_COLOR))
	{
		Correct++;
		pManager->DeleteFigure(Clicked);
		pManager->UpdateInterface();
		if (pManager->getSoundState())
			PlaySound(TEXT("Sounds/smb_coin.wav"), NULL, SND_FILENAME);
	}
	else
	{
		Wrong++;
		if (pManager->getSoundState())
			PlaySound(TEXT("Sounds/WrongAnswer.wav"), NULL, SND_FILENAME);
	}
}

//function Play tells the user which color he should pick and analyzes his action
bool ByColorAction::Play()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	FIG_COLOR = pManager->RandomColor();
	pOut->PrintMessage("Pick " + colorname(FIG_COLOR) + ", Click to start!");
	pIn->GetUserAction();
	pOut->PrintMessage("Pick " + colorname(FIG_COLOR) + "==>Correct: " + to_string(Correct) + "    Wrong: " + to_string(Wrong));
	while (pManager->HasColor(FIG_COLOR))
	{
		ReadActionParameters();
		if (Terminate)
			return false;
		pOut->PrintMessage("Pick " + colorname(FIG_COLOR) + "==>Correct: " + to_string(Correct) + "    Wrong: " + to_string(Wrong));
	}
	return true;

}

//function Reset resets the game
void ByColorAction::Reset()
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Game Restarted!");
	pManager->ClearFigures();
	LoadAction Load(pManager);
	Load.QuickLoad();
}

//function Execute redraws playtoolbar, calls Play until the game ends
void ByColorAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->CreatePlayToolBar();
	pOut->playOnToolbar("images\\MenuItems\\col_clr_selected.jpg", ITM_COL_CLR);

	while (!pManager->Empty())
		if (!Play())
		{
			Reset();
			return;
		}

	pOut->PrintMessage("Game Over! Final Score ==> Correct: " + to_string(Correct) + "    Wrong: " + to_string(Wrong));
	if (pManager->getSoundState())
		PlaySound(TEXT("Sounds/smb_gameover.wav"), NULL, SND_FILENAME);
	// Auto-Loading:
	LoadAction Load(pManager);
	Load.QuickLoad();
}

//function colorname gets the color name from its RGB
string ByColorAction::colorname(color c)
{
	if (c==BLACK) return "BLACK";
	else if (c==WHITE) return "WHITE";
	else if (c==RED) return "RED";
	else if (c==YELLOW) return "YELLOW";
	else if (c==GREEN) return "GREEN";
	else if (c==BLUE) return "BLUE";
	else return "NOFILL";
}
