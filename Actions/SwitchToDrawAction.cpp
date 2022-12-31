#include "SwitchToDrawAction.h"

SwitchToDrawAction::SwitchToDrawAction(ApplicationManager* pApp)
	:Action(pApp)
{
}

void SwitchToDrawAction::ReadActionParameters()
{
}

bool SwitchToDrawAction::Execute(bool ReadActionParams)
{
	if (pManager->GetSoundStatus())
	{
		PlaySound(TEXT("sounds\\draw-mode.wav"), NULL, SND_ASYNC);
	}

	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Back to Draw Mode.......");

	UI.InterfaceMode = MODE_DRAW; // change the tool bar to play


	// load Draw Mode List From Saved File
	LoadAction loadFile(pManager);
	loadFile.LoadDrawModeList();

	return true; // By default every action should be deleted
}
