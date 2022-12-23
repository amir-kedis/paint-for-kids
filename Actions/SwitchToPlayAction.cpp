#include "SwitchToPlayAction.h"

SwitchToPlayAction::SwitchToPlayAction(ApplicationManager* pApp)
	:Action(pApp)
{
}

void SwitchToPlayAction::ReadActionParameters()
{
}

void SwitchToPlayAction::Execute()
{
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
