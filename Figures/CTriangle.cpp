#include "CTriangle.h"

CTriangle::CTriangle(Point A, Point B, Point C, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	P1 = A;
	P2 = B;
	P3 = C;
}

void CTriangle::Draw(Output* pOut) const
{
	//Call Output::DrawTriangle to draw a triangle on the screen	
	pOut->DrawTriangle(P1, P2, P3, FigGfxInfo, Selected);
}