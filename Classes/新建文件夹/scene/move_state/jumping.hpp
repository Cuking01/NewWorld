#pragma once

struct Jumping:Move_State
{
	s2 cnt;
	Jumping(Scene*scene,People*people);
	virtual void load();
	virtual void run();
	virtual void move(Dir dir);
	virtual void jump(f3 interrupt_strength);
	virtual void switch_weapon(s2 id);

};
