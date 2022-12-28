#pragma once
#include "Action.h"
#include "..\Figures\CFigure.h"
class PickByShapeOrColorAction : public Action
{
private:
	string Pick;
	char ShapeOrColor;
	int CorrectCnt;
	int IncorrectCnt;
public:
	PickByShapeOrColorAction(ApplicationManager* pApp, char ShapeOrColor);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();

	//Execute action
	virtual void Execute();

	// Prints score till that moment
	void PrintScore(string start = "") const;
};

