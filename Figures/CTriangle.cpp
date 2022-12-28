#include "CTriangle.h"
#include "../ApplicationManager.h"

CTriangle::CTriangle(Point P1, Point P2, Point P3, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	ID = (long)time(NULL) % 1000000;
	Corner1 = P1;
	Corner2 = P2;
	Corner3 = P3;
}

CTriangle::CTriangle(int id) :CFigure(id)
{
	ID = id;
	Selected = false;
}

void CTriangle::Draw(Output* pOut) const
{
	//Call Output::DrawTriangle to draw a triangle on the screen	
	pOut->DrawTriangle(Corner1, Corner2, Corner3, FigGfxInfo, Selected);
}

void CTriangle::Move(Point NewCenter)
{
	//Get the OldCenter Coordinates of the Rectangle 
	double OldCenterX = (Corner1.x + Corner2.x + Corner3.x) / 3.0;
	double OldCenterY = (Corner1.y + Corner2.y + Corner3.y) / 3.0;

	//Shifting Corner1 by the difference between the NewCenter and the OldCenter
	Corner1.x += (NewCenter.x - OldCenterX);
	Corner1.y += (NewCenter.y - OldCenterY);

	//Shifting Corner2 by the difference between the NewCenter and the OldCenter
	Corner2.x += (NewCenter.x - OldCenterX);
	Corner2.y += (NewCenter.y - OldCenterY);

	//Shifting Corner3 by the difference between the NewCenter and the OldCenter
	Corner3.x += (NewCenter.x - OldCenterX);
	Corner3.y += (NewCenter.y - OldCenterY);
}

void CTriangle::Save(ofstream& OutFile) const
{
	OutFile << "TRIANG \t" << ID << '\t' << Corner1.x << '\t' << Corner1.y << '\t'
		<< Corner2.x << '\t' << Corner2.y << '\t' << Corner3.x << '\t' << Corner3.y << '\t'
		<< ApplicationManager::ColorToString(FigGfxInfo.DrawClr) << '\t';

	if (FigGfxInfo.isFilled)
		OutFile << ApplicationManager::ColorToString(FigGfxInfo.FillClr) << '\n';
	else
		OutFile << "NO_FILL\n";
}

void CTriangle::Load(ifstream& InFile)
{
	string Color;
	InFile >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y
		>> Corner3.x >> Corner3.y >> Color;

	ChngDrawClr(ApplicationManager::StringToColor(Color));

	InFile >> Color;

	if (Color == "NO_FILL")
		FigGfxInfo.isFilled = false;
	else
		ChngFillClr(ApplicationManager::StringToColor(Color));
}

string CTriangle::ClassString() const
{
	return "Triangle";
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

void CTriangle::PrintInfo(Output* pOut)
{
	string Info = "Triangle \t";
	Info += "id: " + to_string(ID);
	Info += " corners: (" + to_string(Corner1.x) + ", " + to_string(Corner1.y) + ") ";
	Info += " (" + to_string(Corner2.x) + ", " + to_string(Corner2.y) + ") ";
	Info += " (" + to_string(Corner3.x) + ", " + to_string(Corner3.y) + ") ";
	Info += " " + ApplicationManager::ColorToString(FigGfxInfo.DrawClr) + ' ';


	if (FigGfxInfo.isFilled)
	{
		Info += ApplicationManager::ColorToString(FigGfxInfo.FillClr) + ' ';
	}
	else
	{
		Info += "NO_FILL ";

	}

	pOut->PrintMessage(Info);
}


