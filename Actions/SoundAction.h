#pragma once
#include "Action.h"
#include "../ApplicationManager.h"
class SoundAction :
	public Action
{
public:
	SoundAction(ApplicationManager* pApp);

	//Reads Circle parameters
	virtual void ReadActionParameters();

	//Add circle to the ApplicationManager
	virtual void Execute(bool ReadActionParams = true);
};

