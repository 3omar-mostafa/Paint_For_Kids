#ifndef OUPTUT_H
#define OUPTUT_H
#include "Input.h"

class Output	//The application manager should have a pointer to this class
{
private:
	window* pWind;	//Pointer to the Graphics Window
public:
	Output();

	window* CreateWind(int, int, int, int) const; //creates the application window
	void CreateDrawToolBar() const;	//creates Draw mode toolbar & menu
	void CreateDrawActionToolBar() const; // creates Draw mode Action bar
	void removeDrawActionToolBar() const; // deletes Draw mode Action bar
	void CreatePlayToolBar() const;	//creates Play mode toolbar & menu
	void CreateStatusBar() const;	//create the status bar

	Input* CreateInput() const; //creates a pointer to the Input object	
	void ClearStatusBar() const;	//Clears the status bar
	void ClearDrawArea() const;	//Clears the drawing area

	// -- Figures Drawing functions
	void DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected = false) const;  //Draw a rectangle
	void DrawCircle(Point P1, Point P2, GfxInfo CircleGfxInfo, bool selected = false) const;
	void DrawEllipse(Point P, GfxInfo ElpsGfxInfo, bool selected = false) const;
	void DrawTriangle(Point P1, Point P2, Point P3, GfxInfo TriGfxInfo, bool selected = false) const;
	void DrawLine(Point P1, Point P2, GfxInfo LineGfxInfo, bool selected = false) const;
	void DrawRhombus(Point P, GfxInfo RhomGfxInfo, bool selected = false) const;

	///Make similar functions for drawing all other figure types.

	void PrintMessage(string msg) const;	//Print a message on Status bar

	color getCrntDrawColor() const;	//get current drwawing color
	color getCrntFillColor() const;	//get current filling color
	int getCrntPenWidth() const;		//get current pen width

	void drawOnToolbar(string, int) const;
	void drawOnActionbar(string, int) const;
	void playOnToolbar(string, int) const;

	void CreateColorIcons() const;
	void drawColorMenu() const;
	void deleteColorMenu() const;

	Point getValidPoint() const;
	Point getValidEllipsePoint() const;
	Point getValidRhombusPoint() const;

	void selectFillColor(Point, color &, bool &) const;
	void selectDrawColor(Point, color &) const;

	~Output();
};

#endif