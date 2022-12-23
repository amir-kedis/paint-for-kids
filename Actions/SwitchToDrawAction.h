#pragma once
#include "Action.h"
#include "../ApplicationManager.h"

class SwitchToDrawAction :
	public Action
{
public:
	SwitchToDrawAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};

