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
	CTriangle(Point, Point, Point, GfxInfo FigureGfxInfo, int id);
	CTriangle(int id);
	virtual void Draw(Output* pOut) const;
	virtual void Save(ofstream& OutFile, int ID) const;
	virtual void Load(ifstream& InFile);
	double CalcArea(Point V1, Point V2, Point V3) const;
	virtual bool IsInFigure(Point CheckPoint) const;
};

#endif