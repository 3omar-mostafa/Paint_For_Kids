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

	pOut->PrintMessage("TEST1: Drawing Tool bar and Status bar, Click anywhere to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click


	///////////////////////////////////////////////////////////////////////////////////
	// TEST 2:	
	//			Drawing all the Figures with all possible states: 
	//			Non-filled, Filled, and highlighted in both cases			
	///////////////////////////////////////////////////////////////////////////////////

	pOut->PrintMessage("TEST2: Now we will show that Output class can draw any figure in any state, Click anywhere to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	GfxInfo gfxInfo; //to be used with draw function of the class Ouput
	Point P1, P2, P3;

	/// 2.1- Rectangle Test ///
	/// =================== 
	pOut->PrintMessage("Drawing a Rectangle, filled/non-filled and Highlighted filled/non-filled,  Click to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	// 2.1.1 - Drawing filled rectangle
	//pOut->PrintMessage("Drawing a Rectangle ==> non-filled,  Click two points");  ***Commented this line and removed all similar lines to keep the status bar statements consistent
	pOut->PrintMessage("Click 2, Filled");

	gfxInfo.BorderWdth = 12;
	gfxInfo.DrawClr = BLACK;	 //any color for border
	gfxInfo.FillClr = MEDIUMAQUAMARINE; //any color for filling
	gfxInfo.isFilled = true;	//Figure is filled

	pIn->GetPointClicked(P1.x, P1.y);
	pIn->GetPointClicked(P2.x, P2.y);
	pOut->DrawRect(P1, P2, gfxInfo, false);

	// 2.1.2 - Drawing non-filled rectangle
	pOut->PrintMessage("Click 2, Non-Filled");
	gfxInfo.isFilled = false;
	pIn->GetPointClicked(P1.x, P1.y);
	pIn->GetPointClicked(P2.x, P2.y);
	pOut->DrawRect(P1, P2, gfxInfo, false);

	// 2.1.3 - Drawing a highlighted filled rectangle
	pOut->PrintMessage("Click 2, Highlighted Filled");
	gfxInfo.isFilled = true;
	pIn->GetPointClicked(P1.x, P1.y);
	pIn->GetPointClicked(P2.x, P2.y);
	pOut->DrawRect(P1, P2, gfxInfo, true);


	// 2.1.4 - Drawing a highlighted non-filled rectangle
	pOut->PrintMessage("Click 2, Highlighted Non-Filled");
	gfxInfo.isFilled = false;
	pIn->GetPointClicked(P1.x, P1.y);
	pIn->GetPointClicked(P2.x, P2.y);
	pOut->DrawRect(P1, P2, gfxInfo, true);



	pOut->PrintMessage("Drawing a Rectangle Test ==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->ClearDrawArea();

	/// 2.2- Line Test ///
	/// ============== 
	pOut->PrintMessage("Drawing a Line, Normal and Highlighted, Click to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click


	///TODO: Add code to draw Line, Normal and Highlighted
	// 2.2.1 - Drawing a normal line
	pOut->PrintMessage("Click 2, Normal");
	pIn->GetPointClicked(P1.x, P1.y);
	pIn->GetPointClicked(P2.x, P2.y);
	pOut->DrawLine(P1, P2, gfxInfo, false);

	// 2.2.2 - Drawing a highlighted line
	pOut->PrintMessage("Click 2, Highlighted");
	pIn->GetPointClicked(P1.x, P1.y);
	pIn->GetPointClicked(P2.x, P2.y);
	pOut->DrawLine(P1, P2, gfxInfo, true);

	pOut->PrintMessage("Drawing a Line Test ==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	pOut->ClearDrawArea();



	/// 2.3- Triangle Test ///
	/// =================== 
	pOut->PrintMessage("Drawing a Triangle, filled/non-filled and Highlighted filled/non-filled,  Click to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	///TODO: Add code to draw Triangle in all possible states
	// 2.3.1 - Drawing a filled triangle
	pOut->PrintMessage("Click 3, Filled");
	gfxInfo.isFilled = true;
	pIn->GetPointClicked(P1.x, P1.y);
	pIn->GetPointClicked(P2.x, P2.y);
	pIn->GetPointClicked(P3.x, P3.y);
	pOut->DrawTriangle(P1, P2, P3, gfxInfo, false);

	// 2.3.2 - Drawing a non-filled triangle
	pOut->PrintMessage("Click 3, Non-Filled");
	gfxInfo.isFilled = false;
	pIn->GetPointClicked(P1.x, P1.y);
	pIn->GetPointClicked(P2.x, P2.y);
	pIn->GetPointClicked(P3.x, P3.y);
	pOut->DrawTriangle(P1, P2, P3, gfxInfo, false);

	// 2.3.3 - Drawing a highlighted filled triangle
	pOut->PrintMessage("Click 3, Highlighted Filled");
	gfxInfo.isFilled = true;
	pIn->GetPointClicked(P1.x, P1.y);
	pIn->GetPointClicked(P2.x, P2.y);
	pIn->GetPointClicked(P3.x, P3.y);
	pOut->DrawTriangle(P1, P2, P3, gfxInfo, true);

	// 2.3.4 - Drawing a highlighted non-filled triangle
	pOut->PrintMessage("Click 3, Highlighted Non-Filled");
	gfxInfo.isFilled = false;
	pIn->GetPointClicked(P1.x, P1.y);
	pIn->GetPointClicked(P2.x, P2.y);
	pIn->GetPointClicked(P3.x, P3.y);
	pOut->DrawTriangle(P1, P2, P3, gfxInfo, true);

	pOut->PrintMessage("Drawing a Triangle Test ==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->ClearDrawArea();

	/// 2.4- Rhombus Test ///
	/// =================== 
	pOut->PrintMessage("Drawing a Rhombus, filled/non-filled and Highlighted filled/non-filled,  Click to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	///TODO: Add code to draw Rhombus in all possible states
	// 2.4.1 - Drawing a filled rhombus
	pOut->PrintMessage("Click 1, Filled");
	gfxInfo.isFilled = true;
	pIn->GetPointClicked(P1.x, P1.y);
	pOut->DrawRhombus(P1, gfxInfo, false);

	// 2.4.2 - Drawing a non-filled rhombus
	pOut->PrintMessage("Click 1, Non-Filled");
	gfxInfo.isFilled = false;
	pIn->GetPointClicked(P1.x, P1.y);
	pOut->DrawRhombus(P1, gfxInfo, false);

	// 2.4.3 - Drawing a highlighted filled rhombus
	pOut->PrintMessage("Click 1, Highlighted Filled");
	gfxInfo.isFilled = true;
	pIn->GetPointClicked(P1.x, P1.y);
	pOut->DrawRhombus(P1, gfxInfo, true);

	// 2.4.4 - Drawing a highlighted non-filled rhombus
	pOut->PrintMessage("Click 1, Highlighted Non-Filled");
	gfxInfo.isFilled = false;
	pIn->GetPointClicked(P1.x, P1.y);
	pOut->DrawRhombus(P1, gfxInfo, true);



	pOut->PrintMessage("Drawing a Rhombus Test ==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->ClearDrawArea();

	/// 2.5- Ellipse Test ///
	/// =================== 
	pOut->PrintMessage("Drawing an Ellipse, filled/non-filled and Highlighted filled/non-filled,  Click to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	///TODO: Add code to draw Ellipse in all possible states
	// 2.5.1 - Drawing a filled ellipse
	pOut->PrintMessage("Click 1, Filled");
	gfxInfo.isFilled = true;
	pIn->GetPointClicked(P1.x, P1.y);
	pOut->DrawEllipse(P1, gfxInfo, false);

	// 2.5.2 - Drawing a non-filled ellipse
	pOut->PrintMessage("Click 1, Non-Filled");
	gfxInfo.isFilled = false;
	pIn->GetPointClicked(P1.x, P1.y);
	pOut->DrawEllipse(P1, gfxInfo, false);

	// 2.5.3 - Drawing a highlighted filled ellipse
	pOut->PrintMessage("Click 1, Highlighted Filled");
	gfxInfo.isFilled = true;
	pIn->GetPointClicked(P1.x, P1.y);
	pOut->DrawEllipse(P1, gfxInfo, true);

	// 2.5.4 - Drawing a highlighted non-filled ellipse
	pOut->PrintMessage("Click 1, Highlighted Non-Filled");
	gfxInfo.isFilled = false;
	pIn->GetPointClicked(P1.x, P1.y);
	pOut->DrawEllipse(P1, gfxInfo, true);

	pOut->PrintMessage("Drawing a Ellipse Test ==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->ClearDrawArea();

	///////////////////////////////////////////////////////////////////////////////////
	// TEST 3: 
	//			Input Class: Read strings from the user
	///////////////////////////////////////////////////////////////////////////////////
	pOut->PrintMessage("TEST3: Now Time to test class Input, Click anywhere to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	pOut->PrintMessage("Testing Input ability to read strings");

	///TODO: Add code here to 
	// 1- Read a string from the user on the status bar
	// 2- After reading the string clear the status bar
	// 3- Print on the status bar "You Entered" then print the string
	pOut->PrintMessage("You entered " + pIn->GetString(pOut) + ".");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->ClearDrawArea();

	///////////////////////////////////////////////////////////////////////////////////
	// TEST 4: 
	//			Input Class : Check for the user action
	///////////////////////////////////////////////////////////////////////////////////
	pOut->PrintMessage("TEST4: Testing Input ability to detect User Action, click anywhere");

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
			    pOut->PrintMessage("Action: Draw a Rectangle, Click 2");
				gfxInfo.FillClr = GREEN;
				gfxInfo.isFilled = true;
				pIn->GetPointClicked(P1.x, P1.y);
				pIn->GetPointClicked(P2.x, P2.y);
				pOut->DrawRect(P1, P2, gfxInfo, false);
				break;

		case DRAW_LINE:
				pOut->CreateDrawToolBar();
				pOut->drawOnToolbar("images\\MenuItems\\Menu_Line_Selected.jpg", ITM_LINE);
			    pOut->PrintMessage("Action: Draw a Line, Click 2");
				gfxInfo.FillClr = BLACK;
				gfxInfo.isFilled = true;
				pIn->GetPointClicked(P1.x, P1.y);
				pIn->GetPointClicked(P2.x, P2.y);
				pOut->DrawLine(P1, P2, gfxInfo, false);
				break;

		case DRAW_RHOMBUS:
		 	    pOut->CreateDrawToolBar();
			    pOut->drawOnToolbar("images\\MenuItems\\Menu_Rhombus_Selected.jpg", ITM_RHOMBUS); 
			    pOut->PrintMessage("Action: Draw a Rhombus, Click 1");
				gfxInfo.FillClr = BLUE;
				gfxInfo.isFilled = true;
				pIn->GetPointClicked(P1.x, P1.y);
				pOut->DrawRhombus(P1, gfxInfo, false);
				
				break;

		case DRAW_ELLIPSE:
				pOut->CreateDrawToolBar();
				pOut->drawOnToolbar("images\\MenuItems\\Menu_Circ_Selected.jpg", ITM_CIRCLE);
			    pOut->PrintMessage("Action: Draw an Ellipse, Click 1");
				gfxInfo.FillClr = YELLOW;
				gfxInfo.isFilled = true;
				pIn->GetPointClicked(P1.x, P1.y);
				pOut->DrawEllipse(P1, gfxInfo, false);				
				break;

		case DRAW_TRI:
			    pOut->CreateDrawToolBar();
			    pOut->drawOnToolbar("images\\MenuItems\\Menu_Triangle_Selected.jpg", ITM_TRIANGLE); 
			    pOut->PrintMessage("Action: Draw a Triangle, Click 3");
				gfxInfo.FillClr = RED;
				gfxInfo.isFilled = true;
				pIn->GetPointClicked(P1.x, P1.y);
				pIn->GetPointClicked(P2.x, P2.y);
				pIn->GetPointClicked(P3.x, P3.y);
				pOut->DrawTriangle(P1, P2, P3, gfxInfo, false);				
				break;

		case CHNG_DRAW_CLR:
				pOut->PrintMessage("Action: Change Figure's drawing color , Click anywhere");
				pOut->CreateDrawToolBar();
				pOut->drawOnToolbar("images\\MenuItems\\Menu_draw_color_Selected.jpg", ITM_DRAW_COLOR);
				break;

		case CHNG_FILL_CLR:
				pOut->PrintMessage("Action: Change Figure's Fill color , Click anywhere");
				pOut->CreateDrawToolBar();
				pOut->drawOnToolbar("images\\MenuItems\\Menu_fill_color_Selected.jpg", ITM_FILL_COLOR);
				break;
			
		case STATUS:
				pOut->PrintMessage("Action: a click on the Status Bar, Click anywhere");
				break;
		case COPY:
				pOut->PrintMessage("Action: copy , Click anywhere");
				pOut->CreateDrawToolBar();
				pOut->drawOnToolbar("images\\MenuItems\\Menu_copy_Selected.jpg", ITM_COPY);
				break;
		case DEL:
				pOut->PrintMessage("Action: delete, Click anywhere");
				pOut->CreateDrawToolBar();
				pOut->drawOnToolbar("images\\MenuItems\\Menu_delete_Selected.jpg", ITM_DELETE);
				break;
		case SAVE:
				pOut->PrintMessage("Action: save, Click anywhere");
				pOut->CreateDrawToolBar();
				pOut->drawOnToolbar("images\\MenuItems\\Menu_save_Selected.jpg", ITM_SAVE);
				break;
 
		case DRAWING_AREA:
				pOut->PrintMessage("Action: a click on the Drawing Area, Click anywhere");
				break;

		case EMPTY:
				pOut->PrintMessage("Action: a click on empty area in the Design Tool Bar, Click anywhere");
				break;

		case TO_DRAW:
				pOut->PrintMessage("Action: Switch to Draw Mode, creating simualtion tool bar");
				pOut->CreateDrawToolBar();
				break;

		case TO_PLAY:
				pOut->PrintMessage("Action: Switch to Play Mode, creating Design tool bar");
				
				pOut->drawOnToolbar("images\\MenuItems\\Menu_game_Selected.jpg", ITM_GAME);

				pOut->CreatePlayToolBar();
				//TODO: Temporary Commenting until we build it
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


