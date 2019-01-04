#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures/CEllipse.h"
#include "Figures/CLine.h"
#include "Figures/CRectangle.h"
#include "Figures/CRhombus.h"
#include "Figures/CTriangle.h"
#include "GUI/Input.h"
#include "GUI/Output.h"
#include "Actions/AddRectangleAction.h"
#include "Actions/AddTriangleAction.h"
#include "Actions/AddEllipseAction.h"
#include "Actions/AddRhombusAction.h"
#include "Actions/AddLineAction.h"
#include "Actions/ChangeDrawColor.h"
#include "Actions/ChangeFillColor.h"
#include "Actions/CopyAction.h"
#include "Actions/CutAction.h"
#include "Actions/PasteAction.h"
#include "Actions/LoadAction.h"
#include "Actions/SaveAction.h"
#include "Actions/SaveByTypeAction.h"
#include "Actions/SelectShapeAction.h"
#include "Actions/DeleteAction.h"
#include "Actions/ExitAction.h"
#include "Actions/ClearAction.h"
#include "Actions/ByShapeAction.h"
#include "Actions/ByColorAction.h"
#include "Actions/SendToBackAction.h"
#include "Actions/BringToFrontAction.h"
#include "Actions/ResizeAction.h"

//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MAX_FIG_COUNT = 200 };	//Max no of figures

private:
	int figCount;		//Actual number of figures
	CFigure* figList[MAX_FIG_COUNT];	//List of all figures (Array of pointers)

	CFigure* selectedFig; //Pointer to the selected figure
	CFigure* lastSelected;
	CFigure* lastCut;
	color lastDrawColor, lastFillColor;
	CFigure* clipboard;   //Pointer to the copied/cut figure

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
	void addFigure(CFigure*);          //Adds a new figure to the FigList
	CFigure *getFigure(int , int) const; //Search for a figure given a point inside the figure
	void deleteFigure(CFigure*);	//Deletes a Figure from the List
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

	void setSelectedFigure(CFigure*);
	CFigure* getSelectedFigure() const;

	void setLastSelected(CFigure*);
	CFigure* getLastSelected() const;

	void setClipboard(CFigure*);
	CFigure* getClipboard() const;

	color getLastDrawClr() const;
	color getLastFillClr() const;
	void setLastDrawClr(color);
	void setLastFillClr(color);

	void bringToFront(CFigure*);
	void sendToBack(CFigure*);

	void setLastCut(CFigure*);
	CFigure* getLastCut() const;

	bool getSoundState() const;
	void toggleSound();
};

#endif