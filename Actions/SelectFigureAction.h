#pragma once
#include "Action.h"
#include "../ApplicationManager.h"


class SelectFigureAction :
	public Action
{
	Point SelectPoint;
public:
	SelectFigureAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};

