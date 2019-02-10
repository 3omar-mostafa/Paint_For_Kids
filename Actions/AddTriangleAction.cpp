#include "AddTriangleAction.h"
#include "..\Figures\CTriangle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\Input.h"
#include "..\GUI\Output.h"

AddTriangleAction::AddTriangleAction(ApplicationManager * pApp) :Action(pApp)
{}

void AddTriangleAction::readActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->getOutput();
	pOut->drawOnToolbar("images\\MenuItems\\Menu_Triangle_Selected.jpg", ITM_TRIANGLE);
	if (pManager->getSoundState())
		PlaySound(TEXT("Sounds/Triangle.wav"), nullptr, SND_ASYNC);
	pOut->printMessage("New Triangle: Click at the first point");

	//Read 1st point and store in p1
	pOut->getValidPoint(P1);

	pOut->printMessage("New Triangle: Click at the second point");
	//Read 2nd point and store in p2
	pOut->getValidPoint(P2);

	pOut->printMessage("New Triangle: Click at the third point");
	//Read 3rd point and store in P3
	pOut->getValidPoint(P3);

	TriGfxInfo.isFilled = pOut->isFilled();	//default is filled
	//get drawing, filling colors and pen width from the interface
	TriGfxInfo.drawColor = pOut->getCurrentDrawColor();
	TriGfxInfo.fillColor = pOut->getCurrentFillColor();
	TriGfxInfo.borderSize = pOut->getCurrentBorderSize();

	pOut->clearStatusBar();

}

//Execute the action
void AddTriangleAction::execute()
{
	//This action needs to read some parameters first
	readActionParameters();

	//Create a triangle with three points from the user
	CTriangle *T = new CTriangle(P1, P2, P3, TriGfxInfo);

	//Add the triangle to the list of figures
	pManager->addFigure(T);

	SaveAction save(pManager);
	save.saveForUndo();
}
