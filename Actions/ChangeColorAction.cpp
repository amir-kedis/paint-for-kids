#include "ChangeColorAction.h"
#include "../ApplicationManager.h"

ChangeColorAction::ChangeColorAction(ApplicationManager* pApp, char DOF, color C) : Action(pApp)
{
	pManager = pApp;
	DrawOrFill = DOF;
	Color = C;
}

void ChangeColorAction::ReadActionParameters()
{

}

//Change Color of the figure
void ChangeColorAction::Execute()
{
	if (pManager->GetSelectedFig() == NULL)
	{
		pManager->GetOutput()->PrintMessage("You Must Select A Figure First");
	}
	else
	{
		if (DrawOrFill == 'D')
		{
			pManager->GetSelectedFig()->ChngDrawClr(Color);
			UI.DrawColor = Color;
		}
		else if (DrawOrFill == 'F')
		{
			pManager->GetSelectedFig()->ChngFillClr(Color);
			UI.IsFilled = true;
			UI.FillColor = Color;
		}
	}
}

void ChangeColorAction::play()
{
	// Change The Tool Bar
	UI.InterfaceMode = MODE_COLORS;

	Execute();
}
