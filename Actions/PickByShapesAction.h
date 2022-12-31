#pragma once
#include "Action.h"
class PickByShapesAction : public Action
{
private:
	string Pick;
	int CorrectCnt;
	int IncorrectCnt;
public:
	PickByShapesAction(ApplicationManager* pApp);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();

	//Execute action
	virtual void Execute(bool ReadActionParams = true);

	// Prints score till that moment
	void PrintScore(string start = "") const;
};

