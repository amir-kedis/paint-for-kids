#pragma once
#include "Action.h"
#include "..\Figures\CFigure.h"
class PickByShapeAction : public Action
{
private:
	string FileName;
	CFigure *Shape;
public:
	PickByShapeAction(ApplicationManager* pApp);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();

	//Execute action
	virtual void Execute();
};

