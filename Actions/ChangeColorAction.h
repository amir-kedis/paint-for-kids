#pragma once
#include "Action.h"
class ChangeColorAction : public Action
{
private:
	char DrawOrFill;
	color Color;
	GfxInfo PreviousInfo;
	CFigure* SelectedFig;
	bool IsRecorded;        //Boolean to check if the Action was recorded or not
public:
	ChangeColorAction(ApplicationManager* pApp, char DOF, color C);

	virtual void ReadActionParameters();

	//Change Color of the figure
	virtual bool Execute(bool ReadActionParams = true);

	virtual void UndoAct();

	virtual void RedoAct();

	//Check if the Action was recorded or not
	virtual bool IsActionRecorded();
};

