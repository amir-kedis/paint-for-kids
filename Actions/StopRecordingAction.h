#pragma once
#include "Action.h"
#include "../ApplicationManager.h"
class StopRecordingAction :
	public Action
{
	bool CanStopRecord;
public:
	StopRecordingAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual bool Execute(bool ReadActionParams = true);
};

