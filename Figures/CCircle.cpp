#include "CCircle.h"
#include "../ApplicationManager.h"

CCircle::CCircle(Point P1, Point P2, GfxInfo FigureGfxInfo) : CFigure(FigureGfxInfo)
{
	ID = (long)time(NULL) % 1000000;
	Center = P1;
	P = P2;
}
CCircle::CCircle(int id) : CFigure(id)
{
	ID = id;
	Selected = false;
}

void CCircle::Draw(Output* pOut) const
{
	// Call Output::DrawCircle to draw a circle on the screen
	pOut->DrawCircle(Center, P, FigGfxInfo, Selected);
}

void CCircle::Move(Point NewCenter)
{
	//Shifting P.x by the difference between the NewCenter and the OldCenter
	P.x += (NewCenter.x - Center.x);

	//Shifting P.y by the difference between the NewCenter and the OldCenter
	P.y += (NewCenter.y - Center.y);

	Center = NewCenter;
}

void CCircle::Save(ofstream& OutFile) const
{
	OutFile << "CIRCLE \t" << ID << '\t' << Center.x << '\t' << Center.y << '\t'
		<< P.x << '\t' << P.y << '\t' << ApplicationManager::ColorToString(FigGfxInfo.DrawClr) << '\t';

	if (FigGfxInfo.isFilled)
		OutFile << ApplicationManager::ColorToString(FigGfxInfo.FillClr) << '\n';
	else
		OutFile << "NO_FILL\n";
}

void CCircle::Load(ifstream& InFile)
{
	string Color;
	InFile >> Center.x >> Center.y >> P.x >> P.y >> Color;

	ChngDrawClr(ApplicationManager::StringToColor(Color));

	InFile >> Color;

	if (Color == "NO_FILL")
		FigGfxInfo.isFilled = false;
	else
		ChngFillClr(ApplicationManager::StringToColor(Color));
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

Point CCircle::GetCenter() const
{
	return Center;
}

void CCircle::PrintInfo(Output* pOut)
{
	string Info = "Circle \t";
	Info += "id: " + to_string(ID);
	Info += " center: (" + to_string(Center.x) + ", " + to_string(Center.y) + ") ";
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
