#ifndef C_FIGURE_H
#define C_FIGURE_H

#include "..\defs.h"
#include "..\GUI\Output.h"

//Base class for all figures
class CFigure
{
protected:
	int ID;					//Each figure has an ID
	FigureType figType;		//Each figure has a figure type.
	bool selected;			//True if the figure is selected.
	GfxInfo figGfxInfo;		//Figure graphics info

	bool cut;
	/// Add more parameters if needed.

public:
	CFigure(GfxInfo );

	void setID(int);
	void setType(FigureType);
	FigureType getType() const;

	void setSelected(bool s);	//select/unselect the figure
	bool isSelected() const;	//check whether fig is selected
	void toggleSelection();

	void setCut(bool);
	bool isCut() const;

	virtual void draw(Output* ) const = 0;		//Draw the figure

	void changeDrawColor(color );	//changes the figure's drawing color
	void changeFillColor(color );	//changes the figure's filling color
	color getFillColor() const;
	color getDrawColor() const;

	bool isFilled() const;
	void setFilled(bool );
	virtual bool doesItContain(int, int) = 0;

	virtual bool resize(double) = 0;

	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure

	///Decide the parameters that you should pass to each function	


	virtual void save(ofstream & ) = 0;	//Save the figure parameters to the file
	virtual void load(ifstream & ) = 0;	//Load the figure parameters to the file

	virtual void printInfo(Output* ) = 0;	//print all figure info on the status bar
};

void setFigType(CFigure *& FP, FigureType T);	//Takes a CFigure* and creates a dummy object of a passed FigureType

#endif