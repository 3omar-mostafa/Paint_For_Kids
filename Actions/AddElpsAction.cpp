#include "AddElpsAction.h"
#include "..\Figures\CEllipse.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddElpsAction::AddElpsAction(ApplicationManager * pApp) :Action(pApp)
{}

void AddElpsAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Ellipse: Click at the center");
	//Read center and store in P
	pIn->GetPointClicked(P.x, P.y);

	ElpsGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	ElpsGfxInfo.DrawClr = pOut->getCrntDrawColor();
	ElpsGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddElpsAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a rhombus with the center from the user
	CEllipse *El = new CEllipse(P, ElpsGfxInfo);

	//Add the rhombus to the list of figures
	pManager->AddFigure(El);
}
