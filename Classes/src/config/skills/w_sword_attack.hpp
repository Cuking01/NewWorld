#pragma once

struct W_Sword_Attack_MS :Move_State
{
	s2 j;
	s2 cnt;
	s2 next_flag;

	Bone* uarm, * larm, * wp, * body, * blarm, * fuleg, * flleg, * buleg, * blleg;

	W_Sword_Attack_MS(Scene* scene, People* people);

	virtual void load();
	virtual void run();
	virtual void unload();

	virtual void use_skill(s2 id, bool down, bool up);

};

struct W_Sword_Attack_Air_MS :Move_State
{
	s2 j;
	s2 cnt;
	s2 next_flag;

	Bone* uarm, * larm, * wp, * body, * blarm, * fuleg, * flleg, * buleg, * blleg;

	W_Sword_Attack_Air_MS(Scene* scene, People* people);

	virtual void load();
	virtual void run();
	virtual void unload();

	virtual void use_skill(s2 id, bool down, bool up);

};


struct W_Sword_Attack :Skill
{
	W_Sword_Attack_MS ms;
	W_Sword_Attack_Air_MS ms_air;
	W_Sword_Attack(Scene* scene, People* people, Weapon* weapon, const ::Config::Skill& con);
	virtual void use(bool down, bool up);
	//virtual bool can_use(bool down, bool up);
};



void w_sword_attack_init();
