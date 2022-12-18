#include "CRectangle.h"

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}


void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}

bool CRectangle::IsInFigure(Point CheckPoint) const
{
	// Check if x between corners 
	// and if y between corners
	// to find which corner is furthest we use min max fuctions
	bool XIsInShape = (CheckPoint.x >= min(Corner1.x, Corner2.x) && CheckPoint.x <= max(Corner1.x, Corner2.x));
	bool YIsInShape = (CheckPoint.y >= min(Corner1.y, Corner2.y) && CheckPoint.y <= max(Corner1.y, Corner2.y));

	return (XIsInShape && YIsInShape);
}
