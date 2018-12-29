#include "ApplicationManager.h"


int main()
{

	ActionType ActType;
	//Create an object of ApplicationManager
	ApplicationManager AppManager;

	// play sound on starting the program
	PlaySound(TEXT("Sounds/smb3_enter_level.wav"), NULL, SND_ASYNC);

	do
	{		
		//Read user action
		ActType = AppManager.GetUserAction();

		//Exexute the action
		AppManager.ExecuteAction(ActType);

		//Update the interface
		if(ActType != EXIT)
			AppManager.UpdateInterface();

	}while(ActType != EXIT);
	

	
	return 0;
}

