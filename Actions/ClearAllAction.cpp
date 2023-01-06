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

bool ClearAllAction::Execute(bool ReadActionParams)
{
	//Call ClearAll function in ApplicationManager
	pManager->ClearAll();

	return true; // By default every action should be deleted
}