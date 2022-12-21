#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;
	Point Corner2;
public:
	CRectangle(Point, Point, GfxInfo FigureGfxInfo, int id);
	CRectangle(int id);
	virtual void Draw(Output* pOut) const;
	virtual void Save(ofstream& OutFile, int ID) const;
	virtual bool IsInFigure(Point CheckPoint) const;
};

#endif