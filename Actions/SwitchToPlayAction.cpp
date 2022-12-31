#include "SwitchToPlayAction.h"

SwitchToPlayAction::SwitchToPlayAction(ApplicationManager* pApp)
	:Action(pApp)
{
}

void SwitchToPlayAction::ReadActionParameters()
{
}

void SwitchToPlayAction::Execute(bool ReadActionParams)
{
	if (pManager->GetSoundStatus())
	{
		PlaySound(TEXT("sounds\\play-mode.wav"), NULL, SND_ASYNC);
	}

	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Play Mode started");

	UI.InterfaceMode = MODE_PLAY; // change the tool bar to play

	// reset the select
	pManager->UnselectAll(NULL);
	pManager->SetSelectedFig(NULL);

	// Save Current Draw Mode List
	SaveAction saveFile(pManager);
	saveFile.SaveDrawModeList();
}
