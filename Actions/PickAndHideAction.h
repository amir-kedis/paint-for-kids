#pragma once
#include "Action.h"
#include "..\Figures\CFigure.h"
class PickAndHideAction : public Action
{
private:
	string PickShape;
	string PickColor;
	char ShapeOrColor; // S for Shape , C for Color , B for Both
	int CorrectCnt;
	int IncorrectCnt;
public:
	PickAndHideAction(ApplicationManager* pApp, char ShapeOrColor);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();

	//Execute action
	virtual void Execute();

	// Prints score till that moment
	void PrintScore(string start = "") const;
};

