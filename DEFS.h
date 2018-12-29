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
	CHANGE_DRAW_COLOR,	//Change the drawing color
	CHANGE_FILL_COLOR,	//Change the filling color
	DEL,			//Delete a figure(s)
	CLEAR,			//Clear Drawing Area
	SAVE,			//Save the whole graph to a file
	SAVE_BY_TYPE,	//Save the all the figures that have a specific type
	LOAD,			//Load a graph from a file
	EXIT,			//Exit the application
	SOUND,
	COPY,
	CUT,
	PASTE,
	SELECT,
	SEND_TO_BACK,
	BRING_TO_FRONT,
	RESIZE,
	DRAWING_AREA,	//A click on the drawing area
	STATUS,			//A click on the status bar
	EMPTY,          //A click on empty place in the toolbar
	PLAY_COLOR,
	PLAY_SHAPE,
	TO_DRAW,		//Switch interface to Draw mode
	TO_PLAY			//Switch interface to Play mode
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
string storeType(FigureType T);		//Stores the type of a figure into a string format
const auto display = storeType;		//Alias for the function StoreType
FigureType readType(string Str);	//Determines the type of a figure from a string format
string colorData(color C);			//Stores the information for a color into a string
color readColor(ifstream& in);		//Reads a color's info from a string


struct Point	//To be used for figures points
{
	int x, y;
	
	Point()
	{}
	
	Point(int X, int Y)
	{
		this->x = X;
		this->y = Y;
	}
	
	string data() const
	{
		string data;
		data += to_string(x) + " " + to_string(y);
		return data;
	}

	void read(ifstream& in)
	{
		int X, Y;
		in >> X >> Y;
		x = X;
		y = Y;
	}

	Point operator+(Point P) const
	{
		Point s;
		s.x = x + P.x;
		s.y = y + P.y;
		return s;
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
	color drawColor;	//Draw color of the figure
	color fillColor;	//Fill color of the figure
	bool isFilled;	//Figure Filled or not
	int borderWidth;	//Width of figure borders
	string data() const
	{
		string Data;
		Data += colorData(drawColor) + " " + colorData(fillColor) + " ";
		Data += to_string((isFilled) ? true : false);
		return Data;
	}
	void read(ifstream& in)
	{
		int filled;
		drawColor = readColor(in);
		fillColor = readColor(in);
		in >> filled;
		isFilled = filled;
	}
};

#endif