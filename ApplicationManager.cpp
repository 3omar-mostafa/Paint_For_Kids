#include "ApplicationManager.h"
//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->createInput();
	pOut->printMessage("Welcome to Paint for Kids!");

	figCount = 0;

	selectedFig = nullptr;
	lastSelected = nullptr;
	clipboard = nullptr;
	lastCut = nullptr;
	isSoundON = true;

	//Create an array of figure pointers and set them to nullptr		
	for (int i = 0; i < MAX_FIG_COUNT; i++)
		figList[i] = nullptr;
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//

//Asks the input to get the action from the user
ActionType ApplicationManager::getUserAction() const
{
	return pIn->getUserAction();
}

//Creates an action and executes it
void ApplicationManager::executeAction(ActionType ActType)
{
	Action* pAct = nullptr;
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
	case DRAW_RECT:
		pAct = new AddRectangleAction(this);
		break;

	case DRAW_TRI:
		pAct = new AddTriangleAction(this);
		break;

	case DRAW_ELLIPSE:
		pAct = new AddEllipseAction(this);
		break;

	case DRAW_RHOMBUS:
		pAct = new AddRhombusAction(this);
		break;

	case DRAW_LINE:
		pAct = new AddLineAction(this);
		break;

	case CLEAR:
		pAct = new ClearAction(this);
		break;

	case CHANGE_DRAW_COLOR:
		pAct = new ChangeDrawColor(this);
		break;

	case CHANGE_FILL_COLOR:
		pAct = new ChangeFillColor(this);
		break;

	case SELECT:
		pAct = new SelectShapeAction(this);
		break;

	case SEND_TO_BACK:
		pAct = new SendToBackAction(this);
		break;

	case BRING_TO_FRONT:
		pAct = new BringToFrontAction(this);
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
		pAct = new CopyAction(this);
		break;

	case CUT:
		pAct = new CutAction(this);
		break;

	case PASTE:
		pAct = new PasteAction(this);
		break;

	case PLAY_SHAPE:
		pAct = new ByShapeAction(this);
		break;

	case PLAY_COLOR:
		pAct = new ByColorAction(this);
		break;

	case SOUND:
		toggleSound();
		break;

	case EXIT:
		pAct = new ExitAction(this);
		break;

	case TO_DRAW:
		pOut->printMessage("Switch to Draw Mode, Creating Design Toolbar");
		pOut->playOnToolbar("images\\MenuItems\\draw_selected.jpg", ITM_DRAW);
		pOut->createDrawToolBar();
		pOut->createColorIcons();
		pOut->createDrawActionToolBar();
		pOut->drawSoundIcon(getSoundState());

		// resets clipboard and selected figures after switching to draw mode
		selectedFig = nullptr;
		lastSelected = nullptr;
		clipboard = nullptr;
		if (getSoundState())
			PlaySound(TEXT("Sounds/smb3_enter_level.wav"), nullptr, SND_FILENAME);
		break;

	case TO_PLAY:
		pOut->printMessage("Switch to Play Mode, Creating Game Toolbar");
		pOut->drawOnToolbar("images\\MenuItems\\Menu_game_Selected.jpg", ITM_GAME);
		pOut->createPlayToolBar();
		pOut->removeDrawActionToolBar();
		if (selectedFig != nullptr) //remove selection color (Magenta) before play mode
			selectedFig->setSelected(false);
		updateInterface();
		if (getSoundState())
			PlaySound(TEXT("Sounds/smb3_enter_level.wav"), nullptr, SND_ASYNC);
		break;

	case STATUS:	//a click on the status bar ==> no action
		pOut->printMessage("A Click on the Status Bar, Click anywhere");
		return;
	}

	//Execute the created action
	if (pAct != nullptr)
	{
		pAct->execute();	//Execute
		delete pAct;		//Action is not needed any more ==> delete it
		pAct = nullptr;
		if (ActType != TO_PLAY && ActType != EXIT && UI.InterfaceMode != MODE_PLAY)
		{
			pOut->createDrawToolBar();
			pOut->createDrawActionToolBar();
			if (ActType == PLAY_SHAPE || ActType == PLAY_COLOR)
				pOut->createColorIcons();
		}
	}
}

//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::addFigure(CFigure* pFig)
{
	if (figCount < MAX_FIG_COUNT)
	{
		figList[figCount++] = pFig;
		pFig->setID(figCount);
	}
}

//Removes all Figures from the List
void ApplicationManager::clearFigures()
{
	for (int i = 0; i < figCount; i++)
	{
		delete figList[i];
		figList[i] = nullptr;
	}
	figCount = 0;
}

void ApplicationManager::writeFigures(ofstream& OutFile)
{
	OutFile << colorData(UI.DrawColor) << " " << colorData(UI.FillColor) << endl;	//Writing the Draw and Fill colors to the file
	OutFile << figCount;	//Writing the number of Figures to the file
	for (int i = 0; i < figCount; i++)
		figList[i]->save(OutFile);	//Calling the Save function for each figure
}

