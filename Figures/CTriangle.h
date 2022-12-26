#ifndef CTRI_H
#define CTRI_H

#include "CFigure.h"

class CTriangle : public CFigure
{
private:
	Point Corner1;
	Point Corner2;
	Point Corner3;
public:
	CTriangle(Point, Point, Point, GfxInfo FigureGfxInfo);
	CTriangle(int id);
	virtual void Draw(Output* pOut) const;
	virtual void Move(Point NewCenter);
	virtual void Save(ofstream& OutFile) const;
	virtual void Load(ifstream& InFile);
	virtual string ClassString() const;
	virtual bool IsThisType(CFigure* fig) const;
	double CalcArea(Point V1, Point V2, Point V3) const;
	virtual bool IsInFigure(Point CheckPoint) const;
	virtual void PrintInfo(Output* pOut);	//print all figure info on the status bar
};

#endif