#pragma once
#include "Action.h"
#include "../ApplicationManager.h"


class SelectFigureAction :
	public Action
{
	Point SelectPoint;
	GfxInfo* SelectedFigureInformation;
public:
	SelectFigureAction(ApplicationManager* pApp, GfxInfo* SelectedFigureGfx);
	virtual void ReadActionParameters();
	virtual void Execute();
};

