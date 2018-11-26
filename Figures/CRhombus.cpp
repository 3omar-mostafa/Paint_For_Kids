#include "CRhombus.h"

CRhombus::CRhombus(Point P, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = P;
}


void CRhombus::Draw(Output* pOut) const
{
	//Call Output::DrawRhombus to draw a rhombus on the screen	
	pOut->DrawRhombus(Center, FigGfxInfo, Selected);
}