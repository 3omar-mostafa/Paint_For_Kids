#include "Color.h"

Color::Color(color c) : c(c) {}

Color::Color(unsigned char red, unsigned char green, unsigned char blue)
{
	c.ucRed = red;  c.ucGreen = green;  c.ucBlue = blue;
}

string Color::getDrawColorIcon() const
{
	return drawColorIcon;
}

void Color::setDrawColorIcon(const string& drawColorIcon)
{
	this->drawColorIcon = drawColorIcon;
}

string Color::getFillColorIcon() const
{
	return fillColorIcon;
}

void Color::setFillColorIcon(const string& fillColorIcon)
{
	this->fillColorIcon = fillColorIcon;
}

color Color::getColor() const
{
	return c;
}

void Color::setColor(color c)
{
	this->c = c;
}

string Color::getName() const
{
	return name;
}

void Color::setName(string name)
{
	this->name = name;
}

string Color::getRGB() const
{
	return to_string(int(c.ucRed)) + " " + to_string(int(c.ucGreen)) + " " + to_string(int(c.ucBlue));
}

bool Color::operator==(const Color& right)const
{
	return c == right.c;
}

bool Color::operator!=(const Color& right) const
{
	return c != right.c;
}
