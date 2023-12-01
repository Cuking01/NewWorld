#pragma once

struct Death:Move_State
{
	Death(Scene*scene,People*people);
	s2 cnt;
	double box_dy;
	virtual void load();
	virtual void run();
	virtual void move(Dir dir);
	virtual void jump(f3 interrupt_strength);
	virtual void use_skill(s2 id,bool down,bool up);
	virtual void be_attack(const Damage&,f3,Vector,s2,s2);
	virtual void switch_weapon(s2);
};
