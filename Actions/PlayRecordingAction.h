#pragma once
#include "Action.h"
#include "../ApplicationManager.h"
#include "SaveAction.h"
#include "LoadAction.h"

class PlayRecordingAction :
	public Action
{
	bool CanPlayRecord;
public:
	PlayRecordingAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};

