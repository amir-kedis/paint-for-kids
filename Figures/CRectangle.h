#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;
	Point Corner2;
public:
	CRectangle(Point, Point, GfxInfo FigureGfxInfo);
	CRectangle(int id);
	virtual void Draw(Output* pOut) const;
	virtual void Move(Point NewCenter);
	virtual void Save(ofstream& OutFile) const;
	virtual void Load(ifstream& InFile);
	virtual string ClassString() const;
	virtual bool IsInFigure(Point CheckPoint) const;
	virtual Point GetCenter() const;
	virtual void PrintInfo(Output* pOut);	//print all figure info on the status bar
};

#endif