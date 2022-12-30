#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

//This file contains some global constants and definitions to be used in the project.
enum ActionType //The actions supported (you can add more if needed)
{
	DRAW_RECT,				//Draw Rectangle
	DRAW_HEX,				//Draw Hexagon
	DRAW_SQUARE,			//Draw Square
	DRAW_CIRCLE,			//Draw Circle
	DRAW_TRI,				//Draw Triangle
	ADD_FIGURE,				//Switch interface to Shapes mode
	CHANGE_DRAWING_COLOR,	//Switch interface to Colors mode to change drawing color
	CHANGE_FILL_COLOR,		//Switch interface to Colors mode to change filling color
	COLOUR_BLACK,			//Choose Black color
	COLOUR_YELLOW,			//Choose Yellow color	
	COLOUR_ORANGE,			//Choose Orange color
	COLOUR_RED,				//Choose Red color
	COLOUR_GREEN,			//Choose Green color
	COLOUR_BLUE,			//Choose Blue color
	SELECT,					//Select a figure
	DELETE_FIGURE,			//Delete a figure 
	MOVE_FIGURE,			//Move a figure
	UNDO,					//Undo operation
	REDO,					//Redo the undone operation
	CLEAR_ALL,				//Clear all the drawing area
	START_RECORDING,		//Start Recording
	STOP_RECORDING,			//Stop Recording
	PLAY_RECORDING,			//Play Recording
	SAVE,					//Save Graph
	LOAD,					//Load Saved Graph
	EXIT,					//Exit Program
	PICK_BY_SHAPES,			//Play by picking specific shape
	PICK_BY_COLORS,			//Play by pickung specific color
	PICK_BY_BOTH,			//Play by picking specific shape and color
	TO_DRAW,				//Switch interface to Draw mode
	TO_PLAY,				//Switch interface to Play mode
	EMPTY,					//A click on empty place in the toolbar
	DRAWING_AREA,			//A click on the drawing area
	SOUND,					//A click on the sound btn
	STATUS					//A click on the status bar
};

struct Point	//To be used for figures points
{
	int x, y;
};

struct GfxInfo	//Graphical info of each figure (you may add more members)
{
	color DrawClr;	//Draw color of the figure
	color FillClr;	//Fill color of the figure
	bool isFilled;	//Figure Filled or not
	int BorderWdth;	//Width of figure borders

};

#endif