#include "ChangeBorderSize.h"
#include "..\ApplicationManager.h"

#include "..\GUI\Input.h"
#include "..\GUI\Output.h"


ChangeBorderSize::ChangeBorderSize(ApplicationManager* pApp) : Action(pApp)
{}

void ChangeBorderSize::readActionParameters() {}

//Execute the action
void ChangeBorderSize::execute()
{
	Output* pOut = pManager->getOutput();
	Input* pIn = pManager->getInput();
	pOut->printMessage("Change Figure's Border Width, Click Anywhere");

	pOut->drawBorderSizeMenu();
	pIn->getPointClicked(P.x, P.y);

	if (pManager->getSelectedFigure() != nullptr)
		pManager->getSelectedFigure()->changeBorderSize(pOut->selectBorderSize(P));
	else
		pOut->selectBorderSize(P);

}
