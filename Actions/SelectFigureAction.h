#pragma once
#include "Action.h"
#include "../ApplicationManager.h"
#include "../Figures/CFigure.h"


class SelectFigureAction :
	public Action
{
	Point SelectPoint;
public:
	SelectFigureAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute(bool ReadActionParams = true);

	// Used For The Ability To Play The Action without further user input
	virtual void play();

	// Used to take user pick for playing
	CFigure* SelectForPlay();
};

