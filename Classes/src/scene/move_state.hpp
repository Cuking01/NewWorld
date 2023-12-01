#pragma once

struct Move_State
{
	Scene*scene;
	People*people;
	f3 priority;

	Move_State(Scene*scene,People*people,f3 priority=100);
	virtual ~Move_State();

	virtual void init();
	virtual void load();
	virtual void run();
	virtual void unload();

	virtual void move(Dir dir);
	virtual void jump(f3 interrupt_strength=0);
	virtual void use_skill(s2 id,bool down,bool up);
	virtual void be_attack(const Damage&damage,f3 hit_intensity,Vector impact_dir,s2 impact_time,s2 freeze_time);
	virtual void switch_weapon(s2 id);
};

namespace Move_States
{

	#include"move_state/general.hpp"
	#include"move_state/freeze.hpp"
	#include"move_state/jumping.hpp"
	#include"move_state/death.hpp"
};


