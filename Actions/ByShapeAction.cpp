#include "ByShapeAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"
//constructor
ByShapeAction::ByShapeAction(ApplicationManager * pApp) :Action(pApp)
{
	Correct = 0;
	Wrong = 0;
	FIG_TYPE = EMPTY_TYPE;
	terminate = false;

	// Auto-saving:
	SaveAction save(pManager);
	save.quickSave();
}
//functions of ByShapeAction are very close to ByColorAction 
//function ReadActionParameters gets user actions and analyze them
void ByShapeAction::readActionParameters()
{
	Input* pIn = pManager->getInput();
	Point P;

	ActionType action = pIn->getUserAction(P);
	if (action == PLAY_SHAPE)
	{
		terminate = true;
		return;
	}
	else if (action == SOUND) {
		pManager->toggleSound();
	}
	else if (action == EXIT) {
		//TODO:
	}

	CFigure* clicked = pManager->getFigure(P.x, P.y);
	if (!clicked)
		return;

	if (clicked->getType() == FIG_TYPE)
	{
		Correct++;
		pManager->deleteFigure(clicked);
		pManager->updateInterface();
		if (pManager->getSoundState())
			PlaySound(TEXT("Sounds/smb_coin.wav"), nullptr, SND_FILENAME);
	}
	else
	{
		Wrong++;
		if (pManager->getSoundState())
			PlaySound(TEXT("Sounds/WrongAnswer.wav"), nullptr, SND_FILENAME);

	}
}

//function Play tells the user which color he should pick and analyzes his action
bool ByShapeAction::Play()
{
	Output* pOut = pManager->getOutput();
	Input* pIn = pManager->getInput();
	FIG_TYPE = pManager->randomType();
	pOut->printMessage("Pick " + display(FIG_TYPE) + ", Click to start!");
	pIn->getUserAction();
	pOut->printMessage("Pick " + display(FIG_TYPE)+" ==> Correct: " + to_string(Correct) + "    Wrong: " + to_string(Wrong));

	while (pManager->hasFigure(FIG_TYPE))
	{
		readActionParameters();
		if (terminate)
			return false;
		pOut->printMessage("Pick " + display(FIG_TYPE) + " ==> Correct: " + to_string(Correct) + "    Wrong: " + to_string(Wrong));
	}
	return true;
}

//function Reset resets the game
void ByShapeAction::reset() const
{
	Output* pOut = pManager->getOutput();
	pOut->printMessage("Game Restarted!");
	pManager->clearFigures();
	LoadAction load(pManager);
	load.quickLoad();
}

//function Execute redraws Play Toolbar, calls Play until the game ends
void ByShapeAction::execute()
{
	Output* pOut = pManager->getOutput();
	pOut->createPlayToolBar();
	pOut->playOnToolbar("images\\MenuItems\\col_shp_selected.jpg", ITM_COL_SHP);

	while (!pManager->empty())
		if (!Play())
		{
			reset();
			return;
		}

	pOut->printMessage("Game Over! Final Score ==> Correct: " + to_string(Correct) + "    Wrong: " + to_string(Wrong));
	if (pManager->getSoundState())
		if (Wrong == 0)
			PlaySound(TEXT("Sounds/siii.wav"), nullptr, SND_ASYNC);
		else PlaySound(TEXT("Sounds/smb_gameover.wav"), nullptr, SND_ASYNC);

	// Auto-Loading:
	LoadAction load(pManager);
	load.quickLoad();
}