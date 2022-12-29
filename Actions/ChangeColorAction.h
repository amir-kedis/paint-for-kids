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
	virtual void Execute();

	// Used For The Ability To Play The Action without further user input
	virtual void play();

	virtual void UndoAct();

	virtual void RedoAct();
};

