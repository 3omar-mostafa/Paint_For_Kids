#pragma once
#include "Action.h"
#include <vector>

class UndoRedoAction :public Action
{
	static int historyCount;
	int mode;
	static vector<string> undoList;
	static vector<string> redoList;
	static  string currentFileName , nextFileName ;

	void updateFileNamesAccordingTo(string) const;
public:
	enum MODES {MODE_UNDO , MODE_REDO};
	UndoRedoAction(ApplicationManager* , int);
	void readActionParameters() override;
	void execute() override;
	static void eraseRedoList();
	static void incrementUndoList();
	static bool isUndoAvailable();
	static bool isRedoAvailable();
	static string getNextFileName();
	static string getCurrentFileName();
};
