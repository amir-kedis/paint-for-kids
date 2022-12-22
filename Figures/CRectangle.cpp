#include "CRectangle.h"
#include "../ApplicationManager.h"

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo) : CFigure(FigureGfxInfo)
{
	ID = (long)time(NULL) % 1000000;
	Corner1 = P1;
	Corner2 = P2;
}

CRectangle::CRectangle(int id) : CFigure(id)
{
	ID = id;
	Selected = false;
}

void CRectangle::Draw(Output *pOut) const
{
	// Call Output::DrawRect to draw a rectangle on the screen
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}

void CRectangle::Save(ofstream &OutFile) const
{
	OutFile << "RECT   \t" << ID << '\t' << Corner1.x << '\t' << Corner1.y << '\t'
			<< Corner2.x << '\t' << Corner2.y << '\t' 
		<< ApplicationManager::ColorToString(FigGfxInfo.DrawClr) << '\t';

	if (FigGfxInfo.isFilled)
		OutFile << ApplicationManager::ColorToString(FigGfxInfo.FillClr) << '\n';
	else
		OutFile << "NO_FILL\n";
}

void CRectangle::Load(ifstream& InFile)
{
	string Color;
	InFile >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y >> Color;

	ChngDrawClr(ApplicationManager::StringToColor(Color));

	InFile >> Color;

	if (Color == "NO_FILL")
		FigGfxInfo.isFilled = false;
	else
		ChngFillClr(ApplicationManager::StringToColor(Color));
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
