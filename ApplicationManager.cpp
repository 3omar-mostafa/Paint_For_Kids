#include "ApplicationManager.h"
//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	pOut->PrintMessage("Welcome to Paint for Kids!");

	FigCount = 0;

	SelectedFig = NULL;
	lastSelected = NULL;
	Clipboard = NULL;
	lastCut = NULL;
	isSoundON = true;

	//Create an array of figure pointers and set them to NULL		
	for (int i = 0; i < MaxFigCount; i++)
		FigList[i] = NULL;
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//

//Asks the input to get the action from the user
ActionType ApplicationManager::GetUserAction() const
{
	return pIn->GetUserAction();
}

//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Action* pAct = NULL;
	GfxInfo gfxInfo;
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
	case DRAW_RECT:
		pAct = new AddRectAction(this);
		break;

	case DRAW_TRI:
		pAct = new AddTriAction(this);
		break;

	case DRAW_ELLIPSE:
		pAct = new AddElpsAction(this);
		break;

	case DRAW_RHOMBUS:
		pAct = new AddRhomAction(this);
		break;

	case DRAW_LINE:
		pAct = new AddLineAction(this);
		break;

	case CLEAR:
		pAct = new ClearAction(this);
		break;

	case CHNG_DRAW_CLR:
		pAct = new ChangeDrawColor(this);
		break;

	case CHNG_FILL_CLR:
		pAct = new ChangeFillColor(this);
		break;

	case SELECT:
		pAct = new selectShapeAction(this);
		break;

	case SEND_TO_BACK:
		pAct = new sendToBackAction(this);
		break;

	case BRING_TO_FRONT:
		pAct = new bringToFrontAction(this);
		break;

	case RESIZE:
		pAct = new ResizeAction(this);
		break;

	case DEL:
		pAct = new DeleteAction(this);
		break;

	case SAVE:
		pAct = new SaveAction(this);
		break;

	case SAVE_BY_TYPE:
		pAct = new SaveByTypeAction(this);
		break;

	case LOAD:
		pAct = new LoadAction(this);
		break;

	case COPY:
		pAct = new copyAction(this);
		break;

	case CUT:
		pAct = new cutAction(this);
		break;

	case PASTE:
		pAct = new pasteAction(this);
		break;

	case COL_SHP:
		pAct = new ByShapeAction(this);
		break;

	case COL_CLR:
		pAct = new ByColorAction(this);
		break;

	case SOUND:
		toggleSound();
		break;

	case EXIT:
		pAct = new ExitAction(this);
		break;

	case TO_DRAW:
		pOut->PrintMessage("Switch to Draw Mode, Creating Design Toolbar");
		pOut->playOnToolbar("images\\MenuItems\\draw_selected.jpg", ITM_DRAW);
		pOut->CreateDrawToolBar();
		pOut->CreateColorIcons();
		pOut->CreateDrawActionToolBar();
		pOut->drawSoundIcon(getSoundState());

		// resets Clipboard and selected figures after switching to draw mode
		SelectedFig = NULL;
		lastSelected = NULL;
		Clipboard = NULL;
		if (getSoundState())
			PlaySound(TEXT("Sounds/smb3_enter_level.wav"), NULL, SND_FILENAME);
		break;

	case TO_PLAY:
		pOut->PrintMessage("Switch to Play Mode, Creating Game Toolbar");
		pOut->drawOnToolbar("images\\MenuItems\\Menu_game_Selected.jpg", ITM_GAME);
		pOut->CreatePlayToolBar();
		pOut->removeDrawActionToolBar();
		if (SelectedFig != NULL) //remove selection color (Magenta) before play mode
			SelectedFig->SetSelected(false);
		UpdateInterface();
		if (getSoundState())
			PlaySound(TEXT("Sounds/smb3_enter_level.wav"), NULL, SND_FILENAME);
		break;

	case STATUS:	//a click on the status bar ==> no action
		pOut->PrintMessage("A Click on the Status Bar, Click anywhere");
		return;
	}

	//Execute the created action
	if (pAct != NULL)
	{
		pAct->Execute();	//Execute
		delete pAct;		//Action is not needed any more ==> delete it
		pAct = NULL;
		if (ActType != TO_PLAY && ActType != EXIT && UI.InterfaceMode != MODE_PLAY)
		{
			pOut->CreateDrawToolBar();
			pOut->CreateDrawActionToolBar();
			if (ActType == COL_SHP || ActType == COL_CLR)
				pOut->CreateColorIcons();
		}
	}
}

//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if (FigCount < MaxFigCount)
	{
		FigList[FigCount++] = pFig;
		pFig->setID(FigCount);
	}
}

//Removes all Figures from the List
void ApplicationManager::ClearFigures()
{
	for (int i = 0; i < FigCount; i++)
	{
		delete FigList[i];
		FigList[i] = NULL;
	}
	FigCount = 0;
}

void ApplicationManager::WriteFigures(ofstream& OutFile)
{
	OutFile << ColorData(UI.DrawColor) << " " << ColorData(UI.FillColor) << endl;	//Writing the Draw and Fill colors to the file
	OutFile << FigCount;	//Writing the number of Figures to the file
	for (int i = 0; i < FigCount; i++)
		FigList[i]->Save(OutFile);	//Calling the Save function for each figure
}

