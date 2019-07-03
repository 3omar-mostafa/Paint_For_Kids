#include "UndoRedoAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"
#include "LoadAction.h"

UndoRedoAction::UndoRedoAction (ApplicationManager * pApp , int mode) :Action(pApp)
{
	this->mode = mode;
}

void UndoRedoAction::readActionParameters()
{}

void UndoRedoAction::execute()
{
	Output* pOut = pManager->getOutput();
	LoadAction load(pManager);

	string filename;
	if (mode == MODE_UNDO) {

		if (undoList.empty()) {
			pOut->printMessage("No more available UNDOs");
			return;
		}

		filename = *(undoList.end() - 1);
		undoList.pop_back();
		redoList.emplace_back(currentFileName);

		updateFileNamesAccordingTo(filename);

	}else {

		if (redoList.empty()) {
			pOut->printMessage("No more available REDOs");
			return;
		}

		filename = *(redoList.end() - 1);
		redoList.pop_back();
		undoList.emplace_back(currentFileName);

		updateFileNamesAccordingTo(filename);
	}

	load.loadFromFile(filename);

	pOut->printMessage("Undo, Click anywhere");

	pOut->drawUndoRedoIcons(MODE_UNDO, !undoList.empty());
	pOut->drawUndoRedoIcons(MODE_REDO, !redoList.empty());
}

void UndoRedoAction::updateFileNamesAccordingTo(string filename) const
{
	currentFileName = filename;
	
	// update value of historyCount according to currentFileName
	sscanf_s(currentFileName.c_str(), "save\\history%d.sav", &historyCount);
	nextFileName = "save\\history" + to_string(++historyCount) + ".sav";
}

void UndoRedoAction::eraseRedoList()
{
	redoList.clear();
}

void UndoRedoAction::incrementUndoList()
{
	undoList.emplace_back(currentFileName);
	currentFileName = nextFileName;
	nextFileName = "save\\history" + to_string(++historyCount) + ".sav";
}

bool UndoRedoAction::isUndoAvailable()
{
	return !undoList.empty();
}

bool UndoRedoAction::isRedoAvailable()
{
	return !redoList.empty();
}

string UndoRedoAction::getNextFileName()
{
	return nextFileName;
}

string UndoRedoAction::getCurrentFileName()
{
	return currentFileName;
}

int UndoRedoAction::historyCount = 1;
string UndoRedoAction::currentFileName = "save\\history0.sav";
string UndoRedoAction::nextFileName = "save\\history1.sav";
vector<string> UndoRedoAction::undoList;
vector<string> UndoRedoAction::redoList;