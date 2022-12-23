#include "ChangeColorAction.h"

ChangeColorAction::ChangeColorAction(ApplicationManager* pApp, char DOF, color C) : Action(pApp)
{
	DrawOrFill = DOF;
	Color = C;
}

void ReadActionParameters()
{

}

//Change Color of the figure
void Execute()
{

}