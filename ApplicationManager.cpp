#include "ApplicationManager.h"
//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();

	FigCount = 0;

	SelectedFig = NULL;
	lastSelected = NULL;
	Clipboard = NULL;

	//Create an array of figure pointers and set them to NULL		
	for (int i = 0; i < MaxFigCount; i++)
		FigList[i] = NULL;
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Action* pAct = NULL;
	GfxInfo gfxInfo;
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
	case DRAW_RECT:
		pOut->CreateDrawToolBar();
		pOut->drawOnToolbar("images\\MenuItems\\Menu_Rect_Selected.jpg", ITM_RECT);
		pAct = new AddRectAction(this);
		break;

	case DRAW_TRI:
		pOut->CreateDrawToolBar();
		pOut->drawOnToolbar("images\\MenuItems\\Menu_Triangle_Selected.jpg", ITM_TRIANGLE);
		pAct = new AddTriAction(this);
		break;

	case DRAW_ELLIPSE:
		pOut->CreateDrawToolBar();
		pOut->drawOnToolbar("images\\MenuItems\\Menu_Circ_Selected.jpg", ITM_CIRCLE);
		pAct = new AddElpsAction(this);
		break;

	case DRAW_RHOMBUS:
		pOut->CreateDrawToolBar();
		pOut->drawOnToolbar("images\\MenuItems\\Menu_Rhombus_Selected.jpg", ITM_RHOMBUS);
		pAct = new AddRhomAction(this);
		break;

	case CLEAR:
		pAct = new ClearAction(this);
		break;

	case DRAW_LINE:
		pOut->CreateDrawToolBar();
		pOut->drawOnToolbar("images\\MenuItems\\Menu_Line_Selected.jpg", ITM_LINE);
		pAct = new AddLineAction(this);
		break;
	case CHNG_DRAW_CLR:
		pOut->PrintMessage("Action: Change Figure's drawing color, Click Anywhere");
		pOut->CreateDrawToolBar();
		pAct = new ChangeDrawColor(this);
		break;
	case CHNG_FILL_CLR:
		pOut->PrintMessage("Action: Change Figure's fill color, Click Anywhere");
		pOut->CreateDrawToolBar();
		pAct = new ChangeFillColor(this);
		break;

	case SELECT:
		pOut->PrintMessage("Action: select , Click anywhere");
		pOut->CreateDrawActionToolBar();
		pOut->drawOnActionbar("images\\MenuItems\\Menu_select_Selected.jpg", ITM_SELECT);
		pAct = new selectShapeAction(this);
		break;

	case DEL:
		pOut->CreateDrawActionToolBar();
		pOut->drawOnActionbar("images\\MenuItems\\Menu_delete_Selected.jpg", ITM_DELETE);
		pAct = new deleteAction(this);
		break;

	case SAVE:
		pAct = new SaveAction(this);
		break;

	case LOAD:
		pAct = new LoadAction(this);
		break;

	case TO_DRAW:
		pOut->PrintMessage("Action: Switch to Draw Mode, Creating Simulation Toolbar");
		pOut->playOnToolbar("images\\MenuItems\\draw_selected.jpg", ITM_DRAW);
		pOut->CreateDrawToolBar();
		pOut->CreateDrawActionToolBar();
		pOut->CreateColorIcons();
		break;

	case TO_PLAY:
		pOut->PrintMessage("Action: Switch to Play Mode, creating Design tool bar");
		pOut->drawOnToolbar("images\\MenuItems\\Menu_game_Selected.jpg", ITM_GAME);
		pOut->CreatePlayToolBar();
		pOut->removeDrawActionToolBar();

		//TODO: Temporary Commenting until we build it
		break;
	
	case COL_SHP:
		pAct = new ByShapeAction(this);
		break;

	case EXIT:
		pAct = new ExitAction(this);
		break;

	case STATUS:	//a click on the status bar ==> no action
		pOut->PrintMessage("Action: a click on the Status Bar, Click anywhere");
		return;
	}

	//Execute the created action
	if (pAct != NULL)
	{
		pAct->Execute();	//Execute
		delete pAct;		//Action is not needed any more ==> delete it
		pAct = NULL;
	}
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if (FigCount < MaxFigCount)
		FigList[FigCount++] = pFig;
}

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
	OutFile << ColorData(UI.DrawColor) << " " << ColorData(UI.FillColor) << endl;
	OutFile << FigCount << " " << endl;
	for (int i = 0; i < FigCount; i++)
		FigList[i]->Save(OutFile);
}

