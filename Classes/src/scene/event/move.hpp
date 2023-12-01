#pragma once

struct Move:Event
{
	Dir dir;
	Move(Dir dir);
	virtual void apply(People*people);
};
