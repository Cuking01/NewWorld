#pragma once

struct W_Sword_Strike_MS:Move_State
{
	s2 cnt;

	Bone* uarm, * larm, * wp, * body, * blarm, * fuleg, * flleg, * buleg, * blleg;
	//Bone* p1, * p2;
	W_Sword_Strike_MS(Scene* scene, People* people);

	virtual void load();
	virtual void run();
	virtual void unload();

};

struct W_Sword_Strike:Skill
{
	W_Sword_Strike_MS ms;
	W_Sword_Strike(Scene* scene, People* people, Weapon* weapon, const ::Config::Skill& con);
	virtual void use(bool down,bool up);
};

void w_sword_strike_init();