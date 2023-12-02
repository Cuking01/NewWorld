#pragma once

struct General:Move_State
{
	s3 move_duration;
	s3 idle_duration;
	s2 move_flag;
	s2 jump_skill_flag;
	s2 switch_weapon_flag;

	Bone&fuleg;
	Bone&buleg;
	Bone&flleg;
	Bone&blleg;
	Bone&fuarm;
	Bone&buarm;

	General(Scene*scene,People*people);

	virtual void load();
	virtual void run();
	virtual void unload();

	virtual void move(Dir dir);
	virtual void use_skill(s2 id,bool down,bool up);
	virtual void switch_weapon(s2 id);

};
