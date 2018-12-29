#include "CFigure.h"

cFigure::cFigure(GfxInfo FigureGfxInfo)
{
	figGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	selected = false;
	cut = false;
}

void cFigure::setID(int ID)
{
	this->ID = ID;
}

void cFigure::setType(FigureType T)
{
	figType = T;
}

FigureType cFigure::getType() const
{
	return figType;
}

void cFigure::setSelected(bool s)
{
	selected = s;
}

bool cFigure::isSelected() const
{
	return selected;
}

void cFigure::setCut(bool c)
{
	cut = c;
}

bool cFigure::isCut() const
{
	return cut;
}

void cFigure::toggleSelection(){
	selected = !selected;
}
void cFigure::changeDrawColor(color dColor)
{
	figGfxInfo.drawColor = dColor;
}

void cFigure::changeFillColor(color fColor)
{
	figGfxInfo.isFilled = true;
	figGfxInfo.fillColor = fColor;
}

color cFigure::getFillColor() const
{
	return figGfxInfo.fillColor;
}

color cFigure::getDrawColor() const
{
	return figGfxInfo.drawColor;
}

void cFigure::setFilled( bool filled) {
	figGfxInfo.isFilled = filled;
}

bool cFigure::isFilled() const
{
	return figGfxInfo.isFilled;
}

