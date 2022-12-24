#pragma once
#include "Action.h"
#include "../ApplicationManager.h"
class StartRecordingAction :
	public Action
{
public:
	StartRecordingAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};

