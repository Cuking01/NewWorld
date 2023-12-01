#pragma once
struct W_Baroque_IE_MS :Move_State
{
	s2 cnt, mx;
	std::set<People*> enemy_set;
	W_Baroque_IE_MS(Scene* scene, People* people);

	virtual void run();
};
struct W_Baroque_I_MS :Move_State
{
	s2 cnt;
	Armature* e1, * e2, * e3, * e4, * e5, * e6;
	Bone* fuarm, * flarm, * buarm, * blarm, * fwp, * bwp, * body, * fuleg, * flleg, * buleg, * blleg, * h;

	W_Baroque_I_MS(Scene* scene, People* people);

	virtual void load();
	virtual void run();
	virtual void unload();

};

struct W_Baroque_I :Skill
{
	W_Baroque_I_MS ms;
	W_Baroque_I(Scene* scene, People* people, Weapon* weapon, const ::Config::Skill& con);
	virtual void use(bool down, bool up);
	virtual bool can_use(bool down, bool up);
};

void w_baroque_i_init();
