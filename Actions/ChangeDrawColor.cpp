#include "ChangeDrawColor.h"
#include "..\ApplicationManager.h"

#include "..\GUI\Input.h"
#include "..\GUI\Output.h"

ChangeDrawColor::ChangeDrawColor(ApplicationManager * pApp) : Action(pApp)
{}

void ChangeDrawColor::readActionParameters() {}

//Execute the action
void ChangeDrawColor::execute()
{
	Output* pOut = pManager->getOutput();
	Input* pIn = pManager->getInput();
	pOut->printMessage("Change Figure's Drawing Color, Click Anywhere");

	pOut->drawDrawingColorMenu();
	pIn->getPointClicked(P.x, P.y);

	color currentDrawColor, selectedColor;
	if (pManager->getSelectedFigure() != nullptr)
	{
		currentDrawColor = pManager->getSelectedFigure()->getDrawColor();
		selectedColor = pOut->selectDrawColor(P);
		pManager->getSelectedFigure()->changeDrawColor(selectedColor);

	}
	else 
	{
		currentDrawColor = UI.DrawColor;
		selectedColor = pOut->selectDrawColor(P);
	}

	if (selectedColor != currentDrawColor) {
		SaveAction save(pManager);
		save.saveForUndo();
	}
}
