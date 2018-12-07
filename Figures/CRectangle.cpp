#include "CRectangle.h"

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}

Point CRectangle::getP1(){
	return Corner1 ;
}
Point CRectangle::getP2(){
	return Corner2 ;
}

void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}

bool CRectangle::doesItContain(int x, int y) {
	int x1 = Corner1.x;
	int y1 = Corner1.y;
	int x2 = Corner2.x;
	int y2 = Corner2.y;
	if (x1 > x2)
		swap(x1, x2);
	if (y1 > y2)
		swap(y1, y2);

	if (isFilled()) {
		if (x >= x1 && x <= x2 && y >= y1 && y <= y2) {
			return true;
		}
	}
	else {
		if ((((x >= x1 - 3 && x <= x1 + 3) || (x >= x2 - 3 && x <= x2 + 3)) && (y > y1 - 5 && y < y2 + 5)) || ((y >= y1 - 3 && y <= y1 + 3) || (y >= y2 - 3 && y <= y2 + 3)) && (x > x1 - 5 && x < x2 + 5)) {
			return true;
		}
	}

	return false;
}

string CRectangle::getInfo() {
	string s;
	s = "ID :" + to_string(ID) + " Points : ( " + to_string(Corner1.x) + " , " + to_string(Corner1.y) + " ) , ( " + to_string(Corner2.x) + " , " + to_string(Corner2.y) + " ) , ";
	s += "Length : " + to_string(abs(Corner1.x - Corner2.x)) + " Width : " + to_string(abs(Corner1.y - Corner2.y));
	return s;
}