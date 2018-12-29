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
	pOut->drawOnToolbar("images\\MenuItems\\Menu_Circ_Selected.jpg", ITM_CIRCLE);
	if(pManager->getSoundState())
		PlaySound(TEXT("Sounds/ellipse--_gb_1.wav"), NULL, SND_ASYNC);
	pOut->PrintMessage("New Ellipse: Click at the center");

	//Read center and store in P
	pOut->getValidEllipsePoint(P);

	ElpsGfxInfo.isFilled = pOut->isFilled();	//default is filled
	//Get drawing, filling colors and pen width from the interface
	ElpsGfxInfo.DrawClr = pOut->getCrntDrawColor();
	ElpsGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddElpsAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create an Ellipse with the center from the user
	CEllipse *El = new CEllipse(P, ElpsGfxInfo);

	//Add the Ellipse to the list of figures
	pManager->AddFigure(El);
}
