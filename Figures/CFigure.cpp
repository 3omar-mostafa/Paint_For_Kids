#include "CFigure.h"

CFigure::CFigure(GfxInfo FigureGfxInfo)
{
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
}

void CFigure::setID(int ID)
{
	this->ID = ID;
}

void CFigure::setType(FigureType T)
{
	FigType = T;
}

FigureType CFigure::getType() const
{
	return FigType;
}

void CFigure::SetSelected(bool s)
{
	Selected = s;
}

bool CFigure::IsSelected() const
{
	return Selected;
}
void CFigure::toggleSelection(){
	Selected = !Selected;
}
void CFigure::ChngDrawClr(color Dclr)
{
	FigGfxInfo.DrawClr = Dclr;
}

void CFigure::ChngFillClr(color Fclr)
{
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr;
}

color CFigure::getFillColor() {
	return FigGfxInfo.FillClr;
}

color CFigure::getDrawColor() {
	return FigGfxInfo.DrawClr;
}

void CFigure::setFilled( bool filled) {
	FigGfxInfo.isFilled = filled;
}

bool CFigure::isFilled() {
	return FigGfxInfo.isFilled;
}
