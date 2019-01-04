#include "ByColorAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"

//constructor
ByColorAction::ByColorAction(ApplicationManager * pApp) :Action(pApp)
{
	correct = 0;
	wrong = 0;
	terminate = false;
	FIG_COLOR = NOFILL;
	// Auto-saving:
	SaveAction save(pManager);
	save.quickSave();
}

//function ReadActionParameters gets user actions and analyze them
void ByColorAction::readActionParameters()
{
	Input* pIn = pManager->getInput();
	Point P;

	ActionType action = pIn->getUserAction(P);
	if (action == PLAY_COLOR)
	{
		terminate = true;
		return;
	}
	else if (action == SOUND){
		pManager->toggleSound();
	}else if (action == EXIT){
		//TODO:
	}

	CFigure* clicked = pManager->getFigure(P.x, P.y);
	if (!clicked)
		return;

	if (clicked->getFillColor() == FIG_COLOR || (!(clicked->isFilled()) && clicked->getDrawColor() == FIG_COLOR))
	{
		correct++;
		pManager->deleteFigure(clicked);
		pManager->updateInterface();
		if (pManager->getSoundState())
			PlaySound(TEXT("Sounds/smb_coin.wav"), nullptr, SND_FILENAME);
	}
	else
	{
		wrong++;
		if (pManager->getSoundState())
			PlaySound(TEXT("Sounds/WrongAnswer.wav"), nullptr, SND_FILENAME);
	}
}

//function Play tells the user which color he should pick and analyzes his action
bool ByColorAction::play()
{
	Output* pOut = pManager->getOutput();
	Input* pIn = pManager->getInput();
	FIG_COLOR = pManager->randomColor();
	pOut->printMessage("Pick " + colorName(FIG_COLOR) + ", Click to start!");
	pIn->getUserAction();
	pOut->printMessage("Pick " + colorName(FIG_COLOR) + " ==> Correct: " + to_string(correct) + "    Wrong: " + to_string(wrong));
	while (pManager->hasColor(FIG_COLOR))
	{
		readActionParameters();
		if (terminate)
			return false;
		pOut->printMessage("Pick " + colorName(FIG_COLOR) + " ==> Correct: " + to_string(correct) + "    Wrong: " + to_string(wrong));
	}
	return true;

}

//function Reset resets the game
void ByColorAction::reset() const
{
	Output* pOut = pManager->getOutput();
	pOut->printMessage("Game Restarted!");
	pManager->clearFigures();
	LoadAction load(pManager);
	load.quickLoad();
}

//function Execute redraws play toolbar, calls Play until the game ends
void ByColorAction::execute()
{
	Output* pOut = pManager->getOutput();
	pOut->createPlayToolBar();
	pOut->playOnToolbar("images\\MenuItems\\col_clr_selected.jpg", ITM_COL_CLR);

	while (!pManager->empty())
		if (!play())
		{
			reset();
			return;
		}

	pOut->printMessage("Game Over! Final Score ==> Correct: " + to_string(correct) + "    Wrong: " + to_string(wrong));
	if (pManager->getSoundState())
		if (wrong == 0)
			PlaySound(TEXT("Sounds/siii.wav"), nullptr, SND_ASYNC);
		else
		PlaySound(TEXT("Sounds/smb_gameover.wav"), nullptr, SND_ASYNC);
	// Auto-Loading:
	LoadAction load(pManager);
	load.quickLoad();
}

//function colorName gets the color name from its RGB
string ByColorAction::colorName(color c)
{
	if (c==BLACK) return "BLACK";
	else if (c==WHITE) return "WHITE";
	else if (c==RED) return "RED";
	else if (c==YELLOW) return "YELLOW";
	else if (c==GREEN) return "GREEN";
	else if (c==BLUE) return "BLUE";
	else return "NOFILL";
}
