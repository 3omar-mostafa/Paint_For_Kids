#ifndef INPUT_H
#define INPUT_H

#include "..\DEFS.h"
#include "UI_Info.h" 
#include "..\CMUgraphicsLib\CMUgraphics.h"

class Output;   // forward declaration

class Input		//The application manager should have a pointer to this class
{
private:
	window *pWind;	//Pointer to the Graphics Window
public:
	Input(window *pW);		//Constructor
	void getPointClicked(int &x, int &y) const;//Get coordinate where user clicks
	string getString(Output* pO) const;	 //Returns a string entered by the user

	ActionType getUserAction() const; //Read the user click and map to an action
	ActionType getUserAction(Point &P) const;	//Added to replace GetPointClicked

};

#endif