#ifndef CHEX_H
#define CHEX_H

#include "CFigure.h"

class CHexagon : public CFigure
{
private:
	Point Center;
	const double radius;

public:
	CHexagon(Point, GfxInfo FigureGfxInfo);
	CHexagon(int id);
	virtual void Draw(Output* pOut) const;
	virtual void Move(Point NewCenter);
	virtual void Save(ofstream& OutFile) const;
	virtual void Load(ifstream& InFile);
	virtual bool IsInFigure(Point CheckPoint) const;
	virtual void PrintInfo(Output* pOut);	//print all figure info on the status bar
};

#endif
