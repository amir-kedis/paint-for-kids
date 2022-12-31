#pragma once
#include "Action.h"
class ChangeColorAction : public Action
{
private:
	char DrawOrFill;
	color Color;
	GfxInfo PreviousInfo;
	CFigure* SelectedFig;
public:
	ChangeColorAction(ApplicationManager* pApp, char DOF, color C);

	virtual void ReadActionParameters();

	//Change Color of the figure
	virtual void Execute(bool ReadActionParams = true);

	virtual void UndoAct();

	virtual void RedoAct();
};

