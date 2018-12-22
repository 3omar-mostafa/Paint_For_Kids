#include "Output.h"


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
	UI.MsgColor = WHITESMOKE;		//Messages color
	UI.BkGrndColor = GAINSBORO;	//Background color
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = STEELBLUE;
	UI.PenWidth = 6;	//width of the figures frames

	filled = true;
	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project");


	CreateDrawToolBar();
	CreateDrawActionToolBar();
	CreateColorIcons();
	CreateStatusBar();

	//draw sound icon
	pWind->DrawImage("images\\MenuItems\\Menu_sound_ON.jpg", 23 * UI.MenuActionWidth, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
}


Input* Output::CreateInput() const
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int w, int h, int x, int y) const
{
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateDrawToolBar() const
{
	UI.InterfaceMode = MODE_DRAW;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way

	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[DRAW_ITM_COUNT];
	MenuItemImages[ITM_GAME] = "images\\MenuItems\\Menu_game.jpg";
	MenuItemImages[ITM_RECT] = "images\\MenuItems\\Menu_Rect.jpg";
	MenuItemImages[ITM_TRIANGLE] = "images\\MenuItems\\Menu_Triangle.jpg";
	MenuItemImages[ITM_CIRCLE] = "images\\MenuItems\\Menu_Circ.jpg";
	MenuItemImages[ITM_RHOMBUS] = "images\\MenuItems\\Menu_Rhombus.jpg";
	MenuItemImages[ITM_LINE] = "images\\MenuItems\\Menu_Line.jpg";
	MenuItemImages[ITM_EXIT] = "images\\MenuItems\\Menu_Exit.jpg";

	//TODO: Prepare images for each menu item and add it to the list

	//Draw menu item one image at a time
	for (int i = 0; i < DRAW_ITM_COUNT - 4; i++)
		pWind->DrawImage(MenuItemImages[i], i *UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight - 3);

	// clean white spaces in toolbar
	pWind->DrawImage("images\\MenuItems\\clean.jpg", 22 * UI.MenuActionWidth, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);

	//draw Exit icon
	pWind->DrawImage(MenuItemImages[ITM_EXIT], (24)*UI.MenuActionWidth, 0, UI.MenuActionWidth + 40, UI.ToolBarHeight - 3);


	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight - 1.5, UI.width, UI.ToolBarHeight - 1.5);

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::CreateDrawActionToolBar()  const
{
	UI.InterfaceMode = MODE_DRAW;

	string MenuActionsImages[DRAW_ACTION_COUNT];
	MenuActionsImages[ITM_LOAD] = "images\\MenuItems\\Menu_Load.jpg";
	MenuActionsImages[ITM_SAVE] = "images\\MenuItems\\Menu_save.jpg";
	MenuActionsImages[ITM_SAVE_TYPE] = "images\\MenuItems\\Menu_save_type.jpg";
	MenuActionsImages[ITM_COPY] = "images\\MenuItems\\Menu_copy.jpg";
	MenuActionsImages[ITM_CUT] = "images\\MenuItems\\Menu_Cut.jpg";
	MenuActionsImages[ITM_PASTE] = "images\\MenuItems\\Menu_Paste.jpg";
	MenuActionsImages[ITM_DELETE] = "images\\MenuItems\\Menu_delete.jpg";
	MenuActionsImages[ITM_CLEAR] = "images\\MenuItems\\Menu_Clear_All.jpg";
	MenuActionsImages[ITM_SELECT] = "images\\MenuItems\\Menu_Select.jpg";
	MenuActionsImages[ITM_SEND_TO_BACK] = "images\\MenuItems\\Menu_send_to_back.jpg";
	MenuActionsImages[ITM_BRING_TO_FRONT] = "images\\MenuItems\\Menu_bring_to_front.jpg";
	MenuActionsImages[ITM_RESIZE] = "images\\MenuItems\\Menu_Resize.jpg";


	//Draw menu action one image at a time
	for (int i = 0; i < DRAW_ACTION_COUNT; i++)
		pWind->DrawImage(MenuActionsImages[i], 0, (i + 1)*UI.ToolBarHeight, UI.MenuActionWidth - 3, UI.ToolBarHeight);

	//Draw a line next to Action Menu
	pWind->SetPen(RED, 3);
	pWind->DrawLine(UI.MenuActionWidth - 1.5, UI.ToolBarHeight, UI.MenuActionWidth - 1.5, UI.height - UI.StatusBarHeight);
}

void Output::removeDrawActionToolBar() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.MenuActionWidth, UI.height - UI.StatusBarHeight);
}
void Output::CreateColorIcons()
{
	pWind->DrawImage("images\\MenuItems\\Menu_fill_color_black.jpg", (ITM_FILL_COLOR)*UI.MenuItemWidth, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
	pWind->DrawImage("images\\MenuItems\\Menu_draw_color_black.jpg", (ITM_DRAW_COLOR)*UI.MenuItemWidth - 50, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
	UI.FillColor = BLACK;
	UI.DrawColor = BLACK;
	filled = true;
}

void Output::drawOnToolbar(string path, int place) const
{
	pWind->DrawImage(path, place * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight - 3);
}

void Output::drawOnActionbar(string path, int place) const
{
	pWind->DrawImage(path, 0, (place + 1) * UI.MenuActionWidth, UI.MenuActionWidth - 3, UI.ToolBarHeight);
}

void Output::drawSoundIcon(bool on) {
	if (on)
		pWind->DrawImage("images\\MenuItems\\Menu_sound_ON.jpg", 23 * UI.MenuActionWidth, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
	else
		pWind->DrawImage("images\\MenuItems\\Menu_sound_OFF.jpg", 23 * UI.MenuActionWidth, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
}

void Output::drawResizeMenu() const
{
	pWind->DrawImage("images\\MenuItems\\sizes.jpg", UI.MenuActionWidth, UI.MenuActionWidth* DRAW_ACTION_COUNT, UI.MenuActionWidth * 4, UI.ToolBarHeight);
}

double Output::selectSize(Point p) const {
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
	pWind->DrawImage("images\\MenuItems\\colors_fill.jpg", UI.MenuActionWidth* (DRAW_ITM_COUNT + 4), 0, UI.MenuActionWidth * 7, UI.ToolBarHeight - 3);
}

void Output::drawDrawingColorMenu() const
{
	pWind->DrawImage("images\\MenuItems\\colors_draw.jpg", UI.MenuActionWidth* (DRAW_ITM_COUNT + 4), 0, UI.MenuActionWidth * 6, UI.ToolBarHeight - 3);
}

void Output::deleteColorMenu() const
{
	pWind->DrawImage("images\\MenuItems\\clean.jpg", UI.MenuActionWidth * (DRAW_ITM_COUNT + 4), 0, UI.MenuActionWidth * 7, UI.ToolBarHeight - 3);
}

color Output::selectFillColor(Point p) {

	if (p.y > 0 && p.y < UI.ToolBarHeight) {
		int selectedColor = ((p.x - (DRAW_ITM_COUNT + 3) * UI.MenuActionWidth) / UI.MenuActionWidth);

		switch (selectedColor) {
		case 1:
			pWind->DrawImage("images\\MenuItems\\Menu_fill_color_black.jpg", (ITM_FILL_COLOR)*UI.MenuItemWidth, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
			UI.FillColor = BLACK;
			filled = true;
			return BLACK;
		case 2:
			pWind->DrawImage("images\\MenuItems\\Menu_fill_color_white.jpg", (ITM_FILL_COLOR)*UI.MenuItemWidth, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
			UI.FillColor = WHITE;
			filled = true;
			return WHITE;
		case 3:
			pWind->DrawImage("images\\MenuItems\\Menu_fill_color_red.jpg", (ITM_FILL_COLOR)*UI.MenuItemWidth, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
			UI.FillColor = RED;
			filled = true;
			return RED;
		case 4:
			pWind->DrawImage("images\\MenuItems\\Menu_fill_color_yellow.jpg", (ITM_FILL_COLOR)*UI.MenuItemWidth, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
			UI.FillColor = YELLOW;
			filled = true;
			return YELLOW;
		case 5:
			pWind->DrawImage("images\\MenuItems\\Menu_fill_color_green.jpg", (ITM_FILL_COLOR)*UI.MenuItemWidth, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
			UI.FillColor = GREEN;
			filled = true;
			return GREEN;
		case 6:
			pWind->DrawImage("images\\MenuItems\\Menu_fill_color_blue.jpg", (ITM_FILL_COLOR)*UI.MenuItemWidth, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
			UI.FillColor = BLUE;
			filled = true;
			return BLUE;
		case 7:
			pWind->DrawImage("images\\MenuItems\\Menu_fill_color_No.jpg", (ITM_FILL_COLOR)*UI.MenuItemWidth, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
			filled = false;
			return NOFILL;
		}
	}

	return (filled) ? UI.FillColor : NOFILL;
}

bool Output::isFilled() {
	return filled;
}

color Output::selectDrawColor(Point p) {

	if (p.y > 0 && p.y < UI.ToolBarHeight) {
		int selectedColor = ((p.x - (DRAW_ITM_COUNT + 3) * UI.MenuActionWidth) / UI.MenuActionWidth);

		switch (selectedColor) {
		case 1:
			pWind->DrawImage("images\\MenuItems\\Menu_draw_color_black.jpg", (ITM_DRAW_COLOR)*UI.MenuItemWidth - 50, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
			UI.DrawColor = BLACK;
			return BLACK;
		case 2:
			pWind->DrawImage("images\\MenuItems\\Menu_draw_color_white.jpg", (ITM_DRAW_COLOR)*UI.MenuItemWidth - 50, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
			UI.DrawColor = WHITE;
			return WHITE;
		case 3:
			pWind->DrawImage("images\\MenuItems\\Menu_draw_color_red.jpg", (ITM_DRAW_COLOR)*UI.MenuItemWidth - 50, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
			UI.DrawColor = RED;
			return RED;
		case 4:
			pWind->DrawImage("images\\MenuItems\\Menu_draw_color_yellow.jpg", (ITM_DRAW_COLOR)*UI.MenuItemWidth - 50, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
			UI.DrawColor = YELLOW;
			return YELLOW;
		case 5:
			pWind->DrawImage("images\\MenuItems\\Menu_draw_color_green.jpg", (ITM_DRAW_COLOR)*UI.MenuItemWidth - 50, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
			UI.DrawColor = GREEN;
			return GREEN;
		case 6:
			pWind->DrawImage("images\\MenuItems\\Menu_draw_color_blue.jpg", (ITM_DRAW_COLOR)*UI.MenuItemWidth - 50, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
			UI.DrawColor = BLUE;
			return BLUE;
		}
	}

	return UI.DrawColor;
}

void Output::changeFillColorIcon(color c, bool filled) {
	if (!filled) {
		pWind->DrawImage("images\\MenuItems\\Menu_fill_color_No.jpg", (ITM_FILL_COLOR)*UI.MenuItemWidth, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
		filled = false;
	}
	else if (c == BLACK) {
		pWind->DrawImage("images\\MenuItems\\Menu_fill_color_black.jpg", (ITM_FILL_COLOR)*UI.MenuItemWidth, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
		UI.FillColor = BLACK;
	}
	else if (c == WHITE) {
		pWind->DrawImage("images\\MenuItems\\Menu_fill_color_white.jpg", (ITM_FILL_COLOR)*UI.MenuItemWidth, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
		UI.FillColor = WHITE;

	}
	else if (c == RED) {
		pWind->DrawImage("images\\MenuItems\\Menu_fill_color_red.jpg", (ITM_FILL_COLOR)*UI.MenuItemWidth, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
		UI.FillColor = RED;

	}
	else if (c == YELLOW) {
		pWind->DrawImage("images\\MenuItems\\Menu_fill_color_yellow.jpg", (ITM_FILL_COLOR)*UI.MenuItemWidth, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
		UI.FillColor = YELLOW;
	}
	else if (c == GREEN) {
		pWind->DrawImage("images\\MenuItems\\Menu_fill_color_green.jpg", (ITM_FILL_COLOR)*UI.MenuItemWidth, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
		UI.FillColor = GREEN;
	}
	else if (c == BLUE) {
		pWind->DrawImage("images\\MenuItems\\Menu_fill_color_blue.jpg", (ITM_FILL_COLOR)*UI.MenuItemWidth, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
		UI.FillColor = BLUE;
	}
}

void Output::changeDrawColorIcon(color c) {
	if (c == BLACK) {
		pWind->DrawImage("images\\MenuItems\\Menu_draw_color_black.jpg", (ITM_DRAW_COLOR)*UI.MenuItemWidth - 50, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
		UI.DrawColor = BLACK;
	}
	else if (c == WHITE) {
		pWind->DrawImage("images\\MenuItems\\Menu_draw_color_white.jpg", (ITM_DRAW_COLOR)*UI.MenuItemWidth - 50, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
		UI.DrawColor = WHITE;
	}
	else if (c == RED) {
		pWind->DrawImage("images\\MenuItems\\Menu_draw_color_red.jpg", (ITM_DRAW_COLOR)*UI.MenuItemWidth - 50, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
		UI.DrawColor = RED;
	}
	else if (c == YELLOW) {
		pWind->DrawImage("images\\MenuItems\\Menu_draw_color_yellow.jpg", (ITM_DRAW_COLOR)*UI.MenuItemWidth - 50, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
		UI.DrawColor = YELLOW;
	}
	else if (c == GREEN) {
		pWind->DrawImage("images\\MenuItems\\Menu_draw_color_green.jpg", (ITM_DRAW_COLOR)*UI.MenuItemWidth - 50, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
		UI.DrawColor = GREEN;
	}
	else if (c == BLUE) {
		pWind->DrawImage("images\\MenuItems\\Menu_draw_color_blue.jpg", (ITM_DRAW_COLOR)*UI.MenuItemWidth - 50, 0, UI.MenuActionWidth, UI.ToolBarHeight - 3);
		UI.DrawColor = BLUE;
	}
}


void Output::CreatePlayToolBar() const
{
	string nul = "images\\MenuItems\\clean.jpg";
	pWind->DrawImage(nul, 0, 0, UI.width, UI.ToolBarHeight);

	UI.InterfaceMode = MODE_PLAY;
	string PlayItemImages[PLAY_ITM_COUNT];
	PlayItemImages[ITM_DRAW] = "images\\MenuItems\\draw.jpg";
	PlayItemImages[ITM_COL_CLR] = "images\\MenuItems\\col_clr.jpg";
	PlayItemImages[ITM_COL_SHP] = "images\\MenuItems\\col_shp.jpg";
	PlayItemImages[ITM_EXIT1] = "images\\MenuItems\\EXIT1.jpg";

	pWind->DrawImage(PlayItemImages[ITM_DRAW], 0, 0, UI.MenuActionWidth + 30, UI.ToolBarHeight);
	pWind->DrawImage(PlayItemImages[ITM_COL_CLR], (10)*UI.MenuActionWidth, 0, UI.MenuActionWidth + 30, UI.ToolBarHeight - 3);
	pWind->DrawImage(PlayItemImages[ITM_COL_SHP], (12)*UI.MenuActionWidth, 0, UI.MenuActionWidth + 30, UI.ToolBarHeight - 3);
	pWind->DrawImage(PlayItemImages[ITM_EXIT1], (22)*UI.MenuActionWidth, 0, UI.MenuActionWidth + 30, UI.ToolBarHeight - 3);

	pWind->SetPen(MIDNIGHTBLUE, 3);
	pWind->DrawLine(0, UI.ToolBarHeight - 1.5, UI.width, UI.ToolBarHeight - 1.5);

	///TODO: write code to create Play mode menu
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

void Output::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(UI.MenuActionWidth, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar

	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight / 1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntDrawColor() const	//get current drawing color
{
	return UI.DrawColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntFillColor() const	//get current filling color
{
	return UI.FillColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

int Output::getCrntPenWidth() const		//get current pen width
{

	return UI.PenWidth;
}


//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

void Output::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 3);
	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);

}
void Output::DrawCircle(Point P1, Point P2, GfxInfo CircleGfxInfo, bool selected) const
{
	int radius = sqrt((pow(P2.x - P1.x, 2) + pow(P2.y - P1.y, 2))); //radius is the distance between two points P1(center) and any point P2
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = CircleGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 3);
	drawstyle style;
	if (CircleGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(CircleGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawCircle(P1.x, P1.y, radius, style);

}
void Output::DrawRhombus(Point P, GfxInfo RhomGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RhomGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 3);
	drawstyle style;
	if (RhomGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RhomGfxInfo.FillClr);
	}
	else
		style = FRAME;

	int X[4];
	int Y[4];
	X[0] = P.x;			X[1] = P.x + 120;	X[2] = P.x;			X[3] = P.x - 120;
	Y[0] = P.y + 60;	Y[1] = P.y;			Y[2] = P.y - 60;	Y[3] = P.y;

	pWind->DrawPolygon(X, Y, 4, style);

}

void Output::DrawRhombus(const int* X, const int* Y, GfxInfo RhomGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RhomGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 3);
	drawstyle style;
	if (RhomGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RhomGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawPolygon(X, Y, 4, style);
}

void Output::DrawEllipse(Point P, GfxInfo ElpsGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = ElpsGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 3);
	drawstyle style;
	if (ElpsGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(ElpsGfxInfo.FillClr);
	}
	else
		style = FRAME;
	Point P1, P2;
	P1.x = P.x - 120; P1.y = P.y + 60;
	P2.x = P.x + 120; P2.y = P.y - 60;

	pWind->DrawEllipse(P1.x, P1.y, P2.x, P2.y, style);

}

void Output::DrawEllipse(Point P1, Point P2, GfxInfo ElpsGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = ElpsGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 3);
	drawstyle style;
	if (ElpsGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(ElpsGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawEllipse(P1.x, P1.y, P2.x, P2.y, style);
}

void Output::DrawTriangle(Point P1, Point P2, Point P3, GfxInfo TriGfxInfo, bool selected) const
{

	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = TriGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 3);
	drawstyle style;
	if (TriGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(TriGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);

}
void Output::DrawLine(Point P1, Point P2, GfxInfo LineGfxInfo, bool selected) const
{

	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = LineGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 3);
	drawstyle style;
	style = FRAME;
	pWind->DrawLine(P1.x, P1.y, P2.x, P2.y, style);

}

void Output::getValidPoint(Point& P) const {
	Input* pIn = new Input(pWind);
	while (true) {
		pIn->GetPointClicked(P.x, P.y);

		if (P.y < UI.ToolBarHeight || P.y > UI.height - UI.StatusBarHeight || P.x < UI.MenuActionWidth) {
			PrintMessage("Please Select a Valid Point");
		}
		else
			break;
	}
}

void Output::getValidEllipsePoint(Point& P) const {
	Input* pIn = new Input(pWind);
	while (true) {
		pIn->GetPointClicked(P.x, P.y);

		if (P.y < UI.ToolBarHeight + 60 || P.y > UI.height - UI.StatusBarHeight - 60 || P.x < UI.MenuActionWidth + 120) {
			PrintMessage("Please Select a Valid Point");
		}
		else
			break;
	}
}

void Output::getValidRhombusPoint(Point& P) const {
	Input* pIn = new Input(pWind);
	while (true) {
		pIn->GetPointClicked(P.x, P.y);

		if (P.y < UI.ToolBarHeight + 60 || P.y > UI.height - UI.StatusBarHeight - 60 || P.x < UI.MenuActionWidth + 120) {
			PrintMessage("Please Select a Valid Point");
		}
		else
			break;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}

