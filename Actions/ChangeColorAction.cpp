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
bool ChangeColorAction::Execute(bool ReadActionParams)
{
	// TO allow excution without raeding params in case of play recording
	if (ReadActionParams)
	{
		//This action needs to read some parameters first
		ReadActionParameters();
	}
	else
	{
		UI.InterfaceMode = MODE_COLORS;
	}


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

	bool shouldBeDeleted = false; // this action shoudn't be deleted by default

	// add action to record and record list if recording list
	if (pManager->GetRecordingStatus())
	{
		pManager->AddActionToRecording(this);
	}
	pManager->AddToURActionList(this);

	return shouldBeDeleted; // By default every action should be deleted
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
