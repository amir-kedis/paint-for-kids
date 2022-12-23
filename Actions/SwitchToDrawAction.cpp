#include "SwitchToDrawAction.h"

SwitchToDrawAction::SwitchToDrawAction(ApplicationManager* pApp)
	:Action(pApp)
{
}

void SwitchToDrawAction::ReadActionParameters()
{
}

void SwitchToDrawAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Back to Draw Mode.......");

	UI.InterfaceMode = MODE_DRAW; // change the tool bar to play


	// load Draw Mode List From Saved File
	LoadAction loadFile(pManager);
	loadFile.LoadDrawModeList();

}
