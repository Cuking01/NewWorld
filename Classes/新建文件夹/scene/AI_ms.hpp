#pragma once

struct AI_MS:Move_State
{
	People*&main;      //主角指针的引用，等价于scene->main
	double attack_d;   //派生类通过修改此值控制run的行为.
	s2 move_flag;
	s2 idle_duration;
	s2 move_duration;

	AI_MS(Scene*scene,People*people);

	virtual void load();
	virtual void run();//派生类可以显式调用此函数来追击主角。
	virtual void unload();

	
	virtual void move(Dir dir);

};
