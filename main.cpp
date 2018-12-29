#include "ApplicationManager.h"


int main()
{

	ActionType ActType;
	//Create an object of ApplicationManager
	ApplicationManager AppManager;

	// play sound on starting the program
	PlaySound(TEXT("Sounds/smb3_enter_level.wav"), nullptr, SND_ASYNC);

	do
	{		
		//Read user action
		ActType = AppManager.getUserAction();

		//Execute the action
		AppManager.executeAction(ActType);

		//Update the interface
		if(ActType != EXIT)
			AppManager.updateInterface();

	}while(ActType != EXIT);
	

	
	return 0;
}

