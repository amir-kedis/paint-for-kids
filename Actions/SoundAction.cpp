#include "SoundAction.h"

SoundAction::SoundAction(ApplicationManager* pApp)
	:Action(pApp)
{
}

void SoundAction::ReadActionParameters()
{
}

void SoundAction::Execute(bool ReadActionParams)
{
	// prepare outputs to print msgs
	Output* pOut = pManager->GetOutput();

	if (pManager->GetSoundStatus())
	{
		pManager->SetSoundStatus(false);
		UI.IsSoundOn = false;
		pOut->PrintMessage("Sound Is OFF");
	}
	else {
		pManager->SetSoundStatus(true);
		UI.IsSoundOn = true;
		pOut->PrintMessage("Sound Is ON");
	}
}
