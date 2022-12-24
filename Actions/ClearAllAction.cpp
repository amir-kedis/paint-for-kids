#include "ClearAllAction.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

ClearAllAction::ClearAllAction(ApplicationManager* pApp) :Action(pApp)
{
}

void ClearAllAction::ReadActionParameters()
{
}

void ClearAllAction::Execute()
{
	//Call ClearAll function in ApplicationManager
	pManager->ClearAll();
}

void ClearAllAction::play()
{
	// Change The Tool Bar
	UI.InterfaceMode = MODE_DRAW;
	Execute();
}