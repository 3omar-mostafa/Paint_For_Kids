#include "Input.h"
#include "Output.h"


Input::Input(window* pW)
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int &x, int &y) const
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string Input::GetString(Output *pO) const
{
	string Label;
	char Key;
	while (1)
	{
		pWind->WaitKeyPress(Key);
		if (Key == 27)	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if (Key == 13)	//ENTER key is pressed
			return Label;
		if ((Key == 8) && (Label.size() >= 1))	//BackSpace is pressed
			Label.resize(Label.size() - 1);
		else
			Label += Key;
		if (pO)
			pO->PrintMessage(Label);
	}
}

//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction() const
{
	Point P;
	return GetUserAction(P);
}

ActionType Input::GetUserAction(Point & P) const
{
	int &x = P.x;
	int &y = P.y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if (UI.InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==

			int ClickedItemOrder = (x / UI.MenuItemWidth);

			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on
			if (x < (25 * UI.MenuActionWidth + 40) && x > 24 * UI.MenuActionWidth)
				return EXIT;
			else if (x < (ITM_FILL_COLOR)*UI.MenuItemWidth + 50 && x >(ITM_FILL_COLOR)*UI.MenuItemWidth)
				return CHNG_FILL_CLR;
			else if (x < (ITM_DRAW_COLOR)*UI.MenuItemWidth && x >(ITM_DRAW_COLOR)*UI.MenuItemWidth - 50)
				return CHNG_DRAW_CLR;
			else {
				switch (ClickedItemOrder)
				{
				case ITM_GAME:      return TO_PLAY;
				case ITM_RECT:      return DRAW_RECT;
				case ITM_TRIANGLE:  return DRAW_TRI;
				case ITM_CIRCLE:    return DRAW_ELLIPSE;
				case ITM_RHOMBUS:   return DRAW_RHOMBUS;
				case ITM_LINE:	    return DRAW_LINE;

				default: return EMPTY;	//A click on empty place in desgin toolbar
				}
			}

		}
		else if (x >= 0 && x < UI.MenuActionWidth) {
			int ClickedItemOrder = (y / UI.MenuActionWidth) - 1;

			switch (ClickedItemOrder)
			{
			case ITM_LOAD:return LOAD;
			case ITM_SAVE:return SAVE;
			case ITM_SAVE_TYPE:return SAVE_BY_TYPE;
			case ITM_COPY:return COPY;
			case ITM_CUT:return CUT;
			case ITM_PASTE:return PASTE;
			case ITM_DELETE:return DEL;
			case ITM_CLEAR:return CLEAR;
			case ITM_SELECT:return SELECT;


			default: return EMPTY;	//A click on empty place in desgin toolbar
			}

		}

		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;
	}
	else	//GUI is in PLAY mode
	{
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			if (x < UI.MenuItemWidth - 20)
				return TO_DRAW;
			else if (x < (10 * UI.MenuActionWidth + 80) && x>10 * UI.MenuActionWidth)
				return COL_CLR;
			else if (x < (12 * UI.MenuActionWidth + 80) && x>12 * UI.MenuActionWidth)
				return COL_SHP;
			else if (x < (22 * UI.MenuActionWidth + 80) && x > 22 * UI.MenuActionWidth)
				return EXIT;

			{
				///TODO:
				//perform checks similar to Draw mode checks above
				//and return the correspoding action
				return TO_PLAY;	//just for now. This should be updated
			}

		}
	}
}
/////////////////////////////////

Input::~Input()
{
}
