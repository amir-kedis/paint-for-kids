#pragma once
#include "Action.h"
class PickByColorsAction : public Action
{
private:
	string Pick;
	int CorrectCnt;
	int IncorrectCnt;
public:
	PickByColorsAction(ApplicationManager* pApp);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();

	//Execute action
	virtual void Execute();

	// Prints score till that moment
	void PrintScore(string start = "") const;
};
