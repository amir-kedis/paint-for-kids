#pragma once
#include "Action.h"
#include "..\Figures\CFigure.h"
class PickByShapeAction : public Action
{
private:
	string Shape;
	int CorrectCnt;
	int IncorrectCnt;
public:
	PickByShapeAction(ApplicationManager* pApp);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();

	//Execute action
	virtual void Execute();

	// Prints score till that moment
	void PrintScore(string start = "") const;
};

