#pragma once
#include "Action.h"
#include "../ApplicationManager.h"
class PlayRecordingAction :
	public Action
{
	bool CanPlayRecord;
public:
	PlayRecordingAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};

