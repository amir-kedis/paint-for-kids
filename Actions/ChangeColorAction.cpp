#include "ChangeColorAction.h"
#include "../ApplicationManager.h"

ChangeColorAction::ChangeColorAction(ApplicationManager* pApp, char DOF, color C) : Action(pApp)
{
	pManager = pApp;
	DrawOrFill = DOF;
	Color = C;
	SelectedFig = NULL;
}

void ChangeColorAction::ReadActionParameters()
{

}

//Change Color of the figure
void ChangeColorAction::Execute(bool ReadActionParams = true)
{
	SelectedFig = pManager->GetSelectedFig();

	if (SelectedFig == NULL)
	{
		pManager->GetOutput()->PrintMessage("You Must Select A Figure First");
	}
	else
	{
		if (DrawOrFill == 'D')
		{
			PreviousInfo = SelectedFig->GetFigInfo();
			SelectedFig->ChngDrawClr(Color);
			UI.DrawColor = Color;
		}
		else if (DrawOrFill == 'F')
		{
			PreviousInfo = SelectedFig->GetFigInfo();
			SelectedFig->ChngFillClr(Color);
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

void ChangeColorAction::UndoAct()
{
	if (SelectedFig == NULL)
	{
		pManager->GetOutput()->PrintMessage("You Can't Undo this action");
	}
	else
	{
		if (DrawOrFill == 'D')
		{
			SelectedFig->ChngDrawClr(PreviousInfo.DrawClr);
			UI.DrawColor = PreviousInfo.DrawClr;
		}
		else if (DrawOrFill == 'F')
		{
			if (PreviousInfo.isFilled)
			{
				SelectedFig->ChngFillClr(PreviousInfo.FillClr);
				UI.FillColor = PreviousInfo.FillClr;
			}
			else
			{
				SelectedFig->ChngFigFillCond(false);
				UI.IsFilled = false;
			}
		}
	}
}

void ChangeColorAction::RedoAct()
{
	if (SelectedFig == NULL) //Delete this cond and the statement below when you change addtoURList
	{
		pManager->GetOutput()->PrintMessage("You Can't Redo this action");
	}
	else
	{
		if (DrawOrFill == 'D')
		{
			SelectedFig->ChngDrawClr(Color);
			UI.DrawColor = Color;
		}
		else if (DrawOrFill == 'F')
		{
			SelectedFig->ChngFillClr(Color);
			UI.IsFilled = true;
			UI.FillColor = Color;
		}
	}
}