void ApplicationManager::WriteFigures(ofstream & OutFile, FigureType SavedType)
{
	// Getting the number of figures of SavedType in the Figure List:
	int TypeCount = 0;
	for (int i = 0; i < FigCount; i++)
		if (FigList[i]->getType() == SavedType)
			TypeCount++;

	OutFile << ColorData(UI.DrawColor) << " " << ColorData(UI.FillColor) << endl;		//Writing the Fill and Draw colors to the file
	OutFile << TypeCount;	//Writing the number of figures of SavedType
	for (int i = 0; i < FigCount; i++)
		if (FigList[i]->getType() == SavedType)
			FigList[i]->Save(OutFile);	//Calling the Save function for figures of SavedType
}

FigureType ApplicationManager::RandomType()
{
	FigureType TYPE;
	int idx = abs(rand()) % FigCount;
	TYPE = FigList[idx]->getType();
	return TYPE;
}

color ApplicationManager::RandomColor()
{
	color COLOR;
	int idx = abs(rand()) % FigCount;
	COLOR = FigList[idx]->isFilled() ? FigList[idx]->getFillColor() : FigList[idx]->getDrawColor() ;
	return COLOR;
}


bool ApplicationManager::Empty()
{
	for (int i = 0; i < FigCount; i++)
		if (FigList[i])
			return false;
	return true;
}

bool ApplicationManager::HasFigure(FigureType FIG_TYPE)
{
	for (int i = 0; i < FigCount; i++)
		if (FigList[i]->getType() == FIG_TYPE)
			return true;
	return false;
}
bool ApplicationManager::HasColor(color FIG_COLOR)
{
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->isFilled() && FigList[i]->getFillColor() == FIG_COLOR)
			return true;
		else if (!(FigList[i]->isFilled()) && FigList[i]->getDrawColor() == FIG_COLOR)
			return true;
	}

	return false;
}

CFigure *ApplicationManager::GetFigure(int x, int y) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL


	//Add your code here to search for a figure given a point x,y	
	//Remember that ApplicationManager only calls functions do NOT implement it.

	//started from last to first because if two shapes overlapped on same point,I should choose the top one
	for (int i = FigCount - 1; i >= 0; i--)
	{
		if (FigList[i]->doesItContain(x, y))
		{
			return FigList[i];
		}
	}

	return NULL;
}
void ApplicationManager::DeleteFigure(CFigure* Deleted)
{
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i] == Deleted)
		{
			if (Clipboard == Deleted)
				Clipboard = NULL;
			delete FigList[i];
			FigCount--;
			while (i < FigCount)
			{
				FigList[i++] = FigList[i + 1];	//Shifting all Figures backwards one place
				FigList[i]->setID(i);	//Matching the ID to the new spot in the Figure List
			}
			FigList[FigCount] = NULL;	//Freeing the last pointer
			return;
		}
	}
}

void ApplicationManager::sendToBack(CFigure* figure)
{
	int currentIndex;
	CFigure* currentFigure;

	for (int i = 0; i < FigCount; i++)
	{

		if (FigList[i] == figure)
		{
			currentIndex = i;
			currentFigure = FigList[i];
			break;
		}
	}

	for (int i = currentIndex; i > 0; i--)
	{
		FigList[i] = FigList[i - 1];
	}

	FigList[0] = currentFigure;
}

void ApplicationManager::bringToFront(CFigure* figure)
{
	int currentIndex;
	CFigure* currentFigure;
	for (int i = 0; i < FigCount; i++)
	{

		if (FigList[i] == figure)
		{
			currentIndex = i;
			currentFigure = FigList[i];
			break;
		}
	}

	for (int i = currentIndex; i < FigCount - 1; i++)
	{
		FigList[i] = FigList[i + 1];
	}

	FigList[FigCount - 1] = currentFigure;
}

//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{
	pOut->ClearDrawArea();
	for (int i = 0; i < FigCount; i++)
		if (FigList[i] != NULL)
			FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{
	return pIn;
}
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{
	return pOut;
}
void ApplicationManager::setSelectedFigure(CFigure* fig)
{
	SelectedFig = fig;
}

CFigure* ApplicationManager::getSelectedFigure()
{
	return SelectedFig;
}

void ApplicationManager::setLastSelected(CFigure* fig)
{
	lastSelected = fig;
}

CFigure* ApplicationManager::getLastSelected()
{
	return lastSelected;
}

void ApplicationManager::Exit()
{
	delete pOut; delete pIn;
	pIn = NULL; pOut = NULL;
}

void ApplicationManager::setClipboard(CFigure* fig)
{
	Clipboard = fig;
}

CFigure* ApplicationManager::getClipboard()
{
	return Clipboard;
}

color ApplicationManager::getLastDrawClr()
{
	return lastdrawclr;
}

color ApplicationManager::getLastFillClr()
{
	return lastfillclr;
}

void ApplicationManager::setLastDrawClr(color c)
{
	lastdrawclr = c;
}

void ApplicationManager::setLastFillClr(color clr)
{
	lastfillclr = clr;

}
void ApplicationManager::setLastCut(CFigure* fig)
{
	lastCut = fig;
}

CFigure* ApplicationManager::getLastCut()
{
	return lastCut;
}

bool ApplicationManager::getSoundState()
{
	return isSoundON;
}

void ApplicationManager::toggleSound()
{
	isSoundON = !isSoundON;
	pOut->drawSoundIcon(isSoundON);
}

////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for (int i = 0; i < FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;

}

