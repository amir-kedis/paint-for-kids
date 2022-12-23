#pragma once
#include "Action.h"
class LoadAction : public Action
{
private:
	string FileName;
public:
	LoadAction(ApplicationManager*);

	virtual void ReadActionParameters();

	virtual void Execute();

	/////////////////////////////////////////////
	/// Switching Between Modes Related Function
	/////////////////////////////////////////////
	void LoadDrawModeList();
};

