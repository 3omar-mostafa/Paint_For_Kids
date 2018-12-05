#include "ApplicationManager.h"


int main()
{

	ActionType ActType;
	//Create an object of ApplicationManager
	ApplicationManager AppManager;

	do
	{		
		//Read user action
		ActType = AppManager.GetUserAction();

		//Exexute the action
		AppManager.ExecuteAction(ActType);

		//Update the interface
		AppManager.UpdateInterface();
		//TODO: bug fix, when drawing any shape then preee EXIT
		//the program cannot update the interface because window pointer is deleted (I assume so)

	}while(ActType != EXIT);
	

	
	return 0;
}

