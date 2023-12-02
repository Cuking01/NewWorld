#pragma once


struct Robotboss_Default_MS:AI_MS
{
	s2 strategy;
	s2 scnt;
	Bone * uarm , * larm, * wp, * body, * blarm, * buarm, * fuleg, * flleg, * buleg, * blleg;
	Robotboss_Default_MS(Scene*scene,People*people);
	virtual void load();
	virtual void run();
	virtual void unload();

};
