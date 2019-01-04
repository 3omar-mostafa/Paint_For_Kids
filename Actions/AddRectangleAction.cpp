#include "AddRectangleAction.h"
#include "..\Figures\CRectangle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\Input.h"
#include "..\GUI\Output.h"

AddRectangleAction::AddRectangleAction(ApplicationManager * pApp) :Action(pApp)
{}

void AddRectangleAction::readActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->getOutput();
	pOut->drawOnToolbar("images\\MenuItems\\Menu_Rect_Selected.jpg", ITM_RECTANGLE);
	if (pManager->getSoundState())
		PlaySound(TEXT("Sounds/Rectangle.wav"), nullptr, SND_ASYNC);
	pOut->printMessage("New Rectangle: Click at first corner");

	//Read 1st corner and store in point p1
	pOut->getValidPoint(P1);

	pOut->printMessage("New Rectangle: Click at second corner");
	//Read 2nd corner and store in point p2
	pOut->getValidPoint(P2);

	RectGfxInfo.isFilled = pOut->isFilled();	//default is filled
	//get drawing, filling colors and pen width from the interface
	RectGfxInfo.drawColor = pOut->getCurrentDrawColor();
	RectGfxInfo.fillColor = pOut->getCurrentFillColor();

	pOut->clearStatusBar();

}

//Execute the action
void AddRectangleAction::execute()
{
	//This action needs to read some parameters first
	readActionParameters();

	//Create a rectangle with the parameters read from the user
	CRectangle *R = new CRectangle(P1, P2, RectGfxInfo);

	//Add the rectangle to the list of figures
	pManager->addFigure(R);
}
