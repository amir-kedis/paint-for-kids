#pragma once
#include "Action.h"
#include "../ApplicationManager.h"
#include "LoadAction.h"

class SwitchToDrawAction :
	public Action
{
public:
	SwitchToDrawAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual bool Execute(bool ReadActionParams = true);
};

