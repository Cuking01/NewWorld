#pragma once
struct W_Crescent_OE_MS :Move_State{
	s2 cnt;
	std::set<People*> enemy_set;
	W_Crescent_OE_MS(Scene* scene, People* people);

	virtual void run();
};

struct W_Crescent_OE2_MS :Move_State{
	s2 cnt,mx;
	std::set<People*> enemy_set;
	W_Crescent_OE2_MS(Scene* scene, People* people);

	virtual void run();
};

struct W_Crescent_O_MS :Move_State
{
	s2 cnt;

	Armature *o1,*o2,*o3,*o4,*o5,*o6,*o7,*o8,*o9;
	W_Crescent_O_MS(Scene* scene, People* people);

	virtual void load();
	virtual void run();
	virtual void unload();
};

struct W_Crescent_O :Skill
{
	W_Crescent_O_MS ms;
	W_Crescent_O(Scene* scene, People* people, Weapon* weapon, const ::Config::Skill& con);
	virtual void use(bool down,bool up);
	virtual bool can_use(bool down,bool up);
};

void w_crescent_o_init();