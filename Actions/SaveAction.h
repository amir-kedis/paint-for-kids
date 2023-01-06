#pragma once
#include "Action.h"
class SaveAction : public Action
{
private:
	string FileName;
public:
	SaveAction(ApplicationManager*);

	virtual void ReadActionParameters();
	virtual bool Execute(bool ReadActionParams = true);

	/////////////////////////////////////////////
	/// Switching Between Modes Related Function
	/////////////////////////////////////////////
	void SaveDrawModeList();
};

