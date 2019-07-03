#include "CFigure.h"

CFigure::CFigure(GfxInfo FigureGfxInfo)
{
	figGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	selected = false;
	cut = false;
}

void CFigure::setID(int ID)
{
	this->ID = ID;
}

void CFigure::setType(FigureType T)
{
	figType = T;
}

FigureType CFigure::getType() const
{
	return figType;
}

void CFigure::setSelected(bool s)
{
	selected = s;
}

bool CFigure::isSelected() const
{
	return selected;
}

void CFigure::setCut(bool c)
{
	cut = c;
}

bool CFigure::isCut() const
{
	return cut;
}

void CFigure::toggleSelection(){
	selected = !selected;
}
void CFigure::changeDrawColor(Color dColor)
{
	figGfxInfo.drawColor = dColor;
}

void CFigure::changeFillColor(Color fColor)
{
	figGfxInfo.isFilled = true;
	figGfxInfo.fillColor = fColor;
}

Color CFigure::getFillColor() const
{
	return figGfxInfo.fillColor;
}

Color CFigure::getDrawColor() const
{
	return figGfxInfo.drawColor;
}

void CFigure::setFilled( bool filled) {
	figGfxInfo.isFilled = filled;
}

bool CFigure::isFilled() const
{
	return figGfxInfo.isFilled;
}

void CFigure::changeBorderSize(int size)
{
	if(size > 0)
		figGfxInfo.borderSize = size;
}

int CFigure::getBorderSize() const
{
	return figGfxInfo.borderSize;
}