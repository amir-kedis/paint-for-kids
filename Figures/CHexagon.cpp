#include "CHexagon.h"
#include "../ApplicationManager.h"

CHexagon::CHexagon(Point P, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo), radius(80)
{
	ID = (long)time(NULL) % 1000000;
	Center = P;
}

CHexagon::CHexagon(int id) :CFigure(id), radius(80)
{
	ID = id;
	Selected = false;
}


void CHexagon::Draw(Output* pOut) const
{
	//Call Output::DrawHexagon to draw a hexagon on the screen	
	pOut->DrawHexagon(Center, FigGfxInfo, Selected);
}

void CHexagon::Move(Point NewCenter)
{
	Center = NewCenter;
}

void CHexagon::Save(ofstream& OutFile) const
{
	OutFile << "HEXAGON\t" << ID << '\t' << Center.x << '\t' << Center.y << '\t'
		<< ApplicationManager::ColorToString(FigGfxInfo.DrawClr) << '\t';

	if (FigGfxInfo.isFilled)
		OutFile << ApplicationManager::ColorToString(FigGfxInfo.FillClr) << '\n';
	else
		OutFile << "NO_FILL\n";
}

void CHexagon::Load(ifstream& InFile)
{
	string Color;
	InFile >> Center.x >> Center.y >> Color;

	ChngDrawClr(ApplicationManager::StringToColor(Color));

	InFile >> Color;

	if (Color == "NO_FILL")
		FigGfxInfo.isFilled = false;
	else
		ChngFillClr(ApplicationManager::StringToColor(Color));
}

string CHexagon::ClassString() const
{
	return "Hexagon";
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

Point CHexagon::GetCenter() const
{
	return Center;
}

void CHexagon::PrintInfo(Output* pOut)
{
	string Info = "Hexagon \t";
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
