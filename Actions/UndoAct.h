#ifndef UNDO_ACT_H
#define UNDO_ACT_H

#include "Action.h"

class UndoAct : public Action
{
public:
	UndoAct(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute(bool ReadActionParams = true);
};

#endif