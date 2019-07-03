#include "Output.h"
#include "../Actions/UndoRedoAction.h"
#include "../Colors/ColorsHeader.h"

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

	UI.DrawColor = Black();	//Drawing color
	UI.FillColor = Black();	//Filling color
	UI.MessageColor = Color(WHITESMOKE);		//Messages color
	UI.BackgroundColor = Color(GAINSBORO);	//Background color
	UI.HighlightColor = Color(MAGENTA);	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = Color(STEELBLUE);
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

	colors.resize(2);
	colors[0] = { Black(), DarkGrey(), DarkBrown(), DarkYellow(), DarkOrange(), DarkRed(), DarkPink(), DarkViolet(), DarkBlue(), DarkTurquoise(), DarkGreen() };
	colors[1] = { White(),	Grey(),		Brown(),	Yellow(),	 Orange(),	    Red(),	   Pink(),		Violet(),	  Blue(),	  Turquoise(),	  Green() };

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
	pW->SetBrush(UI.BackgroundColor.getColor());
	pW->SetPen(UI.BackgroundColor.getColor(), 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::createStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor.getColor(), 1);
	pWind->SetBrush(UI.StatusBarColor.getColor());
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::clearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor.getColor(), 1);
	pWind->SetBrush(UI.StatusBarColor.getColor());
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
	pWind->SetPen(UI.BackgroundColor.getColor(), 1);
	pWind->SetBrush(UI.BackgroundColor.getColor());
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.MenuActionWidth, UI.height - UI.StatusBarHeight);
}
void Output::createColorIcons()
{
	pWind->DrawImage(R"(images\MenuItems\colors\Menu_fill_color_black.jpg)", (ITM_FILL_COLOR)*UI.MenuItemWidth, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
	pWind->DrawImage(R"(images\MenuItems\colors\Menu_draw_color_black.jpg)", (ITM_DRAW_COLOR)*UI.MenuItemWidth - 50, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
	UI.FillColor = Black();
	UI.DrawColor = Black();
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
	pWind->DrawImage(R"(images\MenuItems\colors\colors_fill.jpg)", UI.MenuItemWidth* ITM_FILL_COLOR, UI.ToolBarHeight, UI.MenuItemWidth, UI.MenuActionWidth * 12);
}

void Output::drawDrawingColorMenu() const
{
	pWind->DrawImage(R"(images\MenuItems\colors\colors_draw.jpg)", UI.MenuItemWidth* ITM_FILL_COLOR, UI.ToolBarHeight, UI.MenuItemWidth, UI.MenuActionWidth * 11);
}

Color Output::selectFillColor(Point p) {

	// checks if the user chooses no fill color 
	if (p.y > 12*UI.ToolBarHeight && p.y < 13*UI.ToolBarHeight && p.x > UI.MenuItemWidth*ITM_FILL_COLOR && p.x < UI.MenuItemWidth*ITM_DRAW_COLOR) {
		pWind->DrawImage(NoFill().getFillColorIcon(), (ITM_FILL_COLOR)*UI.MenuItemWidth, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
		filled = false;
		return NoFill();
	}

	if (p.y > UI.ToolBarHeight && p.y < UI.ToolBarHeight + 11* UI.MenuActionWidth && p.x > UI.MenuItemWidth*ITM_FILL_COLOR && p.x < UI.MenuItemWidth*ITM_DRAW_COLOR) {
		const int selectedColorRow = p.y / UI.MenuActionWidth -1;
		const int selectedColorColumn = ( p.x - UI.MenuItemWidth * ITM_FILL_COLOR ) / UI.MenuActionWidth ;

		const Color &c = colors[selectedColorColumn][selectedColorRow];
		pWind->DrawImage(c.getFillColorIcon(), (ITM_FILL_COLOR)*UI.MenuItemWidth, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
		filled = true;
		return UI.FillColor = c;
	}

	return (filled) ? UI.FillColor : NoFill();
}

bool Output::isFilled() const
{
	return filled;
}

Color Output::selectDrawColor(Point p) const
{
	if (p.y > UI.ToolBarHeight && p.y < UI.ToolBarHeight + 11 * UI.MenuActionWidth && p.x > UI.MenuItemWidth*ITM_FILL_COLOR && p.x < UI.MenuItemWidth*ITM_DRAW_COLOR) {

		const int selectedColorRow = p.y / UI.MenuActionWidth -1;
		const int selectedColorColumn = (p.x - UI.MenuItemWidth * ITM_FILL_COLOR) / UI.MenuActionWidth;

		const Color &c = colors[selectedColorColumn][selectedColorRow];

		pWind->DrawImage(c.getDrawColorIcon(), (ITM_DRAW_COLOR)*UI.MenuItemWidth - 50, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
		return UI.DrawColor = c;
	}

	return UI.DrawColor;
}

void Output::changeFillColorIcon(Color c, bool f) {
	if (!f ) {
		pWind->DrawImage(NoFill().getFillColorIcon(), (ITM_FILL_COLOR)*UI.MenuItemWidth, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
		filled = false;
		UI.FillColor = NoFill();

	} else {
		pWind->DrawImage(c.getFillColorIcon(), (ITM_FILL_COLOR)*UI.MenuItemWidth, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
		UI.FillColor = c;
		filled = true;
	}
}

void Output::changeDrawColorIcon(Color c) const
{
	pWind->DrawImage(c.getDrawColorIcon(), (ITM_DRAW_COLOR)*UI.MenuItemWidth - 50, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
	UI.DrawColor = c;
}

Color Output::getColorType(int red , int green , int blue)
{
	Color test(red, green, blue);
	for (int i = 0; i < colors.size(); ++i)
	{
		for (int j = 0; j < colors[i].size(); ++j)
		{
			if (test == colors[i][j])
				return colors[i][j];
		}
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
	pWind->SetPen(UI.BackgroundColor.getColor(), 1);
	pWind->SetBrush(UI.BackgroundColor.getColor());
	pWind->DrawRectangle(UI.MenuActionWidth, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::printMessage(string msg) const	//Prints a message on status bar
{
	clearStatusBar();	//First clear the status bar

	pWind->SetPen(UI.MessageColor.getColor(), 50);
	pWind->SetFont(20, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight / 1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

Color Output::getCurrentDrawColor() //get current drawing color
{
	return UI.DrawColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

Color Output::getCurrentFillColor() //get current filling color
{
	return UI.FillColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

enum BorderSizes { BORDER_SIZE_1 = 5, BORDER_SIZE_2 = 10, BORDER_SIZE_3 = 15, BORDER_SIZE_4 = 20, BORDER_SIZE_5 = 25 };

void Output::createBorderSizeIcon() const
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

int Output::selectBorderSize(Point p) const
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

drawstyle Output::getDrawingStyle(GfxInfo gfxInfo, bool isSelected) const
{
	Color drawingColor;
	if (isSelected)
		drawingColor = UI.HighlightColor; //Figure should be drawn highlighted
	else
		drawingColor = gfxInfo.drawColor;

	pWind->SetPen(drawingColor.getColor(), gfxInfo.borderSize);
	drawstyle style;
	if (gfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(gfxInfo.fillColor.getColor());
	}
	else
		style = FRAME;

	return style;
}

void Output::drawRectangle(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	const drawstyle style = getDrawingStyle(RectGfxInfo, selected);
	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);
}

void Output::drawRhombus(const int* X, const int* Y, GfxInfo RhomGfxInfo, bool selected) const
{
	const drawstyle style = getDrawingStyle(RhomGfxInfo, selected);
	pWind->DrawPolygon(X, Y, 4, style);
}

void Output::drawEllipse(Point P1, Point P2, GfxInfo ElpsGfxInfo, bool selected) const
{
	const drawstyle style = getDrawingStyle(ElpsGfxInfo, selected);
	pWind->DrawEllipse(P1.x, P1.y, P2.x, P2.y, style);
}

void Output::drawTriangle(Point P1, Point P2, Point P3, GfxInfo TriGfxInfo, bool selected) const
{
	const drawstyle style = getDrawingStyle(TriGfxInfo, selected);
	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);
}

void Output::drawLine(Point P1, Point P2, GfxInfo LineGfxInfo, bool selected) const
{
	const drawstyle style = getDrawingStyle(LineGfxInfo, selected);
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

vector<vector<Color>> Output::colors;