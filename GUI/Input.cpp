#include "Input.h"
#include "Output.h"


Input::Input(window* pW)
{
	pWind = pW; //point to the passed window
}

void Input::getPointClicked(int &x, int &y) const
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string Input::getString(Output *pO) const
{
	string label;
	char key;
	while (true)
	{
		pWind->WaitKeyPress(key);
		if (key == 27)	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if (key == 13)	//ENTER key is pressed
			return label;
		if ((key == 8) && !label.empty() )	//BackSpace is pressed
			label.resize(label.size() - 1);
		else
			label += key;
		if (pO)
			pO->printMessage(label);
	}
}

//This function reads the position where the user clicks to determine the desired action
ActionType Input::getUserAction() const
{
	Point P;
	return getUserAction(P);
}

ActionType Input::getUserAction(Point & P) const
{
	int &x = P.x;
	int &y = P.y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if (y >= 0 && y < UI.ToolBarHeight) {
		if (x > UI.width - UI.MenuItemWidth )
			return EXIT;
		if (x > UI.width - 3*UI.MenuActionWidth && x < UI.width - UI.MenuItemWidth)
			return SOUND;
	}

	if (UI.InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			if (x > UI.width - 5 * UI.MenuActionWidth && x < UI.width - 4 * UI.MenuActionWidth)
				return UNDO;
			if (x > UI.width - 4 * UI.MenuActionWidth && x < UI.width - 3 * UI.MenuActionWidth)
				return REDO;

			//Check which Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==

			int ClickedItemOrder = (x / UI.MenuItemWidth);

			//Divide x coordinate of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on
			if (x < (ITM_FILL_COLOR)*UI.MenuItemWidth + 50 && x >(ITM_FILL_COLOR)*UI.MenuItemWidth)
				return CHANGE_FILL_COLOR;
			if (x < (ITM_DRAW_COLOR)*UI.MenuItemWidth && x >(ITM_DRAW_COLOR)*UI.MenuItemWidth - 50)
				return CHANGE_DRAW_COLOR;


			switch (ClickedItemOrder)
			{
				case ITM_GAME:      return TO_PLAY;
				case ITM_RECTANGLE:      return DRAW_RECT;
				case ITM_TRIANGLE:  return DRAW_TRI;
				case ITM_ELLIPSE:    return DRAW_ELLIPSE;
				case ITM_RHOMBUS:   return DRAW_RHOMBUS;
				case ITM_LINE:	    return DRAW_LINE;
				case ITM_BORDER_SIZE: return BORDER_SIZE;

				default: return EMPTY;	//A click on empty place in design toolbar
			}

		}
		else if (x >= 0 && x < UI.MenuActionWidth)
		{
			int clickedItemOrder = (y / UI.MenuActionWidth) - 1;

			switch (clickedItemOrder)
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
			case ITM_SEND_TO_BACK:return SEND_TO_BACK;
			case ITM_BRING_TO_FRONT:return BRING_TO_FRONT;
			case ITM_RESIZE:return RESIZE;


			default: return EMPTY;	//A click on empty place in design toolbar
			}

		}

		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight && x>= UI.MenuActionWidth)
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
				return PLAY_COLOR;
			else if (x < (12 * UI.MenuActionWidth + 80) && x>12 * UI.MenuActionWidth)
				return PLAY_SHAPE;
		}
	}
}