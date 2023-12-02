#pragma once

struct W_Sword_I_E_MS :Move_State
{
	s2 cnt,mx;
	std::set<People*> enemy_set;
	W_Sword_I_E_MS(Scene* scene, People* people);

	virtual void run();
};


struct W_Sword_I_MS :Move_State
{
	s2 cnt;

	Bone* uarm, * larm, * wp, * body, * blarm, * buarm, * fuleg, * flleg, * buleg, * blleg;
	Bone* p0, * p1, * p2, * p3;
	W_Sword_I_MS(Scene* scene, People* people);

	virtual void load();
	virtual void run();
	virtual void unload();

};

struct W_Sword_I :Skill
{
	W_Sword_I_MS ms;
	W_Sword_I(Scene* scene, People* people, Weapon* weapon, const ::Config::Skill& con);
	virtual void use(bool down, bool up);
	virtual bool can_use(bool down, bool up);
};

void w_sword_i_init();