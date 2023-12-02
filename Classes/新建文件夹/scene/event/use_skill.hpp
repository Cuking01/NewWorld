#pragma once

struct Use_Skill:Event
{
	s2 id;
	bool down,up;
	s2 time;
	Use_Skill(s2 id,bool down,bool up,s2 time);
	virtual void apply(People*people);
};