void ApplicationManager::ReadFigures(ifstream& InFile)
{
	while (true)
	{
		CFigure* NewFig;
		string Cast;
		InFile >> Cast;
		FigureType FIG_TYPE = ReadType(Cast);
		if (FIG_TYPE == EMPTY_TYPE)
			return;
		SetFigureType(NewFig, FIG_TYPE);
		NewFig->Load(InFile);
		AddFigure(NewFig);
		FIG_TYPE = EMPTY_TYPE;
	}
}

FigureType ApplicationManager::RandomFigure()
{
	FigureType TYPE;
	int idx = abs(rand()) % FigCount;
	TYPE = FigList[idx]->getType();
	return TYPE;
}

void ApplicationManager::SetFigureType(CFigure*& FP, FigureType T)
{
	Point P1, P2, P3;
	P1 = P2 = P3 = { 400,400 };
	GfxInfo dummy;
	switch (T)
	{
	case LINE:
		FP = new CLine(P1, P2, dummy);
		break;

	case RECTANGLE:
		FP = new CRectangle(P1, P2, dummy);
		break;

	case TRIANGLE:
		FP = new CTriangle(P1, P2, P3, dummy);
		break;

	case RHOMBUS:
		FP = new CRhombus(P1, dummy);
		break;

	case ELLIPSE:
		FP = new CEllipse(P1, dummy);
		break;
	}
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

CFigure *ApplicationManager::GetFigure(int x, int y) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL


	//Add your code here to search for a figure given a point x,y	
	//Remember that ApplicationManager only calls functions do NOT implement it.

	//started from last to first because if two shapes overlapped on same point,I should choose the top one
	for (int i = FigCount - 1; i >= 0; i--) {
		if (FigList[i]->doesItContain(x, y)) {
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
			delete FigList[i];
			FigList[i] = NULL;
			FigList[i] = FigList[--FigCount];
			FigList[FigCount] = NULL;
			return;
		}
	}
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
void ApplicationManager::setSelectedFigure(CFigure* fig) {
	SelectedFig = fig;
}

CFigure* ApplicationManager::getSelectedFigure() {
	return SelectedFig;
}

void ApplicationManager::setLastSelected(CFigure* fig) {
	lastSelected = fig;
}

CFigure* ApplicationManager::getLastSelected() {
	return lastSelected;
}

void  ApplicationManager::setFigureCount(int x) {
	FigCount = x;
}
int  ApplicationManager::getFigureCount() {
	return FigCount;
}

CFigure** ApplicationManager::getFigureArray() {
	return FigList;
}

void ApplicationManager::Exit()
{
	delete pOut; delete pIn;
	pIn = NULL; pOut = NULL;
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

// Additional Functions:
string StoreType(FigureType T)
{
	switch (T)
	{
	case RECTANGLE:
		return "RECTANGLE";
		break;
	case TRIANGLE:
		return "TRIANGLE";
		break;
	case ELLIPSE:
		return "ELLIPSE";
		break;
	case RHOMBUS:
		return "RHOMBUS";
		break;
	case LINE:
		return "LINE";
		break;
	}
	return "";
}

FigureType ReadType(string Str)
{
	switch (Str[1])
	{
	case 'E':
		return RECTANGLE;
		break;
	case 'R':
		return TRIANGLE;
		break;
	case 'L':
		return ELLIPSE;
		break;
	case 'H':
		return RHOMBUS;
		break;
	case 'I':
		return LINE;
		break;
	}
	return EMPTY_TYPE;
}

string ColorData(color C)
{
	string Data;
	Data += to_string(int(C.ucRed)) + " " + to_string(int(C.ucGreen)) + " " + to_string(int(C.ucBlue));
	return Data;
}

color ReadColor(ifstream& in)
{
	int Red, Green, Blue;
	in >> Red >> Green >> Blue;
	return color(Red, Green, Blue);
}
