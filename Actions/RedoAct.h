#pragma once

#include "Action.h"

class RedoAct : public Action
{
public:
	RedoAct(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute(bool ReadActionParams = true);
};

