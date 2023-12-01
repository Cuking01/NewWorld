#pragma once


struct Redlizard_Default_MS:AI_MS
{
	s2 strategy;
	s2 scnt;
	Redlizard_Default_MS(Scene*scene,People*people);
	virtual void load();
	virtual void run();
	virtual void unload();

};
