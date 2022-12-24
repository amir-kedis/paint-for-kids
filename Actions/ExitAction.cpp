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
	pManager->ClearAll();
}
