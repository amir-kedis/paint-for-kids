#pragma once
#include "Action.h"
#include "../ApplicationManager.h"
class ExitAction :
	public Action
{
public:
	ExitAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual bool Execute(bool ReadActionParams = true);
};

