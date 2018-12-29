#include "AddElpsAction.h"
#include "..\Figures\CEllipse.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

addEllipseAction::addEllipseAction(ApplicationManager * pApp) :Action(pApp)
{}

void addEllipseAction::readActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->getOutput();
	Input* pIn = pManager->getInput();
	pOut->drawOnToolbar("images\\MenuItems\\Menu_Circ_Selected.jpg", ITM_ELLIPSE);
	if(pManager->getSoundState())
		PlaySound(TEXT("Sounds/ellipse--_gb_1.wav"), NULL, SND_ASYNC);
	pOut->printMessage("New Ellipse: Click at the center");

	//Read center and store in P
	pOut->getValidEllipsePoint(P);

	ElpsGfxInfo.isFilled = pOut->isFilled();	//default is filled
	//Get drawing, filling colors and pen width from the interface
	ElpsGfxInfo.drawColor = pOut->getCurrentDrawColor();
	ElpsGfxInfo.fillColor = pOut->getCurrentFillColor();

	pOut->clearStatusBar();

}

//Execute the action
void addEllipseAction::execute()
{
	//This action needs to read some parameters first
	readActionParameters();

	//Create an Ellipse with the center from the user
	CEllipse *El = new CEllipse(P, ElpsGfxInfo);

	//Add the Ellipse to the list of figures
	pManager->addFigure(El);
}
