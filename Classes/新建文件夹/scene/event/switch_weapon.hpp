#pragma once

struct Switch_Weapon:Event
{
	s2 id;
	Switch_Weapon(s2 id);
	virtual void apply(People*people);
};
