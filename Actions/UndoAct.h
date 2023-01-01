#ifndef UNDO_ACT_H
#define UNDO_ACT_H

#include "Action.h"

class UndoAct : public Action
{
	bool IsRecorded;        //Boolean to check if the Action was recorded or not
public:
	UndoAct(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual bool Execute(bool ReadActionParams = true);

	//Check if the Action was recorded or not
	virtual bool IsActionRecorded();
};

#endif