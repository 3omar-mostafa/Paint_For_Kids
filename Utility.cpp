#include "DEFS.h"
#include "ApplicationManager.h"

// Additional Functions:
string StoreType(FigureType T)
{
	switch (T)
	{
	case RECTANGLE:
		return "RECTANGLE";
		break;
	case TRIANGLE:
		return "TRIANGLE";
		break;
	case ELLIPSE:
		return "ELLIPSE";
		break;
	case RHOMBUS:
		return "RHOMBUS";
		break;
	case LINE:
		return "LINE";
		break;
	}
	return "";
}

FigureType ReadType(string Str)
{
	switch (Str[1])
	{
	case 'E':
		return RECTANGLE;
		break;
	case 'R':
		return TRIANGLE;
		break;
	case 'L':
		return ELLIPSE;
		break;
	case 'H':
		return RHOMBUS;
		break;
	case 'I':
		return LINE;
		break;
	}
	return EMPTY_TYPE;
}

string ColorData(color C)
{
	string Data;
	Data += to_string(int(C.ucRed)) + " " + to_string(int(C.ucGreen)) + " " + to_string(int(C.ucBlue));
	return Data;
}

color ReadColor(ifstream& in)
{
	int Red, Green, Blue;
	in >> Red >> Green >> Blue;
	return color(Red, Green, Blue);
}

void SetFigType(CFigure *& FP, FigureType T)
{
	Point P1, P2, P3;
	P1 = P2 = P3 = { 400,400 };
	GfxInfo dummy;
	switch (T)
	{
	case LINE:
		FP = new CLine(P1, P2, dummy);
		break;

	case RECTANGLE:
		FP = new CRectangle(P1, P2, dummy);
		break;

	case TRIANGLE:
		FP = new CTriangle(P1, P2, P3, dummy);
		break;

	case RHOMBUS:
		FP = new CRhombus(P1, dummy);
		break;

	case ELLIPSE:
		FP = new CEllipse(P1, dummy);
		break;
	}
}
