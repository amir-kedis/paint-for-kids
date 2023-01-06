#pragma once
#include "Action.h"
#include "../ApplicationManager.h"
#include "../Figures/CFigure.h"


class SelectFigureAction :
	public Action
{
	Point SelectPoint;
	bool IsRecorded;        //Boolean to check if the Action was recorded or not
public:
	SelectFigureAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual bool Execute(bool ReadActionParams = true);

	// Used to take user pick for playing
	CFigure* SelectForPlay();

	//Check if the Action was recorded or not
	virtual bool IsActionRecorded();
};

