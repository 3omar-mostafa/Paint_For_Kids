#ifndef OUTPUT_H
#define OUTPUT_H
#include "Input.h"
#include "../Actions/UndoRedoAction.h"
#include "../Colors/ColorsHeader.h"
#include <vector>

class Output	//The application manager should have a pointer to this class
{
	window* pWind;	//Pointer to the Graphics Window
	bool filled;
	static vector<vector<Color>> colors;
public:
	Output();

	window* createWindow(int, int, int, int) const; //creates the application window
	void createDrawToolBar() const;	//creates Draw mode toolbar & menu
	void createDrawActionToolBar() const; // creates Draw mode Action bar
	void removeDrawActionToolBar() const; // deletes Draw mode Action bar
	void createPlayToolBar() const;	//creates Play mode toolbar & menu
	void createStatusBar() const;	//create the status bar

	Input* createInput() const; //creates a pointer to the Input object	
	void clearStatusBar() const;	//Clears the status bar
	void clearDrawArea() const;	//Clears the drawing area

	// -- Figures Drawing functions
	void drawRectangle(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected = false) const;  //Draw a rectangle
	void drawEllipse(Point P1, Point P2, GfxInfo ElpsGfxInfo, bool selected = false) const;	//Draws the Ellipse using the rectangle that bounds it
	void drawTriangle(Point P1, Point P2, Point P3, GfxInfo TriGfxInfo, bool selected = false) const;
	void drawLine(Point P1, Point P2, GfxInfo LineGfxInfo, bool selected = false) const;
	void drawRhombus(const int* X, const int* Y, GfxInfo RhomGfxInfo, bool selected) const;	//Draws the Rhombus using two array of the respective coordinates of its 4 vertices
	drawstyle getDrawingStyle(GfxInfo , bool) const;

	void printMessage(string msg) const;	//Print a message on Status bar

	static Color getCurrentDrawColor();	//get current drawing color
	static Color getCurrentFillColor();	//get current filling color
	static int getCurrentBorderSize();		//get current border size
	static void setCurrentBorderSize(int);

	void createBorderSizeIcon() const;
	void drawBorderSizeMenu() const;
	int selectBorderSize(Point) const;
	void changeBorderSizeIcon(int) const;

	void drawOnToolbar(string, int) const;
	void drawOnActionbar(string, int) const;

	void drawResizeMenu() const;
	static double selectSize(Point p);

	void playOnToolbar(string, int) const;

	void createColorIcons();
	void drawUndoRedoIcons(UndoRedoAction::MODES , bool ) const;
	void drawFillColorMenu() const;
	void drawDrawingColorMenu() const;

	void getValidPoint(Point&) const;
	void getValidEllipsePoint(Point&) const;
	void getValidRhombusPoint(Point&) const;

	Color selectFillColor(Point);
	Color selectDrawColor(Point) const;

	void changeFillColorIcon(Color, bool);
	void changeDrawColorIcon(Color) const;

	Color static getColorType(int, int, int);
	bool isFilled() const;

	void drawSoundIcon(bool) const;

	~Output();
};

#endif