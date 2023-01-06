#include "ExitAction.h"

ExitAction::ExitAction(ApplicationManager* pApp)
	:Action(pApp)
{
}

void ExitAction::ReadActionParameters()
{
}

bool ExitAction::Execute(bool ReadActionParams)
{
	// PLay sound if on
	if (pManager->GetSoundStatus())
	{
		PlaySound(TEXT("sounds\\exit.wav"), NULL, SND_ASYNC);
	}
	Sleep(1000);

	pManager->ClearAll();

	return true; // By default every action should be deleted
}
