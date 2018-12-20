#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"
#include <iostream>
#include <fstream>
using namespace std;

//This file contains some global constants and definitions to be used in the project.
enum ActionType //The actions supported (you can add more if needed)
{
	DRAW_LINE,		//Draw Line
	DRAW_RECT,		//Draw Rectangle
	DRAW_TRI,		//Draw Triangle
	DRAW_RHOMBUS,		//Draw Rhombus
	DRAW_ELLIPSE,		//Draw Ellipse
	CHNG_DRAW_CLR,	//Change the drawing color
	CHNG_FILL_CLR,	//Change the filling color
	DEL,			//Delete a figure(s)
	CLEAR,			//Clear Drawing Area
	SAVE,			//Save the whole graph to a file
	SAVE_BY_TYPE,	//Save the all the figures that have a specific type
	LOAD,			//Load a graph from a file
	EXIT,			//Exit the application
	COPY,
	CUT,
	PASTE,
	SELECT,
	SEND_TO_BACK,
	BRING_TO_FRONT,
	DRAWING_AREA,	//A click on the drawing area
	STATUS,			//A click on the status bar
	EMPTY,          //A click on empty place in the toolbar
	COL_CLR,
	COL_SHP,
	TO_DRAW,		//Switch interface to Draw mode
	TO_PLAY			//Switch interface to Play mode

	///TODO: Add more action types (if needed)
};

enum FigureType
{
	EMPTY_TYPE,
	RECTANGLE,
	TRIANGLE,
	ELLIPSE,
	RHOMBUS,
	LINE
};


//	Additional Functions:
string StoreType(FigureType T);		//Stores the type of a figure into a string format
const auto Display = StoreType;		//Alias for the function StoreType
FigureType ReadType(string Str);	//Determines the type of a figure from a string format
string ColorData(color C);			//Stores the information for a color into a string
color ReadColor(ifstream& in);		//Reads a color's info from a string


struct Point	//To be used for figures points
{
	int x, y;
	string Data()
	{
		string Data;
		Data += to_string(x) + " " + to_string(y);
		return Data;
	}

	void Read(ifstream& in)
	{
		int X, Y;
		in >> X >> Y;
		x = X;
		y = Y;
	}

	Point operator+(Point P)
	{
		Point S;
		S.x = x + P.x;
		S.y = y + P.y;
		return S;
	}

	Point& operator/(float R)
	{
		x /= R;
		y /= R;
		return *this;
	}
};

struct GfxInfo	//Graphical info of each figure (you may add more members)
{
	color DrawClr;	//Draw color of the figure
	color FillClr;	//Fill color of the figure
	bool isFilled;	//Figure Filled or not
	int BorderWdth = 8;	//Width of figure borders
	string Data()
	{
		string Data;
		Data += ColorData(DrawClr) + " " + ColorData(FillClr) + " ";
		Data += to_string((isFilled) ? 1 : 0);
		Data += " " + to_string(BorderWdth);
		return Data;
	}
	void Read(ifstream& in)
	{
		int Filled;
		int Width;
		DrawClr = ReadColor(in);
		FillClr = ReadColor(in);
		in >> Filled >> Width;
		isFilled = Filled;
		BorderWdth = Width;
	}
};

#endif