#include "ExitAction.h"

ExitAction::ExitAction(ApplicationManager* pApp)
	:Action(pApp)
{
}

void ExitAction::ReadActionParameters()
{
}

void ExitAction::Execute(bool ReadActionParams)
{
	// PLay sound if on
	if (pManager->GetSoundStatus())
	{
		PlaySound(TEXT("sounds\\exit.wav"), NULL, SND_ASYNC);
	}
	Sleep(1000);

	pManager->ClearAll();
}
