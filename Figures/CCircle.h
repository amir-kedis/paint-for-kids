#ifndef CCircle_H
#define CCircle_H

#include "CFigure.h"

class CCircle : public CFigure
{
private:
	Point Center;
	Point P;    //Any point on the circle
public:
	CCircle(Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual void Save(ofstream& OutFile, int ID) const;
};

#endif
