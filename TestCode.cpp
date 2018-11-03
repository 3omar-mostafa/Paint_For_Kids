#include "GUI\Input.h"
#include "GUI\Output.h"

//This is a test code to test the Input and Output classes

int main()
{
	int x, y;

	//Create Input and Output objects to test
	Output *pOut = new Output();
	Input *pIn = pOut->CreateInput();

	//Starting the test
	pOut->PrintMessage("This demo is to test input and output classes, Click anywhere to start the test");
	pIn->GetPointClicked(x, y);	//Wait for any click

	GfxInfo gfxInfo; //to be used with draw function of the class Ouput
	Point P1, P2, P3;




	ActionType ActType;
	
	///TODO:  
	//You must add a case for each action (both Draw mode and Play mode actions)
	//Add cases for the missing actions below
	do
	{
		ActType = pIn->GetUserAction();

		switch (ActType)
		{
		case DRAW_RECT:
			pOut->CreateDrawToolBar();
			pOut->drawOnToolbar("images\\MenuItems\\Menu_Rect_Selected.jpg", ITM_RECT);
			pOut->PrintMessage("Action: Draw a Rectangle, Click 2 Points");

			while (true)
			{
				pIn->GetPointClicked(P1.x, P1.y);
				if (P1.y < UI.ToolBarHeight) break;
				while (P1.y > UI.height - UI.StatusBarHeight)
				{
					pOut->PrintMessage("Choose a valid point");
					pIn->GetPointClicked(P1.x, P1.y);
				}

				pOut->PrintMessage("Click point 2");

				pIn->GetPointClicked(P2.x, P2.y);
				if (P2.y < UI.ToolBarHeight) break;
				while (P2.y > UI.height - UI.StatusBarHeight)
				{
					pOut->PrintMessage("Choose a valid point");
					pIn->GetPointClicked(P2.x, P2.y);
				}

				pOut->DrawRect(P1, P2, gfxInfo, false);
				pOut->CreateDrawToolBar();
				break;
			}

			break;

		case DRAW_LINE:
			pOut->CreateDrawToolBar();
			pOut->drawOnToolbar("images\\MenuItems\\Menu_Line_Selected.jpg", ITM_LINE);
			pOut->PrintMessage("Action: Draw a Line, Click 2");

			while (true)
			{
				pIn->GetPointClicked(P1.x, P1.y);
				if (P1.y < UI.ToolBarHeight) break;
				while (P1.y > UI.height - UI.StatusBarHeight)
				{
					pOut->PrintMessage("Choose a valid point");
					pIn->GetPointClicked(P1.x, P1.y);
				}

				pOut->PrintMessage("Click point 2");

				pIn->GetPointClicked(P2.x, P2.y);
				if (P2.y < UI.ToolBarHeight) break;
				while (P2.y > UI.height - UI.StatusBarHeight)
				{
					pOut->PrintMessage("Choose a valid point");
					pIn->GetPointClicked(P2.x, P2.y);
				}

				pOut->DrawLine(P1, P2, gfxInfo, false);
				pOut->CreateDrawToolBar();
				break;
			}
			break;

		case DRAW_RHOMBUS:
			pOut->CreateDrawToolBar();
			pOut->drawOnToolbar("images\\MenuItems\\Menu_Rhombus_Selected.jpg", ITM_RHOMBUS);
			pOut->PrintMessage("Action: Draw a Rhombus, Click 1");

			while (true)
			{
				pIn->GetPointClicked(P1.x, P1.y);
				if (P1.y < UI.ToolBarHeight) break;
				while (P1.y > UI.height - (UI.StatusBarHeight + 100))
				{
					pOut->PrintMessage("Choose a valid point(Higher)");
					pIn->GetPointClicked(P1.x, P1.y);
				}

				pOut->DrawRhombus(P1, gfxInfo, false);
				pOut->CreateDrawToolBar();
				break;
			}

			break;

		case DRAW_ELLIPSE:
			pOut->CreateDrawToolBar();
			pOut->drawOnToolbar("images\\MenuItems\\Menu_Circ_Selected.jpg", ITM_CIRCLE);
			pOut->PrintMessage("Action: Draw an Ellipse, Click 1");

			while (true)
			{
				pIn->GetPointClicked(P1.x, P1.y);
				if (P1.y < UI.ToolBarHeight) break;
				while (P1.y > UI.height - (UI.StatusBarHeight + 80))
				{
					pOut->PrintMessage("Choose a valid point(Higher)");
					pIn->GetPointClicked(P1.x, P1.y);
				}

				pOut->DrawEllipse(P1, gfxInfo, false);
				pOut->CreateDrawToolBar();
				break;
			}
			break;

		case DRAW_TRI:
			pOut->CreateDrawToolBar();
			pOut->drawOnToolbar("images\\MenuItems\\Menu_Triangle_Selected.jpg", ITM_TRIANGLE);
			pOut->PrintMessage("Action: Draw a Triangle, Click 3");

			while (true)
			{
				pIn->GetPointClicked(P1.x, P1.y);
				if (P1.y < UI.ToolBarHeight) break;
				while (P1.y > UI.height - UI.StatusBarHeight)
				{
					pOut->PrintMessage("Choose a valid point");
					pIn->GetPointClicked(P1.x, P1.y);
				}

				pOut->PrintMessage("Click point 2");

				pIn->GetPointClicked(P2.x, P2.y);
				if (P2.y < UI.ToolBarHeight) break;
				while (P2.y > UI.height - UI.StatusBarHeight)
				{
					pOut->PrintMessage("Choose a valid point");
					pIn->GetPointClicked(P2.x, P2.y);
				}

				pOut->PrintMessage("Click point 3");

				pIn->GetPointClicked(P3.x, P3.y);
				if (P3.y < UI.ToolBarHeight) break;
				while (P3.y > UI.height - UI.StatusBarHeight)
				{
					pOut->PrintMessage("Choose a valid point");
					pIn->GetPointClicked(P3.x, P3.y);
				}

				pOut->DrawTriangle(P1, P2, P3, gfxInfo, false);
				pOut->CreateDrawToolBar();
				break;
			}
			break;

		case CHNG_DRAW_CLR:
				pOut->PrintMessage("Action: Change Figure's drawing color , Click anywhere");
				pOut->CreateDrawToolBar();
				pOut->drawOnToolbar("images\\MenuItems\\Menu_draw_color_Selected.jpg", ITM_DRAW_COLOR);
				break;

		case CHNG_FILL_CLR:
				pOut->PrintMessage("Action: Change Figure's Fill color , Click anywhere");
				pOut->drawColorMenu();
				while (true) {
					pIn->GetPointClicked(P1.x, P1.y);
					if ( P1.x < 9 * UI.MenuActionWidth || P1.x > 10 * UI.MenuActionWidth || P1.y > 7 * UI.MenuActionWidth ) {
						pOut->deleteolorMenu();
						pOut->CreateDrawToolBar();
						break;
					}
					pOut->selectColor(P1, gfxInfo.FillClr, gfxInfo.isFilled);
				}
				
				break;

		case STATUS:
				pOut->PrintMessage("Action: a click on the Status Bar, Click anywhere");
				break;
		case COPY:
				pOut->PrintMessage("Action: copy , Click anywhere");
				pOut->CreateDrawToolBar();
				pOut->drawOnToolbar("images\\MenuItems\\Menu_copy_Selected.jpg", ITM_COPY);
				break;
		case CUT:
				pOut->PrintMessage("Action: cut , Click anywhere");
				pOut->CreateDrawToolBar();
				pOut->drawOnToolbar("images\\MenuItems\\Menu_Cut_Selected.jpg", ITM_CUT);
				break;
		case PASTE:
				pOut->PrintMessage("Action: paste , Click anywhere");
				pOut->CreateDrawToolBar();
				pOut->drawOnToolbar("images\\MenuItems\\Menu_Paste_Selected.jpg", ITM_PASTE);
				break;
		case DEL:
				pOut->PrintMessage("Action: delete, Click anywhere");
				pOut->CreateDrawToolBar();
				pOut->drawOnToolbar("images\\MenuItems\\Menu_delete_Selected.jpg", ITM_DELETE);
				break;
		case CLEAR:
				pOut->PrintMessage("Action: Clear Drawing Area");
				pOut->CreateDrawToolBar();
				pOut->ClearDrawArea();
				break;
		case SAVE:
				pOut->PrintMessage("Action: save, Click anywhere");
				pOut->CreateDrawToolBar();
				pOut->drawOnToolbar("images\\MenuItems\\Menu_save_Selected.jpg", ITM_SAVE);
				break;

		case SELECT:
				pOut->PrintMessage("Action: select , Click anywhere");
				pOut->CreateDrawToolBar();
				pOut->drawOnToolbar("images\\MenuItems\\Menu_select_Selected.jpg", ITM_SELECT);
				break;
 
		case DRAWING_AREA:
				pOut->PrintMessage("Action: a click on the Drawing Area, Click anywhere");
				break;

		case EMPTY:
				pOut->PrintMessage("Action: a click on empty area in the Design Tool Bar, Click anywhere");
				break;

		case TO_DRAW:
				pOut->PrintMessage("Action: Switch to Draw Mode, creating simualtion tool bar");
				pOut->playOnToolbar("images\\MenuItems\\draw_selected.jpg", ITM_DRAW);
				pOut->CreateDrawToolBar();
				break;

		case TO_PLAY:
				pOut->PrintMessage("Action: Switch to Play Mode, creating Design tool bar");
				
				pOut->drawOnToolbar("images\\MenuItems\\Menu_game_Selected.jpg", ITM_GAME);

				pOut->CreatePlayToolBar();
				//TODO: Temporary Commenting until we build it
				break;
		case COL_CLR:
			pOut->CreatePlayToolBar();
			pOut->PrintMessage("Action: Collecting by color");

			pOut->playOnToolbar("images\\MenuItems\\col_clr_selected.jpg", ITM_COL_CLR);
			break;
		case COL_SHP:
			pOut->CreatePlayToolBar();
			pOut->PrintMessage("Action: Collecting by Shape");

			pOut->playOnToolbar("images\\MenuItems\\col_shp_selected.jpg", ITM_COL_SHP);
			break;

		case EXIT:				
				break;
		}
		pOut->PrintMessage("Action performed! Click anywhere.");
	}while(ActType != EXIT);


	/// Exiting
	pOut->PrintMessage("Action: EXIT, test is finished, click anywhere to exit");
	pIn->GetPointClicked(x,y);


	delete pIn;
	delete pOut;	
	return 0;
}


