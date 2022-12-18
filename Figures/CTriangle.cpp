#include "CTriangle.h"

CTriangle::CTriangle(Point P1, Point P2, Point P3, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Corner3 = P3;
}

void CTriangle::Draw(Output* pOut) const
{
	//Call Output::DrawTriangle to draw a triangle on the screen	
	pOut->DrawTriangle(Corner1, Corner2, Corner3, FigGfxInfo, Selected);
}

double CTriangle::CalcArea(Point V1, Point V2, Point V3) const
{
	return abs((V1.x * (V2.y - V3.y) + V2.x * (V3.y - V1.y) + V3.x * (V1.y - V2.y)) / 2.0);
}

bool CTriangle::IsInFigure(Point CheckPoint) const
{
	/////////////
	// To Know if point is in triangle
	// we assume that the point is in triangle
	// then divide the shape into three diffrent triangles each having the point as ther vertics
	// if the total areas of the 3 traingles equlas the area of the orignal traingle
	// then point is outside
	/////////////

	double TriangleArea = CalcArea(Corner1, Corner2, Corner3);

	double SubTriangleArea1 = CalcArea(CheckPoint, Corner2, Corner3);
	double SubTriangleArea2 = CalcArea(Corner1, CheckPoint, Corner3);
	double SubTriangleArea3 = CalcArea(Corner1, Corner2, CheckPoint);

	return (TriangleArea == SubTriangleArea1 + SubTriangleArea2 + SubTriangleArea3);
}


