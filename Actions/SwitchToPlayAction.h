#pragma once
#include "Action.h"
#include "../ApplicationManager.h"
class SwitchToPlayAction :
	public Action
{
public:
	SwitchToPlayAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};

