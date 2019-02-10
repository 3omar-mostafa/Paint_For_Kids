#include "ChangeFillColor.h"
#include "..\ApplicationManager.h"

#include "..\GUI\Input.h"
#include "..\GUI\Output.h"

ChangeFillColor::ChangeFillColor(ApplicationManager * pApp) :Action(pApp)
{}

void ChangeFillColor::readActionParameters() {}

//Execute the action
void ChangeFillColor::execute()
{
	Output* pOut = pManager->getOutput();
	Input* pIn = pManager->getInput();
	pOut->printMessage("Change Figure's Fill Color, Click Anywhere");

	pOut->drawFillColorMenu();

	pIn->getPointClicked(P.x, P.y);

	color currentFillColor , selectedColor;
	if (pManager->getSelectedFigure() != nullptr) 
	{
		currentFillColor = pManager->getSelectedFigure()->getFillColor();
		selectedColor = pOut->selectFillColor(P);
		if (selectedColor != NOFILL)
			pManager->getSelectedFigure()->changeFillColor(selectedColor);
		else
			pManager->getSelectedFigure()->setFilled(false);
	}
	else
	{
		currentFillColor = UI.FillColor;
		selectedColor = pOut->selectFillColor(P);
	}

	if (selectedColor != currentFillColor) {
		SaveAction save(pManager);
		save.saveForUndo();
	}
}