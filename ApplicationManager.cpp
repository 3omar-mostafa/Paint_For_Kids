#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "Actions\AddTriAction.h"
#include "Actions\AddElpsAction.h"
#include "Actions\AddRhomAction.h"
#include "Actions\AddLineAction.h"
#include "Actions\ExitAction.h"

//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();

	FigCount = 0;
	

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

	case DRAW_LINE:
		pOut->CreateDrawToolBar();
		pOut->drawOnToolbar("images\\MenuItems\\Menu_Line_Selected.jpg", ITM_LINE);
		pAct = new AddLineAction(this);
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

		//TODO: Temporary Commenting until we build it
		break;

	case EXIT:
		//pAct = new ExitAction(this);
		break;

	case STATUS:	//a click on the status bar ==> no action
		pOut->PrintMessage("Action: a click on the Status Bar, Click anywhere");
		return;
	}

	//Execute the created action
	if (pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//Action is not needed any more ==> delete it
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
void ApplicationManager::Exit()
{
	
	delete pOut; delete pIn;
	pIn = NULL; pOut = NULL;
	


}

////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(int x, int y) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL


	//Add your code here to search for a figure given a point x,y	
	//Remember that ApplicationManager only calls functions do NOT implement it.

	return NULL;
}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{
	for (int i = 0; i < FigCount; i++)
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
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for (int i = 0; i < FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;

}
