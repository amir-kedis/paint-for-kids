#pragma once

#include "Action.h"

class RedoAct : public Action
{
private:
	bool IsRecorded;        //Boolean to check if the Action was recorded or not
public:
	RedoAct(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual bool Execute(bool ReadActionParams = true);

	//Check if the Action was recorded or not
	virtual bool IsActionRecorded();
};

