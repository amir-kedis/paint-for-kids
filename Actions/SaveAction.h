#pragma once
#include "Action.h"
class SaveAction : public Action
{
private:
	string FileName;
public:
	SaveAction(ApplicationManager*);

	virtual void ReadActionParameters();
	virtual void Execute();

	/////////////////////////////////////////////
	/// Switching Between Modes Related Function
	/////////////////////////////////////////////
	void SaveDrawModeList();
};

