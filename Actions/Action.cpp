#include "Action.h"

void Action::UndoAct()
{
}

void Action::RedoAct()
{
}

bool Action::IsActionRecorded()
{
	return false;   //By Default
}

Action::~Action()
{
}