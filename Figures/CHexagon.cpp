#include "CHexagon.h"

CHexagon::CHexagon(Point P, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo), radius(80)
{
	Center = P;
}


void CHexagon::Draw(Output* pOut) const
{
	//Call Output::DrawHexagon to draw a hexagon on the screen	
	pOut->DrawHexagon(Center, FigGfxInfo, Selected);
}

bool CHexagon::IsInFigure(Point CheckPoint) const
{
	//////////////////////////////////////////////////////////////////////////
	// For Details in this Method read this: 
	// http://www.playchilla.com/how-to-check-if-a-point-is-inside-a-hexagon
	////////////////////////////////////////////////////////////////////////////

	/// Provide Needed Lengthes
	double VertDist = radius / 2.0;
	double HoriDist = radius * cos(3.1415 / 6);

	/// Transform Point To 2nd quadrant to reduce calculation
	Point TransformedCheckPoint;								// transform Point To
	TransformedCheckPoint.x = abs(CheckPoint.x - Center.x);		// Second Quadrant
	TransformedCheckPoint.y = abs(CheckPoint.y - Center.y);

	/// Check if point is outside the box made in quad 2
	if (TransformedCheckPoint.x > HoriDist || TransformedCheckPoint.y > radius)
	{
		return false;
	}

	/// Calculated the dot product of the vector from vertix to point 
	/// and the vector normal to the inclined side
	/// if pointing in the same direction then inseide

	double checkCorner = 2 * VertDist * HoriDist - VertDist * TransformedCheckPoint.x - HoriDist * TransformedCheckPoint.y;

	return (checkCorner >= 0);
}
