#include "DEFS.h"
#include "ApplicationManager.h"

//==================================================================================//
//							Additional Utility Functions							//
//==================================================================================//

//Stores the type of a figure into a string format
string storeType(FigureType T)
{
	switch (T)
	{
	case RECTANGLE:
		return "RECTANGLE";
	case TRIANGLE:
		return "TRIANGLE";
	case ELLIPSE:
		return "ELLIPSE";
	case RHOMBUS:
		return "RHOMBUS";
	case LINE:
		return "LINE";
	default:
		return "";
	}
}

//Determines the type of a figure from a string format
FigureType readType(string Str)
{
	switch (Str[1])
	{
	case 'E':
		return RECTANGLE;
	case 'R':
		return TRIANGLE;
	case 'L':
		return ELLIPSE;
	case 'H':
		return RHOMBUS;
	case 'I':
		return LINE;
	default:
		return EMPTY_TYPE;
	}
}

//Stores the information for a color into a string
string colorData(Color c)
{
	return c.getRGB();
}

//Reads a color's info from a string
Color readColor(ifstream& in)
{
	int Red, Green, Blue;
	in >> Red >> Green >> Blue;
	return Output::getColorType(Red, Green, Blue);
}

//Takes a CFigure* and creates a dummy object of a passed FigureType
void setFigType(CFigure *& FP, FigureType T)
{
	Point p1, p2, p3;
	p1 = p2 = p3 = Point(400, 400);
	GfxInfo dummy;
	switch (T)
	{
	case LINE:
		FP = new CLine(p1, p2, dummy);
		break;

	case RECTANGLE:
		FP = new CRectangle(p1, p2, dummy);
		break;

	case TRIANGLE:
		FP = new CTriangle(p1, p2, p3, dummy);
		break;

	case RHOMBUS:
		FP = new CRhombus(p1, dummy);
		break;

	case ELLIPSE:
		FP = new CEllipse(p1, dummy);
		break;
	}
}
