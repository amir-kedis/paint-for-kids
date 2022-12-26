#pragma once
#include "Action.h"
#include "..\Figures\CFigure.h"
class PickByShapeAction : public Action
{
private:
	CFigure *Shape;
	int CorrectCnt;
	int IncorrectCnt;
public:
	PickByShapeAction(ApplicationManager* pApp);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();

	//Execute action
	virtual void Execute();

	// checks if the figure is one needed
	bool IsShape(CFigure* UserPick) const;
};

