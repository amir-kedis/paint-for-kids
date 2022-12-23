#pragma once
#include "Action.h"
class ChangeColorAction : public Action
{
private:
	char DrawOrFill;
	color Color;
public:
	ChangeColorAction(ApplicationManager* pApp, char DOF, color C);

	virtual void ReadActionParameters();

	//Change Color of the figure
	virtual void Execute();
};

