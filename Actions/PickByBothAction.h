#pragma once
#include "Action.h"
class PickByBothAction : public Action
{
private:
	string PickShape;
	string PickColor;
	int CorrectCnt;
	int IncorrectCnt;
public:
	PickByBothAction(ApplicationManager* pApp);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();

	//Execute action
	virtual void Execute(bool ReadActionParams = true);

	// Prints score till that moment
	void PrintScore(string start = "") const;
};

