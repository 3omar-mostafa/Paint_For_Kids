#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures/CEllipse.h"
#include "Figures/CLine.h"
#include "Figures/CRectangle.h"
#include "Figures/CRhombus.h"
#include "Figures/CTriangle.h"
#include "GUI\input.h"
#include "GUI\output.h"
#include "Actions\AddRectAction.h"
#include "Actions\AddTriAction.h"
#include "Actions\AddElpsAction.h"
#include "Actions\AddRhomAction.h"
#include "Actions\AddLineAction.h"
#include "Actions\ChangeDrawColor.h"
#include "Actions\ChangeFillColor.h"
#include "Actions\copyAction.h"
#include "Actions\cutAction.h"
#include "Actions\pasteAction.h"
#include "Actions\loadAction.h"
#include "Actions\saveAction.h"
#include "Actions\saveByTypeAction.h"
#include "Actions\selectShapeAction.h"
#include "Actions\deleteAction.h"
#include "Actions\ExitAction.h"
#include "Actions\ClearAction.h"

//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures

private:
	int FigCount;		//Actual number of figures
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)

	CFigure* SelectedFig; //Pointer to the selected figure
	CFigure* lastSelected;
	CFigure* Clipboard;   //Pointer to the copied/cut figure

	//Pointers to Input and Output classes
	Input *pIn;
	Output *pOut;

public:
	ApplicationManager();
	~ApplicationManager();

	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType); //Creates an action and executes it

	// -- Figures Management Functions
	void AddFigure(CFigure* pFig);          //Adds a new figure to the FigList
	CFigure *GetFigure(int x, int y) const; //Search for a figure given a point inside the figure
	void ClearFigures();		//Added a function to remove all figures
	void Exit();
	// -- Interface Management Functions
	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window

	void setSelectedFigure(CFigure*);
	CFigure* getSelectedFigure();

	void setFigureCount(int);
	int getFigureCount();

	CFigure** getFigureArray();
	void setLastSelected(CFigure*);
	CFigure* getLastSelected();
};

#endif