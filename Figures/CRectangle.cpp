#include "CRectangle.h"

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	FigType = RECTANGLE;
}

Point CRectangle::getP1()
{
	return Corner1;
}
Point CRectangle::getP2()
{
	return Corner2;
}

void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}

bool CRectangle::doesItContain(int x, int y)
{
	int x1 = Corner1.x;
	int y1 = Corner1.y;
	int x2 = Corner2.x;
	int y2 = Corner2.y;
	if (x1 > x2)
		swap(x1, x2);
	if (y1 > y2)
		swap(y1, y2);

	if (x >= x1 && x <= x2 && y >= y1 && y <= y2) 
	{
		return true;
	}

	return false;
}

void CRectangle::Save(ofstream &OutFile)
{
	string Info = StoreType(FigType) + " " + to_string(ID) + " " + Corner1.Data() + " " + Corner2.Data() + " "+ FigGfxInfo.Data();
	OutFile << endl << Info;
}

void CRectangle::Load(ifstream &InFile)
{
	Point P1, P2;
	GfxInfo RectGfxInfo;
	InFile >> ID;
	P1.Read(InFile);
	P2.Read(InFile);
	RectGfxInfo.Read(InFile);
	*this = CRectangle(P1, P2, RectGfxInfo);
}

void CRectangle::PrintInfo(Output * pOut)
{
	string s;
	s = "ID: " + to_string(ID) + "    Points: (" + to_string(Corner1.x) + ", " + to_string(Corner1.y) + "), (" + to_string(Corner2.x) + ", " + to_string(Corner2.y) + ")    ";
	s += "Length: " + to_string(abs(Corner1.x - Corner2.x)) + "    Width: " + to_string(abs(Corner1.y - Corner2.y));
	pOut->PrintMessage(s);
}
