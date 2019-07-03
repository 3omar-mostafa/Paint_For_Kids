#include "AddRhombusAction.h"
#include "..\Figures\CRhombus.h"

#include "..\ApplicationManager.h"

#include "..\GUI\Input.h"
#include "..\GUI\Output.h"

AddRhombusAction::AddRhombusAction(ApplicationManager * pApp) :Action(pApp)
{}

void AddRhombusAction::readActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->getOutput();

	pOut->drawOnToolbar("images\\MenuItems\\Menu_Rhombus_Selected.jpg", ITM_RHOMBUS);
	if (pManager->getSoundState())
		PlaySound(TEXT("Sounds/En-au-rhombus.wav"), NULL, SND_ASYNC);
	pOut->printMessage("New Rhombus: Click at the center");

	//Read center and store in P
	pOut->getValidRhombusPoint(P);

	RhomGfxInfo.isFilled = pOut->isFilled();	//default is filled
	//get drawing, filling colors and pen width from the interface
	RhomGfxInfo.drawColor = Output::getCurrentDrawColor();
	RhomGfxInfo.fillColor = Output::getCurrentFillColor();
	RhomGfxInfo.borderSize = Output::getCurrentBorderSize();

	pOut->clearStatusBar();

}

//Execute the action
void AddRhombusAction::execute()
{
	//This action needs to read some parameters first
	readActionParameters();

	//Create a rhombus with the center from the user
	CRhombus *Rh = new CRhombus(P, RhomGfxInfo);

	//Add the rhombus to the list of figures
	pManager->addFigure(Rh);

	SaveAction save(pManager);
	save.saveForUndo();
}