void ApplicationManager::writeFigures(ofstream & OutFile, FigureType SavedType)
{
	// Getting the number of figures of SavedType in the Figure List:
	int TypeCount = 0;
	for (int i = 0; i < figCount; i++)
		if (figList[i]->getType() == SavedType)
			TypeCount++;

	OutFile << colorData(UI.DrawColor) << " " << colorData(UI.FillColor) << endl;		//Writing the Fill and Draw colors to the file
	OutFile << TypeCount;	//Writing the number of figures of SavedType
	for (int i = 0; i < figCount; i++)
		if (figList[i]->getType() == SavedType)
			figList[i]->save(OutFile);	//Calling the Save function for figures of SavedType
}

FigureType ApplicationManager::randomType() const
{
	int index = abs(rand()) % figCount;
	FigureType type = figList[index]->getType();
	return type;
}

color ApplicationManager::randomColor() const
{
	int index = abs(rand()) % figCount;
	color color = figList[index]->isFilled() ? figList[index]->getFillColor() : figList[index]->getDrawColor();
	return color;
}


bool ApplicationManager::empty()
{
	for (int i = 0; i < figCount; i++)
		if (figList[i])
			return false;
	return true;
}

bool ApplicationManager::hasFigure(FigureType FIG_TYPE) const
{
	for (int i = 0; i < figCount; i++)
		if (figList[i]->getType() == FIG_TYPE)
			return true;
	return false;
}
bool ApplicationManager::hasColor(color FIG_COLOR) const
{
	for (int i = 0; i < figCount; i++)
	{
		if (figList[i]->isFilled() && figList[i]->getFillColor() == FIG_COLOR)
			return true;
		else if (!(figList[i]->isFilled()) && figList[i]->getDrawColor() == FIG_COLOR)
			return true;
	}

	return false;
}

CFigure *ApplicationManager::getFigure(int x, int y) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return nullptr

	//started from last to first because if two shapes overlapped on same point,I should choose the top one
	for (int i = figCount - 1; i >= 0; i--)
	{
		if (figList[i]->doesItContain(x, y))
		{
			return figList[i];
		}
	}

	return nullptr;
}
void ApplicationManager::deleteFigure(CFigure* deleted)
{
	for (int i = 0; i < figCount; i++)
	{
		if (figList[i] == deleted)
		{
			if (clipboard == deleted)
				clipboard = nullptr;
			if(selectedFig = deleted)
				selectedFig = nullptr;
			delete figList[i];
			figCount--;
			while (i < figCount)
			{
				figList[i++] = figList[i + 1];	//Shifting all Figures backwards one place
				figList[i]->setID(i);	//Matching the ID to the new spot in the Figure List
			}
			figList[figCount] = nullptr;	//Freeing the last pointer
			return;
		}
	}
}

void ApplicationManager::sendToBack(CFigure* figure)
{
	int currentIndex;
	CFigure* currentFigure;

	for (int i = 0; i < figCount; i++)
	{

		if (figList[i] == figure)
		{
			currentIndex = i;
			currentFigure = figList[i];
			break;
		}
	}

	for (int i = currentIndex; i > 0; i--)
	{
		figList[i] = figList[i - 1];
	}

	figList[0] = currentFigure;
}

void ApplicationManager::bringToFront(CFigure* figure)
{
	int currentIndex;
	CFigure* currentFigure;
	for (int i = 0; i < figCount; i++)
	{

		if (figList[i] == figure)
		{
			currentIndex = i;
			currentFigure = figList[i];
			break;
		}
	}

	for (int i = currentIndex; i < figCount - 1; i++)
	{
		figList[i] = figList[i + 1];
	}

	figList[figCount - 1] = currentFigure;
}

//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::updateInterface() const
{
	pOut->clearDrawArea();
	for (int i = 0; i < figCount; i++)
		if (figList[i] != nullptr)
			figList[i]->draw(pOut);		//Call Draw function (virtual member fn)
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::getInput() const
{
	return pIn;
}
//Return a pointer to the output
Output *ApplicationManager::getOutput() const
{
	return pOut;
}
void ApplicationManager::setSelectedFigure(CFigure* fig)
{
	selectedFig = fig;
}

CFigure* ApplicationManager::getSelectedFigure() const
{
	return selectedFig;
}

void ApplicationManager::setLastSelected(CFigure* fig)
{
	lastSelected = fig;
}

CFigure* ApplicationManager::getLastSelected() const
{
	return lastSelected;
}

void ApplicationManager::exit()
{
	delete pOut; delete pIn;
	pIn = nullptr; pOut = nullptr;
}

void ApplicationManager::setClipboard(CFigure* fig)
{
	clipboard = fig;
}

CFigure* ApplicationManager::getClipboard() const
{
	return clipboard;
}

color ApplicationManager::getLastDrawClr() const
{
	return lastDrawColor;
}

color ApplicationManager::getLastFillClr() const
{
	return lastFillColor;
}

void ApplicationManager::setLastDrawClr(color c)
{
	lastDrawColor = c;
}

void ApplicationManager::setLastFillClr(color clr)
{
	lastFillColor = clr;

}
void ApplicationManager::setLastCut(CFigure* fig)
{
	lastCut = fig;
}

CFigure* ApplicationManager::getLastCut() const
{
	return lastCut;
}

bool ApplicationManager::getSoundState() const
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
	for (int i = 0; i < figCount; i++)
		delete figList[i];
	delete pIn;
	delete pOut;

}

