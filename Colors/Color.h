#pragma once
#include <string>
#include "../CMUgraphicsLib/colors.h"

using namespace std;

class Color
{
protected:
	string name , drawColorIcon , fillColorIcon;
	color c;
public:

	explicit Color(color c);
	explicit Color(unsigned char red = 0, unsigned char green = 0, unsigned char blue = 0);

	virtual string getDrawColorIcon() const;
	virtual void setDrawColorIcon(const string& drawColorIcon);
	
	virtual string getFillColorIcon() const;
	virtual void setFillColorIcon(const string& fillColorIcon);

	virtual color getColor() const;
	virtual void setColor(color c);

	virtual string getName() const;
	virtual void setName(string);

	virtual string getRGB() const;

	bool operator==(const Color& right) const;
	bool operator!=(const Color& right) const;
};