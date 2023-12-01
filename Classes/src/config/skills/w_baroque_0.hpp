#pragma once

struct W_Baroque_0_MS :Move_State
{
	s2 j;
	s2 cnt;
	s2 next_flag;

	Bone* fuarm, * flarm,* buarm, * blarm, * fwp, * bwp, * body, * fuleg, * flleg, * buleg, * blleg, *h;

	W_Baroque_0_MS (Scene* scene, People* people);

	virtual void load();
	virtual void run();
	virtual void unload();

};

struct W_Baroque_0 :Skill
{
	W_Baroque_0_MS ms;
	W_Baroque_0(Scene* scene, People* people, Weapon* weapon, const ::Config::Skill& con);
	virtual void use(bool down,bool up);
};



void w_baroque_0_init();
