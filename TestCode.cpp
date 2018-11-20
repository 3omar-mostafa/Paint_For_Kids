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

	///////////////////////////////////////////////////////////////////////////////////
	// TEST 1:	
	//			Create The FULL Tool bar, the drawing area and the status bar	
	//			This has already been done through the constrcutor of class Output
	///////////////////////////////////////////////////////////////////////////////////

	pOut->PrintMessage("TEST1: Drawing Toolbar and Status bar, Click anywhere to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click


	///////////////////////////////////////////////////////////////////////////////////
	// TEST 2:	
	//			Drawing all the Figures with all possible states: 
	//			Non-filled, Filled, and highlighted in both cases			
	///////////////////////////////////////////////////////////////////////////////////

	pOut->PrintMessage("TEST2: Now we will show that the Output class can draw any figure in any state, Click anywhere to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	GfxInfo gfxInfo; //to be used with draw function of the class Ouput
	Point P1, P2, P3;

	gfxInfo.BorderWdth = 12;
	gfxInfo.DrawClr = BLACK;			//any color for border
	gfxInfo.FillClr = MEDIUMAQUAMARINE;	//any color for filling



	/// 2.1- Rectangle Test ///
	/// =================== 
	pOut->PrintMessage("Drawing a Rectangle, filled/non-filled and Highlighted filled/non-filled,  Click to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	// 2.1.1 - Drawing filled rectangle
	//pOut->PrintMessage("Drawing a Rectangle ==> non-filled,  Click two points");  ***Commented this line and removed all similar lines to keep the status bar statements consistent
	pOut->PrintMessage("Click 2 Points, Filled");
	gfxInfo.isFilled = true;	//Figure is filled
	pOut->DrawRect( gfxInfo, false);

	// 2.1.2 - Drawing non-filled rectangle
	pOut->PrintMessage("Click 2 Points, Non-Filled");
	gfxInfo.isFilled = false;
	pOut->DrawRect( gfxInfo, false);

	// 2.1.3 - Drawing a highlighted filled rectangle
	pOut->PrintMessage("Click 2 Points, Highlighted Filled");
	gfxInfo.isFilled = true;
	pOut->DrawRect( gfxInfo, true);


	// 2.1.4 - Drawing a highlighted non-filled rectangle
	pOut->PrintMessage("Click 2 Points, Highlighted Non-Filled");
	gfxInfo.isFilled = false;
	pOut->DrawRect(gfxInfo, true);

		
	pOut->PrintMessage("Drawing a Rectangle Test ==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->ClearDrawArea();



	/// 2.2- Line Test ///
	/// ============== 
	pOut->PrintMessage("Drawing a Line, Normal and Highlighted, Click to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click


	///TODO: Add code to draw Line, Normal and Highlighted
	// 2.2.1 - Drawing a normal line
	pOut->PrintMessage("Click 2 Points, Normal");
	pOut->DrawLine( gfxInfo, false);

	// 2.2.2 - Drawing a highlighted line
	pOut->PrintMessage("Click 2 Points, Highlighted");
	pOut->DrawLine( gfxInfo, true);

		
	pOut->PrintMessage("Drawing a Line Test ==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->ClearDrawArea();



	/// 2.3- Triangle Test ///
	/// =================== 
	pOut->PrintMessage("Drawing a Triangle, filled/non-filled and Highlighted filled/non-filled,  Click to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	///TODO: Add code to draw Triangle in all possible states
	// 2.3.1 - Drawing a filled triangle
	pOut->PrintMessage("Click 3 Points, Filled");
	gfxInfo.isFilled = true;
	pOut->DrawTriangle( gfxInfo, false);

	// 2.3.2 - Drawing a non-filled triangle
	pOut->PrintMessage("Click 3 Points, Non-Filled");
	gfxInfo.isFilled = false;
	pOut->DrawTriangle( gfxInfo, false);

	// 2.3.3 - Drawing a highlighted filled triangle
	pOut->PrintMessage("Click 3 Points, Highlighted Filled");
	gfxInfo.isFilled = true;
	pOut->DrawTriangle( gfxInfo, true);

	// 2.3.4 - Drawing a highlighted non-filled triangle
	pOut->PrintMessage("Click 3 Points, Highlighted Non-Filled");
	gfxInfo.isFilled = false;
	pOut->DrawTriangle( gfxInfo, true);

		
	pOut->PrintMessage("Drawing a Triangle Test ==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->ClearDrawArea();



	/// 2.4- Rhombus Test ///
	/// =================== 
	pOut->PrintMessage("Drawing a Rhombus, filled/non-filled and Highlighted filled/non-filled,  Click to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	///TODO: Add code to draw Rhombus in all possible states
	// 2.4.1 - Drawing a filled rhombus
	pOut->PrintMessage("Click 1 Point, Filled");
	gfxInfo.isFilled = true;
	pOut->DrawRhombus(gfxInfo, false);

	// 2.4.2 - Drawing a non-filled rhombus
	pOut->PrintMessage("Click 1 Point, Non-Filled");
	gfxInfo.isFilled = false;
	pOut->DrawRhombus(gfxInfo, false);

	// 2.4.3 - Drawing a highlighted filled rhombus
	pOut->PrintMessage("Click 1 Point, Highlighted Filled");
	gfxInfo.isFilled = true;
	pOut->DrawRhombus(gfxInfo, true);

	// 2.4.4 - Drawing a highlighted non-filled rhombus
	pOut->PrintMessage("Click 1 Point, Highlighted Non-Filled");
	gfxInfo.isFilled = false;
	pOut->DrawRhombus(gfxInfo, true);
		
	
	pOut->PrintMessage("Drawing a Rhombus Test ==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->ClearDrawArea();



	/// 2.5- Ellipse Test ///
	/// =================== 
	pOut->PrintMessage("Drawing an Ellipse, filled/non-filled and Highlighted filled/non-filled,  Click to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	///TODO: Add code to draw Ellipse in all possible states
	// 2.5.1 - Drawing a filled ellipse
	pOut->PrintMessage("Click 1 Point, Filled");
	gfxInfo.isFilled = true;
	pOut->DrawEllipse(gfxInfo, false);

	// 2.5.2 - Drawing a non-filled ellipse
	pOut->PrintMessage("Click 1 Point, Non-Filled");
	gfxInfo.isFilled = false;
	pOut->DrawEllipse(gfxInfo, false);

	// 2.5.3 - Drawing a highlighted filled ellipse
	pOut->PrintMessage("Click 1 Point, Highlighted Filled");
	gfxInfo.isFilled = true;
	pOut->DrawEllipse(gfxInfo, true);

	// 2.5.4 - Drawing a highlighted non-filled ellipse
	pOut->PrintMessage("Click 1 Point, Highlighted Non-Filled");
	gfxInfo.isFilled = false;
	pOut->DrawEllipse(gfxInfo, true);

		
	pOut->PrintMessage("Drawing a Ellipse Test ==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->ClearDrawArea();

	

	///////////////////////////////////////////////////////////////////////////////////
	// TEST 3: 
	//			Input Class: Read strings from the user
	///////////////////////////////////////////////////////////////////////////////////
	pOut->PrintMessage("TEST3: Now, time to test the Input class, Click anywhere to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	pOut->PrintMessage("Testing the Input class's ability to read strings, Enter a string");

	///TODO: Add code here to 
	// 1- Read a string from the user on the status bar
	// 2- After reading the string clear the status bar
	// 3- Print on the status bar "You Entered" then print the string
	pOut->PrintMessage("You entered " + pIn->GetString(pOut) + ",  Click anywhere to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->ClearDrawArea();

	

	///////////////////////////////////////////////////////////////////////////////////
	// TEST 4: 
	//			Input Class : Check for the user action
	///////////////////////////////////////////////////////////////////////////////////
	pOut->PrintMessage("TEST4: Testing the Input class's ability to detect User Action, Click anywhere");

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
			pOut->PrintMessage("Action: Draw a Rectangle, Click Anywhere");
			break;

		case DRAW_LINE:
			pOut->CreateDrawToolBar();
			pOut->drawOnToolbar("images\\MenuItems\\Menu_Line_Selected.jpg", ITM_LINE);
			pOut->PrintMessage("Action: Draw a Line, Click Anywhere");
			break;

		case DRAW_RHOMBUS:
			pOut->CreateDrawToolBar();
			pOut->drawOnToolbar("images\\MenuItems\\Menu_Rhombus_Selected.jpg", ITM_RHOMBUS);
			pOut->PrintMessage("Action: Draw a Rhombus, Click Anywhere");
			break;

		case DRAW_ELLIPSE:
			pOut->CreateDrawToolBar();
			pOut->drawOnToolbar("images\\MenuItems\\Menu_Circ_Selected.jpg", ITM_CIRCLE);
			pOut->PrintMessage("Action: Draw an Ellipse, Click Anywhere");
			break;

		case DRAW_TRI:
			pOut->CreateDrawToolBar();
			pOut->drawOnToolbar("images\\MenuItems\\Menu_Triangle_Selected.jpg", ITM_TRIANGLE);
			pOut->PrintMessage("Action: Draw a Triangle, Click Anywhere");
			break;

		case CHNG_DRAW_CLR:
			pOut->PrintMessage("Action: Change Figure's drawing color, Click Anywhere");
			pOut->CreateDrawActionToolBar();
			pOut->drawColorMenu();
			while (true) {
				pIn->GetPointClicked(P1.x, P1.y);
				if (P1.x > UI.MenuActionWidth || P1.y < (ITM_SAVE_TYPE + 1) * UI.MenuActionWidth || P1.y >(ITM_FILL_COLOR + 1) * UI.MenuActionWidth) {
					pOut->deleteColorMenu();
					pOut->CreateDrawToolBar();
					break;
				}
				pOut->selectDrawColor(P1, gfxInfo.DrawClr);
			}
			break;

		case CHNG_FILL_CLR:
			pOut->PrintMessage("Action: Change Figure's fill color, Click Anywhere");
			pOut->CreateDrawActionToolBar();
			pOut->drawColorMenu();
			while (true) {
				pIn->GetPointClicked(P1.x, P1.y);
				if (P1.x > UI.MenuActionWidth || P1.y < (ITM_SAVE_TYPE + 1)* UI.MenuActionWidth || P1.y >(ITM_FILL_COLOR + 1) * UI.MenuActionWidth) {
					pOut->deleteColorMenu();
					pOut->CreateDrawToolBar();
					break;
				}
				pOut->selectFillColor(P1, gfxInfo.FillClr, gfxInfo.isFilled);
			}
			break;

		case STATUS:
			pOut->PrintMessage("Action: A Click on the Status Bar, Click Anywhere");
			break;

		case LOAD:
			pOut->PrintMessage("Action: Load, Click Anywhere");
			pOut->CreateDrawActionToolBar();
			pOut->drawOnActionbar("images\\MenuItems\\Menu_Load_Selected.jpg", ITM_LOAD);
			break;

		case SAVE:
			pOut->PrintMessage("Action: Save, Click Anywhere");
			pOut->CreateDrawActionToolBar();
			pOut->drawOnActionbar("images\\MenuItems\\Menu_save_Selected.jpg", ITM_SAVE);
			break;

		case SAVE_BY_TYPE:
			pOut->PrintMessage("Action: Save by Type, Click Anywhere");
			pOut->CreateDrawActionToolBar();
			pOut->drawOnActionbar("images\\MenuItems\\Menu_save_type_Selected.jpg", ITM_SAVE_TYPE);
			break;

		case COPY:
			pOut->PrintMessage("Action: Copy, Click Anywhere");
			pOut->CreateDrawActionToolBar();
			pOut->drawOnActionbar("images\\MenuItems\\Menu_copy_Selected.jpg", ITM_COPY);
			break;

		case CUT:
			pOut->PrintMessage("Action: Cut, Click Anywhere");
			pOut->CreateDrawActionToolBar();
			pOut->drawOnActionbar("images\\MenuItems\\Menu_Cut_Selected.jpg", ITM_CUT);
			break;

		case PASTE:
			pOut->PrintMessage("Action: Paste, Click Anywhere");
			pOut->CreateDrawActionToolBar();
			pOut->drawOnActionbar("images\\MenuItems\\Menu_Paste_Selected.jpg", ITM_PASTE);
			break;
		case DEL:
			pOut->PrintMessage("Action: Delete, Click Anywhere");
			pOut->CreateDrawActionToolBar();
			pOut->drawOnActionbar("images\\MenuItems\\Menu_delete_Selected.jpg", ITM_DELETE);
			break;

		case CLEAR:
			pOut->PrintMessage("Action: Clear Drawing Area, Click Anywhere");
			pOut->CreateDrawActionToolBar();
			pOut->ClearDrawArea();
			break;


		case SELECT:
			pOut->PrintMessage("Action: Select, Click Anywhere");
			pOut->CreateDrawActionToolBar();
			pOut->drawOnActionbar("images\\MenuItems\\Menu_select_Selected.jpg", ITM_SELECT);
			break;
 
		case DRAWING_AREA:
			pOut->PrintMessage("Action: A Click on the Drawing Area, Click Anywhere");
			break;

		case EMPTY:
			pOut->PrintMessage("Action: A Click on an Empty Area in the Design Toolbar, Click Anywhere");
			break;

		case TO_DRAW:
			pOut->PrintMessage("Action: Switch to Draw Mode, Creating Simulation Toolbar");
			pOut->playOnToolbar("images\\MenuItems\\draw_selected.jpg", ITM_DRAW);
			pOut->CreateDrawToolBar();
			pOut->CreateDrawActionToolBar();
			pOut->CreateColorIcons();
			break;

		case TO_PLAY:
			pOut->PrintMessage("Action: Switch to Play Mode, Creating Design Toolbar");				
			pOut->drawOnToolbar("images\\MenuItems\\Menu_game_Selected.jpg", ITM_GAME);
			pOut->removeDrawActionToolBar();
			pOut->CreatePlayToolBar();
			//TODO: Temporary Commenting until we build it
			break;

		case COL_CLR:
			pOut->CreatePlayToolBar();
			pOut->PrintMessage("Action: Collecting by Color, Click Anywhere");
			pOut->playOnToolbar("images\\MenuItems\\col_clr_selected.jpg", ITM_COL_CLR);
			break;

		case COL_SHP:
			pOut->CreatePlayToolBar();
			pOut->PrintMessage("Action: Collecting by Shape, Click Anywhere");
			pOut->playOnToolbar("images\\MenuItems\\col_shp_selected.jpg", ITM_COL_SHP);
			break;

		case EXIT:				
			break;
		}
	} while(ActType != EXIT);


	/// Exiting
	pOut->PrintMessage("Action: EXIT, Click Anywhere to Exit");
	pIn->GetPointClicked(x,y);


	delete pIn;
	delete pOut;	
	return 0;
}


