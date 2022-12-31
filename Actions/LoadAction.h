#pragma once
#include "Action.h"
class LoadAction : public Action
{
private:
	string FileName;
public:
	LoadAction(ApplicationManager*);

	virtual void ReadActionParameters();

	virtual bool Execute(bool ReadActionParams = true);

	/////////////////////////////////////////////
	/// Switching Between Modes Related Function
	/////////////////////////////////////////////
	void LoadDrawModeList();
};

