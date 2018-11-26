#include "CEllipse.h"

CEllipse::CEllipse(Point P, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = P;
}


void CEllipse::Draw(Output* pOut) const
{
	//Call Output::DrawEllipse to draw a rhombus on the screen	
	pOut->DrawEllipse(Center, FigGfxInfo, Selected);
}