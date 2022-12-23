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
	CCircle(int id);
	virtual void Draw(Output* pOut) const;
	virtual void Save(ofstream& OutFile) const;
	virtual void Load(ifstream& InFile);
	virtual bool IsInFigure(Point CheckPoint) const;
	virtual void PrintInfo(Output* pOut);	//print all figure info on the status bar
};

#endif
