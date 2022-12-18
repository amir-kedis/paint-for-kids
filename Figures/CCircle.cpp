#include "CCircle.h"

CCircle::CCircle(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = P1;
	P = P2;
}


void CCircle::Draw(Output* pOut) const
{
	//Call Output::DrawCircle to draw a circle on the screen	
	pOut->DrawCircle(Center, P, FigGfxInfo, Selected);
}

bool CCircle::IsInFigure(Point CheckPoint) const
{
	// radius is distance between center and point in parameter
	double radiusOfCircle = sqrt(pow(Center.x - P.x, 2) + pow(Center.y - P.y, 2));

	// distance between check point and center
	double CheckRaduis = sqrt(pow(Center.x - CheckPoint.x, 2) + pow(Center.y - CheckPoint.y, 2));

	// Point is in circle if dist from it to center is less than the raduis
	return CheckRaduis <= radiusOfCircle;
}
