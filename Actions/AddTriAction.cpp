#include "AddTriAction.h"
#include "..\Figures\CTriangle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddTriAction::AddTriAction(ApplicationManager * pApp) :Action(pApp)
{}

void AddTriAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->drawOnToolbar("images\\MenuItems\\Menu_Triangle_Selected.jpg", ITM_TRIANGLE);
	if (pManager->getSoundState())
		PlaySound(TEXT("Sounds/Triangle.wav"), NULL, SND_ASYNC);
	pOut->PrintMessage("New Triangle: Click at the first point");

	//Read 1st point and store in P1
	pOut->getValidPoint(P1);

	pOut->PrintMessage("New Triangle: Click at the second point");
	//Read 2nd point and store in P2
	pOut->getValidPoint(P2);

	pOut->PrintMessage("New Triangle: Click at the third point");
	//Read 3rd point and store in P3
	pOut->getValidPoint(P3);

	TriGfxInfo.isFilled = pOut->isFilled();	//default is filled
	//get drawing, filling colors and pen width from the interface
	TriGfxInfo.DrawClr = pOut->getCrntDrawColor();
	TriGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddTriAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a triangle with three points from the user
	CTriangle *T = new CTriangle(P1, P2, P3, TriGfxInfo);

	//Add the triangle to the list of figures
	pManager->AddFigure(T);
}
