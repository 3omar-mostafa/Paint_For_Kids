#include "AddRhomAction.h"
#include "..\Figures\CRhombus.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

addRhombusAction::addRhombusAction(ApplicationManager * pApp) :Action(pApp)
{}

void addRhombusAction::readActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->getOutput();
	Input* pIn = pManager->getInput();
	pOut->drawOnToolbar("images\\MenuItems\\Menu_Rhombus_Selected.jpg", ITM_RHOMBUS);
	if (pManager->getSoundState())
		PlaySound(TEXT("Sounds/En-au-rhombus.wav"), NULL, SND_ASYNC);
	pOut->printMessage("New Rhombus: Click at the center");

	//Read center and store in P
	pOut->getValidRhombusPoint(P);

	RhomGfxInfo.isFilled = pOut->isFilled();	//default is filled
	//get drawing, filling colors and pen width from the interface
	RhomGfxInfo.drawColor = pOut->getCurrentDrawColor();
	RhomGfxInfo.fillColor = pOut->getCurrentFillColor();

	pOut->clearStatusBar();

}

//Execute the action
void addRhombusAction::execute()
{
	//This action needs to read some parameters first
	readActionParameters();

	//Create a rhombus with the center from the user
	cRhombus *Rh = new cRhombus(P, RhomGfxInfo);

	//Add the rhombus to the list of figures
	pManager->addFigure(Rh);
}
