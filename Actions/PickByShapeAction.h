#pragma once
#include "Action.h"
class PickByShapeAction : public Action
{
private:
	string FileName;
public:
	PickByShapeAction(ApplicationManager* pApp);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();

	//Execute action
	virtual void Execute();
};

