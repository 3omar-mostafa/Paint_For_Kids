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
	while(1)
	{
		pWind->WaitKeyPress(Key);
		if(Key == 27 )	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if(Key == 13 )	//ENTER key is pressed
			return Label;
		if((Key == 8) && (Label.size() >= 1))	//BackSpace is pressed
			Label.resize(Label.size() -1 );			
		else
			Label += Key;
		if (pO)
			pO->PrintMessage(Label);
	}
}

//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction() const
{	
	int x,y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if(UI.InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
		//[1] If user clicks on the Toolbar
		if ( y >= 0 && y < UI.ToolBarHeight)
		{	
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==

			//ClickedItemOrder = (x / UI.MenuItemWidth);

			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			// Omar :
			// I've changed this logic because I made buttons that have different widths

			
			if (x < UI.MenuItemWidth)
				return TO_PLAY;
			else if (x < DRAW_ACTION_COUNT * UI.MenuActionWidth + 50) {
				int ClickedItemOrder = ( (x - 50) / UI.MenuActionWidth);
				switch (ClickedItemOrder)
				{
				case ITM_SAVE :return SAVE;
				case ITM_COPY :return COPY;
				case ITM_DELETE :return DEL;
				case ITM_FILL_COLOR :return CHNG_FILL_CLR;
				case ITM_DRAW_COLOR :return CHNG_DRAW_CLR;

				default: return EMPTY;	//A click on empty place in desgin toolbar
				}
			}else{
				int ClickedItemOrder = (DRAW_ACTION_COUNT + 1 + (x - 50 - DRAW_ACTION_COUNT*UI.MenuActionWidth) / UI.MenuItemWidth);

				switch (ClickedItemOrder)
				{
				case ITM_RECT: return DRAW_RECT;
				case ITM_EXIT: return EXIT;
				case ITM_TRIANGLE: return DRAW_TRI;
				case ITM_CIRCLE:   return DRAW_ELLIPSE;
				case ITM_RHOMBUS:  return DRAW_RHOMBUS;
				case ITM_LINE:	   return DRAW_LINE;

				default: return EMPTY;	//A click on empty place in desgin toolbar
				}
			}
		}

		//[2] User clicks on the drawing area
		if ( y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;	
		}
		
		//[3] User clicks on the status bar
		return STATUS;
	}
	else	//GUI is in PLAY mode
	{
		///TODO:
		//perform checks similar to Draw mode checks above
		//and return the correspoding action
		return TO_PLAY;	//just for now. This should be updated
	}	

}
/////////////////////////////////
	
Input::~Input()
{
}
