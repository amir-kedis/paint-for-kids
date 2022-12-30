#include "ExitAction.h"

ExitAction::ExitAction(ApplicationManager* pApp)
	:Action(pApp)
{
}

void ExitAction::ReadActionParameters()
{
}

void ExitAction::Execute()
{
	// PLay sound if on
	if (pManager->GetSoundStatus())
	{
		PlaySound(TEXT("sounds\\exit.wav"), NULL, SND_ASYNC);
	}

	pManager->ClearAll();
}
