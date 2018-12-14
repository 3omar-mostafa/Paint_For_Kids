#include "AddRhomAction.h"
#include "..\Figures\CRhombus.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddRhomAction::AddRhomAction(ApplicationManager * pApp) :Action(pApp)
{}

void AddRhomAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->drawOnToolbar("images\\MenuItems\\Menu_Rhombus_Selected.jpg", ITM_RHOMBUS);

	pOut->PrintMessage("New Rhombus: Click at the center");
	//Read center and store in P
	pOut->getValidRhombusPoint(P);

	RhomGfxInfo.isFilled = pOut->isFilled();	//default is filled
	//get drawing, filling colors and pen width from the interface
	RhomGfxInfo.DrawClr = pOut->getCrntDrawColor();
	RhomGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddRhomAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a rhombus with the center from the user
	CRhombus *Rh = new CRhombus(P, RhomGfxInfo);

	//Add the rhombus to the list of figures
	pManager->AddFigure(Rh);
}
