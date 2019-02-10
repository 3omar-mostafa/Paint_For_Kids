#include "Output.h"
#include "../Actions/UndoRedoAction.h"


Output::Output()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;

	UI.width = 1350;
	UI.height = 700;
	UI.wx = 5;
	UI.wy = 5;


	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 50;
	UI.MenuItemWidth = 100;
	UI.MenuActionWidth = 50;

	UI.DrawColor = BLACK;	//Drawing color
	UI.FillColor = BLACK;	//Filling color
	UI.MessageColor = WHITESMOKE;		//Messages color
	UI.BackgroundColor = GAINSBORO;	//Background color
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = STEELBLUE;
	UI.BorderSize = 5;	//width of the figures frames

	filled = true;
	//Create the output window
	pWind = createWindow(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project");


	createDrawToolBar();
	createDrawActionToolBar();
	createColorIcons();
	createStatusBar();
	createBorderSizeIcon();
	drawUndoRedoIcons(UndoRedoAction::MODE_UNDO,false);
	drawUndoRedoIcons(UndoRedoAction::MODE_REDO,false);

	//draw sound icon
	pWind->DrawImage("images\\MenuItems\\Menu_sound_ON.jpg", UI.width - 3*UI.MenuActionWidth, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
}


Input* Output::createInput() const
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::createWindow(int w, int h, int x, int y) const
{
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BackgroundColor);
	pW->SetPen(UI.BackgroundColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::createStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::clearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::createDrawToolBar() const
{
	UI.InterfaceMode = MODE_DRAW;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way

	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string menuItemImages[DRAW_ITM_COUNT];
	menuItemImages[ITM_GAME] = "images\\MenuItems\\Menu_game.jpg";
	menuItemImages[ITM_RECTANGLE] = "images\\MenuItems\\Menu_Rect.jpg";
	menuItemImages[ITM_TRIANGLE] = "images\\MenuItems\\Menu_Triangle.jpg";
	menuItemImages[ITM_ELLIPSE] = "images\\MenuItems\\Menu_Circ.jpg";
	menuItemImages[ITM_RHOMBUS] = "images\\MenuItems\\Menu_Rhombus.jpg";
	menuItemImages[ITM_LINE] = "images\\MenuItems\\Menu_Line.jpg";
	menuItemImages[ITM_EXIT] = "images\\MenuItems\\Menu_Exit.jpg";

	//Draw menu item one image at a time
	for (int i = 0; i <= ITM_LINE; i++)
		pWind->DrawImage(menuItemImages[i], i *UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight - 3);

	// clean white spaces in toolbar
	// pWind->DrawImage("images\\MenuItems\\clean.jpg", 22 * UI.MenuActionWidth, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);

	//draw Exit icon
	pWind->DrawImage(menuItemImages[ITM_EXIT], UI.width - UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight - 3);


	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight - 1.5, UI.width, UI.ToolBarHeight - 1.5);

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::createDrawActionToolBar()  const
{
	UI.InterfaceMode = MODE_DRAW;

	string menuActionsImages[DRAW_ACTION_COUNT];
	menuActionsImages[ITM_LOAD] = "images\\MenuItems\\Menu_Load.jpg";
	menuActionsImages[ITM_SAVE] = "images\\MenuItems\\Menu_save.jpg";
	menuActionsImages[ITM_SAVE_TYPE] = "images\\MenuItems\\Menu_save_type.jpg";
	menuActionsImages[ITM_COPY] = "images\\MenuItems\\Menu_copy.jpg";
	menuActionsImages[ITM_CUT] = "images\\MenuItems\\Menu_Cut.jpg";
	menuActionsImages[ITM_PASTE] = "images\\MenuItems\\Menu_Paste.jpg";
	menuActionsImages[ITM_DELETE] = "images\\MenuItems\\Menu_delete.jpg";
	menuActionsImages[ITM_CLEAR] = "images\\MenuItems\\Menu_Clear_All.jpg";
	menuActionsImages[ITM_SELECT] = "images\\MenuItems\\Menu_Select.jpg";
	menuActionsImages[ITM_SEND_TO_BACK] = "images\\MenuItems\\Menu_send_to_back.jpg";
	menuActionsImages[ITM_BRING_TO_FRONT] = "images\\MenuItems\\Menu_bring_to_front.jpg";
	menuActionsImages[ITM_RESIZE] = "images\\MenuItems\\Menu_Resize.jpg";


	//Draw menu action one image at a time
	for (int i = 0; i < DRAW_ACTION_COUNT; i++)
		pWind->DrawImage(menuActionsImages[i], 0, (i + 1)*UI.ToolBarHeight, UI.MenuActionWidth - 3, UI.ToolBarHeight);

	//Draw a line next to Action Menu
	pWind->SetPen(RED, 3);
	pWind->DrawLine(UI.MenuActionWidth - 1.5, UI.ToolBarHeight, UI.MenuActionWidth - 1.5, UI.height - UI.StatusBarHeight);
}

void Output::removeDrawActionToolBar() const
{
	pWind->SetPen(UI.BackgroundColor, 1);
	pWind->SetBrush(UI.BackgroundColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.MenuActionWidth, UI.height - UI.StatusBarHeight);
}
void Output::createColorIcons()
{
	pWind->DrawImage("images\\MenuItems\\colors\\Menu_fill_color_black.jpg", (ITM_FILL_COLOR)*UI.MenuItemWidth, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
	pWind->DrawImage("images\\MenuItems\\colors\\Menu_draw_color_black.jpg", (ITM_DRAW_COLOR)*UI.MenuItemWidth - 50, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
	UI.FillColor = BLACK;
	UI.DrawColor = BLACK;
	filled = true;
}

void Output::drawUndoRedoIcons(UndoRedoAction::MODES mode , bool isAvailable) const
{
	if( mode == UndoRedoAction::MODE_UNDO)
		if(isAvailable)
			pWind->DrawImage("images\\MenuItems\\Menu_undo.jpg", UI.width - 5 * UI.MenuActionWidth, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
		else
			pWind->DrawImage("images\\MenuItems\\Menu_undo_no.jpg", UI.width - 5 * UI.MenuActionWidth, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
	else
		if (isAvailable)
			pWind->DrawImage("images\\MenuItems\\Menu_redo.jpg", UI.width - 4 * UI.MenuActionWidth, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
		else
			pWind->DrawImage("images\\MenuItems\\Menu_redo_no.jpg", UI.width - 4 * UI.MenuActionWidth, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
}

void Output::drawOnToolbar(string path, int place) const
{
	pWind->DrawImage(path, place * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight - 3);
}

void Output::drawOnActionbar(string path, int place) const
{
	pWind->DrawImage(path, 0, (place + 1) * UI.MenuActionWidth, UI.MenuActionWidth - 3, UI.ToolBarHeight);
}

void Output::drawSoundIcon(bool on) const
{
	if (on)
		pWind->DrawImage("images\\MenuItems\\Menu_sound_ON.jpg", UI.width - 3 * UI.MenuActionWidth, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
	else
		pWind->DrawImage("images\\MenuItems\\Menu_sound_OFF.jpg", UI.width - 3 * UI.MenuActionWidth, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
}

void Output::drawResizeMenu() const
{
	pWind->DrawImage("images\\MenuItems\\sizes.jpg", UI.MenuActionWidth, UI.MenuActionWidth* DRAW_ACTION_COUNT, UI.MenuActionWidth * 4, UI.ToolBarHeight);
}

double Output::selectSize(Point p)
{
	if (p.y > UI.ToolBarHeight * DRAW_ACTION_COUNT && p.y < UI.height - UI.StatusBarHeight ) {
		int selectSize = p.x / UI.MenuActionWidth;
		switch (selectSize)
		{
		case 1:
			return 0.25;
		case 2:
			return 0.5;
		case 3:
			return 2;
		case 4:
			return 4;
		}
	}
	return 1; // 1 because its size is not affected
}

void Output::drawFillColorMenu() const
{
	pWind->DrawImage("images\\MenuItems\\colors\\colors_fill.jpg", UI.MenuItemWidth* ITM_FILL_COLOR, UI.ToolBarHeight, UI.MenuItemWidth, UI.MenuActionWidth * 12);
}

void Output::drawDrawingColorMenu() const
{
	pWind->DrawImage("images\\MenuItems\\colors\\colors_draw.jpg", UI.MenuItemWidth* ITM_FILL_COLOR, UI.ToolBarHeight, UI.MenuItemWidth, UI.MenuActionWidth * 11);
}

color Output::selectFillColor(Point p) {

	// checks if the user chooses no fill color 
	if (p.y > 12*UI.ToolBarHeight && p.y < 13*UI.ToolBarHeight && p.x > UI.MenuItemWidth*ITM_FILL_COLOR && p.x < UI.MenuItemWidth*ITM_DRAW_COLOR) {
		pWind->DrawImage("images\\MenuItems\\colors\\Menu_fill_color_No.jpg", (ITM_FILL_COLOR)*UI.MenuItemWidth, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
		filled = false;
		return NOFILL;
	}

	if (p.y > UI.ToolBarHeight && p.y < UI.ToolBarHeight + 11* UI.MenuActionWidth && p.x > UI.MenuItemWidth*ITM_FILL_COLOR && p.x < UI.MenuItemWidth*ITM_DRAW_COLOR) {

		int selectedColorRow = p.y / UI.MenuActionWidth;
		int selectedColorColumn = ( p.x - UI.MenuItemWidth * ITM_FILL_COLOR ) / UI.MenuActionWidth ;

		if (selectedColorColumn == 0) // first column
		{
			switch (selectedColorRow) {
			case 1:
				pWind->DrawImage("images\\MenuItems\\colors\\Menu_fill_color_black.jpg", (ITM_FILL_COLOR)*UI.MenuItemWidth, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
				UI.FillColor = BLACK;
				filled = true;
				return BLACK;
			case 2:
				pWind->DrawImage("images\\MenuItems\\colors\\Menu_fill_color_grey_dark.jpg", (ITM_FILL_COLOR)*UI.MenuItemWidth, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
				UI.FillColor = DARK_GREY;
				filled = true;
				return DARK_GREY;
			case 3:
				pWind->DrawImage("images\\MenuItems\\colors\\Menu_fill_color_brown_dark.jpg", (ITM_FILL_COLOR)*UI.MenuItemWidth, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
				UI.FillColor = DARK_BROWN;
				filled = true;
				return DARK_BROWN;
			case 4:
				pWind->DrawImage("images\\MenuItems\\colors\\Menu_fill_color_yellow_dark.jpg", (ITM_FILL_COLOR)*UI.MenuItemWidth, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
				UI.FillColor = DARK_YELLOW;
				filled = true;
				return DARK_YELLOW;
			case 5:
				pWind->DrawImage("images\\MenuItems\\colors\\Menu_fill_color_orange_dark.jpg", (ITM_FILL_COLOR)*UI.MenuItemWidth, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
				UI.FillColor = DARK_ORANGE;
				filled = true;
				return DARK_ORANGE;
			case 6:
				pWind->DrawImage("images\\MenuItems\\colors\\Menu_fill_color_red_dark.jpg", (ITM_FILL_COLOR)*UI.MenuItemWidth, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
				UI.FillColor = DARK_RED;
				filled = true;
				return DARK_RED;
			case 7:
				pWind->DrawImage("images\\MenuItems\\colors\\Menu_fill_color_pink_dark.jpg", (ITM_FILL_COLOR)*UI.MenuItemWidth, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
				UI.FillColor = DARK_PINK;
				filled = true;
				return DARK_PINK;
			case 8:
				pWind->DrawImage("images\\MenuItems\\colors\\Menu_fill_color_violet_dark.jpg", (ITM_FILL_COLOR)*UI.MenuItemWidth, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
				UI.FillColor = DARK_VIOLET;
				filled = true;
				return DARK_VIOLET;
			case 9:
				pWind->DrawImage("images\\MenuItems\\colors\\Menu_fill_color_blue_dark.jpg", (ITM_FILL_COLOR)*UI.MenuItemWidth, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
				UI.FillColor = DARK_BLUE;
				filled = true;
				return DARK_BLUE;
			case 10:
				pWind->DrawImage("images\\MenuItems\\colors\\Menu_fill_color_turquoise_dark.jpg", (ITM_FILL_COLOR)*UI.MenuItemWidth, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
				UI.FillColor = DARK_TURQUOISE;
				filled = true;
				return DARK_TURQUOISE;
			case 11:
				pWind->DrawImage("images\\MenuItems\\colors\\Menu_fill_color_green_dark.jpg", (ITM_FILL_COLOR)*UI.MenuItemWidth, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
				UI.FillColor = DARK_GREEN;
				filled = true;
				return DARK_GREEN;
			}

		} else {
			switch (selectedColorRow) {
			case 1:
				pWind->DrawImage("images\\MenuItems\\colors\\Menu_fill_color_white.jpg", (ITM_FILL_COLOR)*UI.MenuItemWidth, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
				UI.FillColor = WHITE;
				filled = true;
				return WHITE;
			case 2:
				pWind->DrawImage("images\\MenuItems\\colors\\Menu_fill_color_grey.jpg", (ITM_FILL_COLOR)*UI.MenuItemWidth, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
				UI.FillColor = GREY;
				filled = true;
				return GREY;
			case 3:
				pWind->DrawImage("images\\MenuItems\\colors\\Menu_fill_color_brown.jpg", (ITM_FILL_COLOR)*UI.MenuItemWidth, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
				UI.FillColor = BROWN;
				filled = true;
				return BROWN;
			case 4:
				pWind->DrawImage("images\\MenuItems\\colors\\Menu_fill_color_yellow.jpg", (ITM_FILL_COLOR)*UI.MenuItemWidth, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
				UI.FillColor = YELLOW;
				filled = true;
				return YELLOW;
			case 5:
				pWind->DrawImage("images\\MenuItems\\colors\\Menu_fill_color_orange.jpg", (ITM_FILL_COLOR)*UI.MenuItemWidth, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
				UI.FillColor = ORANGE;
				filled = true;
				return ORANGE;
			case 6:
				pWind->DrawImage("images\\MenuItems\\colors\\Menu_fill_color_red.jpg", (ITM_FILL_COLOR)*UI.MenuItemWidth, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
				UI.FillColor = RED;
				filled = true;
				return RED;
			case 7:
				pWind->DrawImage("images\\MenuItems\\colors\\Menu_fill_color_pink.jpg", (ITM_FILL_COLOR)*UI.MenuItemWidth, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
				UI.FillColor = PINK;
				filled = true;
				return PINK;
			case 8:
				pWind->DrawImage("images\\MenuItems\\colors\\Menu_fill_color_violet.jpg", (ITM_FILL_COLOR)*UI.MenuItemWidth, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
				UI.FillColor = VIOLET;
				filled = true;
				return VIOLET;
			case 9:
				pWind->DrawImage("images\\MenuItems\\colors\\Menu_fill_color_blue.jpg", (ITM_FILL_COLOR)*UI.MenuItemWidth, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
				UI.FillColor = BLUE;
				filled = true;
				return BLUE;
			case 10:
				pWind->DrawImage("images\\MenuItems\\colors\\Menu_fill_color_turquoise.jpg", (ITM_FILL_COLOR)*UI.MenuItemWidth, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
				UI.FillColor = TURQUOISE;
				filled = true;
				return TURQUOISE;
			case 11:
				pWind->DrawImage("images\\MenuItems\\colors\\Menu_fill_color_green.jpg", (ITM_FILL_COLOR)*UI.MenuItemWidth, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
				UI.FillColor = GREEN;
				filled = true;
				return GREEN;
			}
		}
	}

	return (filled) ? UI.FillColor : NOFILL;
}

bool Output::isFilled() const
{
	return filled;
}

color Output::selectDrawColor(Point p) const
{
	if (p.y > UI.ToolBarHeight && p.y < UI.ToolBarHeight + 11 * UI.MenuActionWidth && p.x > UI.MenuItemWidth*ITM_FILL_COLOR && p.x < UI.MenuItemWidth*ITM_DRAW_COLOR) {

		int selectedColorRow = p.y / UI.MenuActionWidth;
		int selectedColorColumn = (p.x - UI.MenuItemWidth * ITM_FILL_COLOR) / UI.MenuActionWidth;

		if (selectedColorColumn == 0) // first column
		{
			switch (selectedColorRow) {
			case 1:
				pWind->DrawImage("images\\MenuItems\\colors\\Menu_draw_color_black.jpg", (ITM_DRAW_COLOR)*UI.MenuItemWidth - 50, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
				UI.DrawColor = BLACK;
				return BLACK;
			case 2:
				pWind->DrawImage("images\\MenuItems\\colors\\Menu_draw_color_grey_dark.jpg", (ITM_DRAW_COLOR)*UI.MenuItemWidth - 50, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
				UI.DrawColor = DARK_GREY;
				return DARK_GREY;
			case 3:
				pWind->DrawImage("images\\MenuItems\\colors\\Menu_draw_color_brown_dark.jpg", (ITM_DRAW_COLOR)*UI.MenuItemWidth - 50, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
				UI.DrawColor = DARK_BROWN;
				return DARK_BROWN;
			case 4:
				pWind->DrawImage("images\\MenuItems\\colors\\Menu_draw_color_yellow_dark.jpg", (ITM_DRAW_COLOR)*UI.MenuItemWidth - 50, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
				UI.DrawColor = DARK_YELLOW;
				return DARK_YELLOW;
			case 5:
				pWind->DrawImage("images\\MenuItems\\colors\\Menu_draw_color_orange_dark.jpg", (ITM_DRAW_COLOR)*UI.MenuItemWidth - 50, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
				UI.DrawColor = DARK_ORANGE;
				return DARK_ORANGE;
			case 6:
				pWind->DrawImage("images\\MenuItems\\colors\\Menu_draw_color_red_dark.jpg", (ITM_DRAW_COLOR)*UI.MenuItemWidth - 50, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
				UI.DrawColor = DARK_RED;
				return DARK_RED;
			case 7:
				pWind->DrawImage("images\\MenuItems\\colors\\Menu_draw_color_pink_dark.jpg", (ITM_DRAW_COLOR)*UI.MenuItemWidth - 50, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
				UI.DrawColor = DARK_PINK;
				return DARK_PINK;
			case 8:
				pWind->DrawImage("images\\MenuItems\\colors\\Menu_draw_color_violet_dark.jpg", (ITM_DRAW_COLOR)*UI.MenuItemWidth - 50, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
				UI.DrawColor = DARK_VIOLET;
				return DARK_VIOLET;
			case 9:
				pWind->DrawImage("images\\MenuItems\\colors\\Menu_draw_color_blue_dark.jpg", (ITM_DRAW_COLOR)*UI.MenuItemWidth - 50, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
				UI.DrawColor = DARK_BLUE;
				return DARK_BLUE;
			case 10:
				pWind->DrawImage("images\\MenuItems\\colors\\Menu_draw_color_turquoise_dark.jpg", (ITM_DRAW_COLOR)*UI.MenuItemWidth - 50, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
				UI.DrawColor = DARK_TURQUOISE;
				return DARK_TURQUOISE;
			case 11:
				pWind->DrawImage("images\\MenuItems\\colors\\Menu_draw_color_green_dark.jpg", (ITM_DRAW_COLOR)*UI.MenuItemWidth - 50, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
				UI.DrawColor = DARK_GREEN;
				return DARK_GREEN;
			}

		} else {
			switch (selectedColorRow) {
			case 1:
				pWind->DrawImage("images\\MenuItems\\colors\\Menu_draw_color_white.jpg", (ITM_DRAW_COLOR)*UI.MenuItemWidth - 50, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
				UI.DrawColor = WHITE;
				return WHITE;
			case 2:
				pWind->DrawImage("images\\MenuItems\\colors\\Menu_draw_color_grey.jpg", (ITM_DRAW_COLOR)*UI.MenuItemWidth - 50, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
				UI.DrawColor = GREY;
				return GREY;
			case 3:
				pWind->DrawImage("images\\MenuItems\\colors\\Menu_draw_color_brown.jpg", (ITM_DRAW_COLOR)*UI.MenuItemWidth - 50, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
				UI.DrawColor = BROWN;
				return BROWN;
			case 4:
				pWind->DrawImage("images\\MenuItems\\colors\\Menu_draw_color_yellow.jpg", (ITM_DRAW_COLOR)*UI.MenuItemWidth - 50, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
				UI.DrawColor = YELLOW;
				return YELLOW;
			case 5:
				pWind->DrawImage("images\\MenuItems\\colors\\Menu_draw_color_orange.jpg", (ITM_DRAW_COLOR)*UI.MenuItemWidth - 50, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
				UI.DrawColor = ORANGE;
				return ORANGE;
			case 6:
				pWind->DrawImage("images\\MenuItems\\colors\\Menu_draw_color_red.jpg", (ITM_DRAW_COLOR)*UI.MenuItemWidth - 50, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
				UI.DrawColor = RED;
				return RED;
			case 7:
				pWind->DrawImage("images\\MenuItems\\colors\\Menu_draw_color_pink.jpg", (ITM_DRAW_COLOR)*UI.MenuItemWidth - 50, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
				UI.DrawColor = PINK;
				return PINK;
			case 8:
				pWind->DrawImage("images\\MenuItems\\colors\\Menu_draw_color_violet.jpg", (ITM_DRAW_COLOR)*UI.MenuItemWidth - 50, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
				UI.DrawColor = VIOLET;
				return VIOLET;
			case 9:
				pWind->DrawImage("images\\MenuItems\\colors\\Menu_draw_color_blue.jpg", (ITM_DRAW_COLOR)*UI.MenuItemWidth - 50, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
				UI.DrawColor = BLUE;
				return BLUE;
			case 10:
				pWind->DrawImage("images\\MenuItems\\colors\\Menu_draw_color_turquoise.jpg", (ITM_DRAW_COLOR)*UI.MenuItemWidth - 50, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
				UI.DrawColor = TURQUOISE;
				return TURQUOISE;
			case 11:
				pWind->DrawImage("images\\MenuItems\\colors\\Menu_draw_color_green.jpg", (ITM_DRAW_COLOR)*UI.MenuItemWidth - 50, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
				UI.DrawColor = GREEN;
				return GREEN;
			}
		}
	}
	return UI.DrawColor;
}

void Output::changeFillColorIcon(color c, bool f) {
	if (!f ) {
		pWind->DrawImage("images\\MenuItems\\colors\\Menu_fill_color_No.jpg", (ITM_FILL_COLOR)*UI.MenuItemWidth, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
		filled = false;
		UI.FillColor=NOFILL;

	} else if ( c == BLACK ) {
		pWind->DrawImage("images\\MenuItems\\colors\\Menu_fill_color_black.jpg", (ITM_FILL_COLOR)*UI.MenuItemWidth, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
		UI.FillColor = BLACK;
		filled = true;

	} else if (c == WHITE) {
		pWind->DrawImage("images\\MenuItems\\colors\\Menu_fill_color_white.jpg", (ITM_FILL_COLOR)*UI.MenuItemWidth, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
		UI.FillColor = WHITE;
		filled = true;

	} else if (c == GREY) {
		pWind->DrawImage("images\\MenuItems\\colors\\Menu_fill_color_grey.jpg", (ITM_FILL_COLOR)*UI.MenuItemWidth, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
		UI.FillColor = GREY;
		filled = true;

	} else if ( c == DARK_GREY ) {
		pWind->DrawImage("images\\MenuItems\\colors\\Menu_fill_color_grey_dark.jpg", (ITM_FILL_COLOR)*UI.MenuItemWidth, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
		UI.FillColor = DARK_GREY;
		filled = true;

	} else if (c == BROWN) {
		pWind->DrawImage("images\\MenuItems\\colors\\Menu_fill_color_brown.jpg", (ITM_FILL_COLOR)*UI.MenuItemWidth, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
		UI.FillColor = BROWN;
		filled = true;

	} else if ( c == DARK_BROWN) {
		pWind->DrawImage("images\\MenuItems\\colors\\Menu_fill_color_brown_dark.jpg", (ITM_FILL_COLOR)*UI.MenuItemWidth, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
		UI.FillColor = DARK_BROWN;
		filled = true;

	}else if (c == YELLOW) {
		pWind->DrawImage("images\\MenuItems\\colors\\Menu_fill_color_yellow.jpg", (ITM_FILL_COLOR)*UI.MenuItemWidth, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
		UI.FillColor = YELLOW;
		filled = true;

	} else if ( c == DARK_YELLOW) {
		pWind->DrawImage("images\\MenuItems\\colors\\Menu_fill_color_yellow_dark.jpg", (ITM_FILL_COLOR)*UI.MenuItemWidth, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
		UI.FillColor = DARK_YELLOW;
		filled = true;

	}else if (c == ORANGE) {
		pWind->DrawImage("images\\MenuItems\\colors\\Menu_fill_color_orange.jpg", (ITM_FILL_COLOR)*UI.MenuItemWidth, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
		UI.FillColor = ORANGE;
		filled = true;

	} else if ( c == DARK_ORANGE) {
		pWind->DrawImage("images\\MenuItems\\colors\\Menu_fill_color_orange_dark.jpg", (ITM_FILL_COLOR)*UI.MenuItemWidth, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
		UI.FillColor = DARK_ORANGE;
		filled = true;

	} else if (c == RED) {
		pWind->DrawImage("images\\MenuItems\\colors\\Menu_fill_color_red.jpg", (ITM_FILL_COLOR)*UI.MenuItemWidth, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
		UI.FillColor = RED;
		filled = true;

	} else if ( c == DARK_RED ) {
		pWind->DrawImage("images\\MenuItems\\colors\\Menu_fill_color_red_dark.jpg", (ITM_FILL_COLOR)*UI.MenuItemWidth, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
		UI.FillColor = DARK_RED;
		filled = true;

	} else if (c == PINK) {
		pWind->DrawImage("images\\MenuItems\\colors\\Menu_fill_color_pink.jpg", (ITM_FILL_COLOR)*UI.MenuItemWidth, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
		UI.FillColor = PINK;
		filled = true;

	} else if ( c == DARK_PINK) {
		pWind->DrawImage("images\\MenuItems\\colors\\Menu_fill_color_pink_dark.jpg", (ITM_FILL_COLOR)*UI.MenuItemWidth, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
		UI.FillColor = DARK_PINK;
		filled = true;

	} else if (c == VIOLET) {
		pWind->DrawImage("images\\MenuItems\\colors\\Menu_fill_color_violet.jpg", (ITM_FILL_COLOR)*UI.MenuItemWidth, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
		UI.FillColor = VIOLET;
		filled = true;

	} else if ( c == DARK_VIOLET) {
		pWind->DrawImage("images\\MenuItems\\colors\\Menu_fill_color_violet_dark.jpg", (ITM_FILL_COLOR)*UI.MenuItemWidth, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
		UI.FillColor = DARK_VIOLET;
		filled = true;

	} else if (c == BLUE) {
		pWind->DrawImage("images\\MenuItems\\colors\\Menu_fill_color_blue.jpg", (ITM_FILL_COLOR)*UI.MenuItemWidth, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
		UI.FillColor = BLUE;
		filled = true;

	} else if ( c == DARK_BLUE) {
		pWind->DrawImage("images\\MenuItems\\colors\\Menu_fill_color_blue_dark.jpg", (ITM_FILL_COLOR)*UI.MenuItemWidth, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
		UI.FillColor = DARK_BLUE;
		filled = true;

	} else if (c == TURQUOISE) {
		pWind->DrawImage("images\\MenuItems\\colors\\Menu_fill_color_turquoise.jpg", (ITM_FILL_COLOR)*UI.MenuItemWidth, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
		UI.FillColor = TURQUOISE;
		filled = true;

	} else if ( c == DARK_TURQUOISE) {
		pWind->DrawImage("images\\MenuItems\\colors\\Menu_fill_color_turquoise_dark.jpg", (ITM_FILL_COLOR)*UI.MenuItemWidth, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
		UI.FillColor = DARK_TURQUOISE;
		filled = true;

	}else if (c == GREEN) {
		pWind->DrawImage("images\\MenuItems\\colors\\Menu_fill_color_green.jpg", (ITM_FILL_COLOR)*UI.MenuItemWidth, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
		UI.FillColor = GREEN;
		filled = true;

	} else if ( c == DARK_GREEN) {
		pWind->DrawImage("images\\MenuItems\\colors\\Menu_fill_color_green_dark.jpg", (ITM_FILL_COLOR)*UI.MenuItemWidth, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
		UI.FillColor = DARK_GREEN;
		filled = true;	
	}
}

void Output::changeDrawColorIcon(color c) const
{
	if (c == BLACK) {
		pWind->DrawImage("images\\MenuItems\\colors\\Menu_draw_color_black.jpg", (ITM_DRAW_COLOR)*UI.MenuItemWidth - 50, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
		UI.DrawColor = BLACK;
		
	} else if (c == WHITE) {
		pWind->DrawImage("images\\MenuItems\\colors\\Menu_draw_color_white.jpg", (ITM_DRAW_COLOR)*UI.MenuItemWidth - 50, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
		UI.DrawColor = WHITE;
		

	} else if (c == GREY) {
		pWind->DrawImage("images\\MenuItems\\colors\\Menu_draw_color_grey.jpg", (ITM_DRAW_COLOR)*UI.MenuItemWidth - 50, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
		UI.DrawColor = GREY;

	} else if (c == DARK_GREY) {
		pWind->DrawImage("images\\MenuItems\\colors\\Menu_draw_color_grey_dark.jpg", (ITM_DRAW_COLOR)*UI.MenuItemWidth - 50, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
		UI.DrawColor = DARK_GREY;
		
	} else if (c == BROWN) {
		pWind->DrawImage("images\\MenuItems\\colors\\Menu_draw_color_brown.jpg", (ITM_DRAW_COLOR)*UI.MenuItemWidth - 50, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
		UI.DrawColor = BROWN;
		
	} else if (c == DARK_BROWN) {
		pWind->DrawImage("images\\MenuItems\\colors\\Menu_draw_color_brown_dark.jpg", (ITM_DRAW_COLOR)*UI.MenuItemWidth - 50, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
		UI.DrawColor = DARK_BROWN;
		
	} else if (c == YELLOW) {
		pWind->DrawImage("images\\MenuItems\\colors\\Menu_draw_color_yellow.jpg", (ITM_DRAW_COLOR)*UI.MenuItemWidth - 50, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
		UI.DrawColor = YELLOW;
		
	} else if (c == DARK_YELLOW) {
		pWind->DrawImage("images\\MenuItems\\colors\\Menu_draw_color_yellow_dark.jpg", (ITM_DRAW_COLOR)*UI.MenuItemWidth - 50, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
		UI.DrawColor = DARK_YELLOW;
		
	} else if (c == ORANGE) {
		pWind->DrawImage("images\\MenuItems\\colors\\Menu_draw_color_orange.jpg", (ITM_DRAW_COLOR)*UI.MenuItemWidth - 50, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
		UI.DrawColor = ORANGE;

	} else if (c == DARK_ORANGE) {
		pWind->DrawImage("images\\MenuItems\\colors\\Menu_draw_color_orange_dark.jpg", (ITM_DRAW_COLOR)*UI.MenuItemWidth - 50, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
		UI.DrawColor = DARK_ORANGE;

	} else if (c == RED) {
		pWind->DrawImage("images\\MenuItems\\colors\\Menu_draw_color_red.jpg", (ITM_DRAW_COLOR)*UI.MenuItemWidth - 50, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
		UI.DrawColor = RED;

	} else if (c == DARK_RED) {
		pWind->DrawImage("images\\MenuItems\\colors\\Menu_draw_color_red_dark.jpg", (ITM_DRAW_COLOR)*UI.MenuItemWidth - 50, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
		UI.DrawColor = DARK_RED;
		
	} else if (c == PINK) {
		pWind->DrawImage("images\\MenuItems\\colors\\Menu_draw_color_pink.jpg", (ITM_DRAW_COLOR)*UI.MenuItemWidth - 50, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
		UI.DrawColor = PINK;
		
	} else if (c == DARK_PINK) {
		pWind->DrawImage("images\\MenuItems\\colors\\Menu_draw_color_pink_dark.jpg", (ITM_DRAW_COLOR)*UI.MenuItemWidth - 50, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
		UI.DrawColor = DARK_PINK;

	} else if (c == VIOLET) {
		pWind->DrawImage("images\\MenuItems\\colors\\Menu_draw_color_violet.jpg", (ITM_DRAW_COLOR)*UI.MenuItemWidth - 50, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
		UI.DrawColor = VIOLET;

	} else if (c == DARK_VIOLET) {
		pWind->DrawImage("images\\MenuItems\\colors\\Menu_draw_color_violet_dark.jpg", (ITM_DRAW_COLOR)*UI.MenuItemWidth - 50, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
		UI.DrawColor = DARK_VIOLET;

	} else if (c == BLUE) {
		pWind->DrawImage("images\\MenuItems\\colors\\Menu_draw_color_blue.jpg", (ITM_DRAW_COLOR)*UI.MenuItemWidth - 50, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
		UI.DrawColor = BLUE;

	} else if (c == DARK_BLUE) {
		pWind->DrawImage("images\\MenuItems\\colors\\Menu_draw_color_blue_dark.jpg", (ITM_DRAW_COLOR)*UI.MenuItemWidth - 50, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
		UI.DrawColor = DARK_BLUE;

	} else if (c == TURQUOISE) {
		pWind->DrawImage("images\\MenuItems\\colors\\Menu_draw_color_turquoise.jpg", (ITM_DRAW_COLOR)*UI.MenuItemWidth - 50, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
		UI.DrawColor = TURQUOISE;

	} else if (c == DARK_TURQUOISE) {
		pWind->DrawImage("images\\MenuItems\\colors\\Menu_draw_color_turquoise_dark.jpg", (ITM_DRAW_COLOR)*UI.MenuItemWidth - 50, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
		UI.DrawColor = DARK_TURQUOISE;

	} else if (c == GREEN) {
		pWind->DrawImage("images\\MenuItems\\colors\\Menu_draw_color_green.jpg", (ITM_DRAW_COLOR)*UI.MenuItemWidth - 50, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
		UI.DrawColor = GREEN;

	} else if (c == DARK_GREEN) {
		pWind->DrawImage("images\\MenuItems\\colors\\Menu_draw_color_green_dark.jpg", (ITM_DRAW_COLOR)*UI.MenuItemWidth - 50, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
		UI.DrawColor = DARK_GREEN;

	}
}


void Output::createPlayToolBar() const
{
	string clean = "images\\MenuItems\\clean.jpg";
	pWind->DrawImage(clean, 0, 0, UI.width-3*UI.MenuActionWidth, UI.ToolBarHeight);

	UI.InterfaceMode = MODE_PLAY;
	string playItemImages[PLAY_ITM_COUNT];
	playItemImages[ITM_DRAW] = "images\\MenuItems\\draw.jpg";
	playItemImages[ITM_COL_CLR] = "images\\MenuItems\\col_clr.jpg";
	playItemImages[ITM_COL_SHP] = "images\\MenuItems\\col_shp.jpg";

	pWind->DrawImage(playItemImages[ITM_DRAW], 0, 0, UI.MenuActionWidth + 30, UI.ToolBarHeight);
	pWind->DrawImage(playItemImages[ITM_COL_CLR], (10)*UI.MenuActionWidth, 0, UI.MenuActionWidth + 30, UI.ToolBarHeight - 3);
	pWind->DrawImage(playItemImages[ITM_COL_SHP], (12)*UI.MenuActionWidth, 0, UI.MenuActionWidth + 30, UI.ToolBarHeight - 3);

	pWind->SetPen(MIDNIGHTBLUE, 3);
	pWind->DrawLine(0, UI.ToolBarHeight - 1.5, UI.width, UI.ToolBarHeight - 1.5);

}
void Output::playOnToolbar(string path, int place) const
{
	switch (place)
	{
	case ITM_DRAW: pWind->DrawImage(path, 0, 0, UI.MenuActionWidth + 30, UI.ToolBarHeight); break;
	case ITM_COL_CLR:pWind->DrawImage(path, (10)*UI.MenuActionWidth, 0, UI.MenuActionWidth + 30, UI.ToolBarHeight); break;
	case ITM_COL_SHP:pWind->DrawImage(path, (12)*UI.MenuActionWidth, 0, UI.MenuActionWidth + 30, UI.ToolBarHeight); break;
	}
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::clearDrawArea() const
{
	pWind->SetPen(UI.BackgroundColor, 1);
	pWind->SetBrush(UI.BackgroundColor);
	pWind->DrawRectangle(UI.MenuActionWidth, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::printMessage(string msg) const	//Prints a message on status bar
{
	clearStatusBar();	//First clear the status bar

	pWind->SetPen(UI.MessageColor, 50);
	pWind->SetFont(20, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight / 1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCurrentDrawColor() //get current drawing color
{
	return UI.DrawColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCurrentFillColor() //get current filling color
{
	return UI.FillColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

enum BorderSizes { BORDER_SIZE_1 = 5, BORDER_SIZE_2 = 10, BORDER_SIZE_3 = 15, BORDER_SIZE_4 = 20, BORDER_SIZE_5 = 25 };

void Output::createBorderSizeIcon()
{
	pWind->DrawImage("images\\MenuItems\\Menu_Border_Size_1.jpg", ITM_BORDER_SIZE*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight - 3);
	UI.BorderSize = BORDER_SIZE_1;
}

int Output::getCurrentBorderSize() //get current pen width
{
	return UI.BorderSize;
}

void Output::setCurrentBorderSize(int width)
{
	UI.BorderSize = width;
}

void Output::changeBorderSizeIcon(int size) const
{
	switch (size)
	{
	case BORDER_SIZE_1:
		pWind->DrawImage("images\\MenuItems\\Menu_Border_Size_1.jpg", ITM_BORDER_SIZE*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight -3);
		UI.BorderSize = BORDER_SIZE_1 ;
		return ;
	case BORDER_SIZE_2:
		pWind->DrawImage("images\\MenuItems\\Menu_Border_Size_2.jpg", ITM_BORDER_SIZE*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight - 3);
		UI.BorderSize = BORDER_SIZE_2 ;
		return ;
	case BORDER_SIZE_3:
		pWind->DrawImage("images\\MenuItems\\Menu_Border_Size_3.jpg", ITM_BORDER_SIZE*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight - 3);
		UI.BorderSize = BORDER_SIZE_3 ;
		return ;
	case BORDER_SIZE_4:
		pWind->DrawImage("images\\MenuItems\\Menu_Border_Size_4.jpg", ITM_BORDER_SIZE*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight - 3);
		UI.BorderSize = BORDER_SIZE_4 ;
		return ;
	case BORDER_SIZE_5:
		pWind->DrawImage("images\\MenuItems\\Menu_Border_Size_5.jpg", ITM_BORDER_SIZE*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight - 3);
		UI.BorderSize = BORDER_SIZE_5 ;
		return ;
	}
}

void Output::drawBorderSizeMenu() const
{
	pWind->DrawImage("images\\MenuItems\\Menu_Border_Size.jpg", ITM_BORDER_SIZE*UI.MenuItemWidth, UI.ToolBarHeight, UI.MenuItemWidth, 5 * UI.MenuActionWidth);
}

int Output::selectBorderSize(Point p)
{
	if (p.x > ITM_BORDER_SIZE*UI.MenuItemWidth && p.x < (ITM_BORDER_SIZE + 1)*UI.MenuItemWidth) {
		int selectedColor = ((p.y ) / UI.MenuActionWidth);
		switch (selectedColor)
		{
		case 1:
			pWind->DrawImage("images\\MenuItems\\Menu_Border_Size_1.jpg", ITM_BORDER_SIZE*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight - 3);
			UI.BorderSize = BORDER_SIZE_1;
			return BORDER_SIZE_1;
		case 2:
			pWind->DrawImage("images\\MenuItems\\Menu_Border_Size_2.jpg", ITM_BORDER_SIZE*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight - 3);
			UI.BorderSize = BORDER_SIZE_2;
			return BORDER_SIZE_2;
		case 3:
			pWind->DrawImage("images\\MenuItems\\Menu_Border_Size_3.jpg", ITM_BORDER_SIZE*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight - 3);
			UI.BorderSize = BORDER_SIZE_3;
			return BORDER_SIZE_3;
		case 4:
			pWind->DrawImage("images\\MenuItems\\Menu_Border_Size_4.jpg", ITM_BORDER_SIZE*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight - 3);
			UI.BorderSize = BORDER_SIZE_4;
			return BORDER_SIZE_4;
		case 5:
			pWind->DrawImage("images\\MenuItems\\Menu_Border_Size_5.jpg", ITM_BORDER_SIZE*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight - 3);
			UI.BorderSize = BORDER_SIZE_5;
			return BORDER_SIZE_5;
		}
	}

	return -1;
}

//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

void Output::drawRectangle(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color drawingColor;
	if (selected)
		drawingColor = UI.HighlightColor; //Figure should be drawn highlighted
	else
		drawingColor = RectGfxInfo.drawColor;

	pWind->SetPen(drawingColor, RectGfxInfo.borderSize);
	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.fillColor);
	}
	else
		style = FRAME;


	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);

}

void Output::drawRhombus(const int* X, const int* Y, GfxInfo RhomGfxInfo, bool selected) const
{
	color drawingColor;
	if (selected)
		drawingColor = UI.HighlightColor; //Figure should be drawn highlighted
	else
		drawingColor = RhomGfxInfo.drawColor;

	pWind->SetPen(drawingColor, RhomGfxInfo.borderSize);
	drawstyle style;
	if (RhomGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RhomGfxInfo.fillColor);
	}
	else
		style = FRAME;

	pWind->DrawPolygon(X, Y, 4, style);
}

void Output::drawEllipse(Point P1, Point P2, GfxInfo ElpsGfxInfo, bool selected) const
{
	color drawingColor;
	if (selected)
		drawingColor = UI.HighlightColor; //Figure should be drawn highlighted
	else
		drawingColor = ElpsGfxInfo.drawColor;

	pWind->SetPen(drawingColor, ElpsGfxInfo.borderSize);
	drawstyle style;
	if (ElpsGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(ElpsGfxInfo.fillColor);
	}
	else
		style = FRAME;

	pWind->DrawEllipse(P1.x, P1.y, P2.x, P2.y, style);
}

void Output::drawTriangle(Point P1, Point P2, Point P3, GfxInfo TriGfxInfo, bool selected) const
{

	color drawingColor;
	if (selected)
		drawingColor = UI.HighlightColor; //Figure should be drawn highlighted
	else
		drawingColor = TriGfxInfo.drawColor;

	pWind->SetPen(drawingColor, TriGfxInfo.borderSize);
	drawstyle style;
	if (TriGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(TriGfxInfo.fillColor);
	}
	else
		style = FRAME;


	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);

}
void Output::drawLine(Point P1, Point P2, GfxInfo LineGfxInfo, bool selected) const
{

	color drawingColor;
	if (selected)
		drawingColor = UI.HighlightColor; //Figure should be drawn highlighted
	else
		drawingColor = LineGfxInfo.drawColor;

	pWind->SetPen(drawingColor, LineGfxInfo.borderSize);
	drawstyle style = FRAME;
	pWind->DrawLine(P1.x, P1.y, P2.x, P2.y, style);

}

void Output::getValidPoint(Point& P) const {
	Input* pIn = new Input(pWind);
	while (true) {
		pIn->getPointClicked(P.x, P.y);

		if (P.y < UI.ToolBarHeight || P.y > UI.height - UI.StatusBarHeight || P.x < UI.MenuActionWidth) {
			printMessage("Please Select a Valid Point");
		}
		else
			break;
	}
	delete pIn;
}

void Output::getValidEllipsePoint(Point& P) const {
	Input* pIn = new Input(pWind);
	while (true) {
		pIn->getPointClicked(P.x, P.y);

		if (P.y < UI.ToolBarHeight + 60 || P.y > UI.height - UI.StatusBarHeight - 60 || P.x < UI.MenuActionWidth + 120) {
			printMessage("Please Select a Valid Point");
		}
		else
			break;
	}
	delete pIn;
}

void Output::getValidRhombusPoint(Point& P) const {
	Input* pIn = new Input(pWind);
	while (true) {
		pIn->getPointClicked(P.x, P.y);

		if (P.y < UI.ToolBarHeight + 60 || P.y > UI.height - UI.StatusBarHeight - 60 || P.x < UI.MenuActionWidth + 120) {
			printMessage("Please Select a Valid Point");
		}
		else
			break;
	}
	delete pIn;
}

//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}

