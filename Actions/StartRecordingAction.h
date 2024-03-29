#pragma once
#include "Action.h"
#include "../ApplicationManager.h"
class StartRecordingAction :
	public Action
{
	bool CanRecord;
public:
	StartRecordingAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual bool Execute(bool ReadActionParams = true);
};

