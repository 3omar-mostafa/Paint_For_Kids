#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures/CEllipse.h"
#include "Figures/CLine.h"
#include "Figures/CRectangle.h"
#include "Figures/CRhombus.h"
#include "Figures/CTriangle.h"
#include "GUI/input.h"
#include "GUI/output.h"
#include "Actions/AddRectAction.h"
#include "Actions/AddTriAction.h"
#include "Actions/AddElpsAction.h"
#include "Actions/AddRhomAction.h"
#include "Actions/AddLineAction.h"
#include "Actions/ChangeDrawColor.h"
#include "Actions/ChangeFillColor.h"
#include "Actions/copyAction.h"
#include "Actions/cutAction.h"
#include "Actions/pasteAction.h"
#include "Actions/LoadAction.h"
#include "Actions/SaveAction.h"
#include "Actions/saveByTypeAction.h"
#include "Actions/selectShapeAction.h"
#include "Actions/deleteAction.h"
#include "Actions/ExitAction.h"
#include "Actions/ClearAction.h"
#include "Actions/ByShapeAction.h"
#include "Actions/ByColorAction.h"
#include "Actions/sendToBackAction.h"
#include "Actions/bringToFrontAction.h"
#include "Actions/ResizeAction.h"

//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MAX_FIG_COUNT = 200 };	//Max no of figures

private:
	int figCount;		//Actual number of figures
	cFigure* figList[MAX_FIG_COUNT];	//List of all figures (Array of pointers)

	cFigure* selectedFig; //Pointer to the selected figure
	cFigure* lastSelected;
	cFigure* lastCut;
	color lastDrawColor, lastFillColor;
	cFigure* clipboard;   //Pointer to the copied/cut figure

	bool isSoundON;
	//Pointers to Input and Output classes
	Input *pIn;
	Output *pOut;

public:
	ApplicationManager();
	~ApplicationManager();

	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType getUserAction() const;
	void executeAction(ActionType); //Creates an action and executes it

	// -- Figures Management Functions
	void addFigure(cFigure*);          //Adds a new figure to the FigList
	cFigure *getFigure(int , int) const; //Search for a figure given a point inside the figure
	void deleteFigure(cFigure*);	//Deletes a Figure from the List
	void clearFigures();		//Added a function to remove all figures
	void writeFigures(ofstream&);	//Saves Figure Information to a text file 
	void writeFigures(ofstream&, FigureType);	//Saves Figure Information of a certain Type to a text file 
	FigureType randomType() const;
	color randomColor() const;
	bool empty();
	bool hasFigure(FigureType) const;
	bool hasColor(color) const;
	void exit();

	// -- Interface Management Functions
	Input *getInput() const; //Return pointer to the input
	Output *getOutput() const; //Return pointer to the output
	void updateInterface() const;	//Redraws all the drawing window

	void setSelectedFigure(cFigure*);
	cFigure* getSelectedFigure() const;

	void setLastSelected(cFigure*);
	cFigure* getLastSelected() const;

	void setClipboard(cFigure*);
	cFigure* getClipboard() const;

	color getLastDrawClr() const;
	color getLastFillClr() const;
	void setLastDrawClr(color);
	void setLastFillClr(color);

	void bringToFront(cFigure*);
	void sendToBack(cFigure*);

	void setLastCut(cFigure*);
	cFigure* getLastCut() const;

	bool getSoundState() const;
	void toggleSound();
};

#endif