#pragma once

struct W_Crescent_H_MS :Move_State
{
	s2 cnt;

	Bone* uarm,*larm, * wp,*body,*blarm,*fuleg,*flleg,*buleg,*blleg;
	Bone* p1,*p2;
	W_Crescent_H_MS(Scene* scene, People* people);

	virtual void load();
	virtual void run();
	virtual void unload();

};

struct W_Crescent_H :Skill
{
	W_Crescent_H_MS ms;
	W_Crescent_H(Scene* scene, People* people, Weapon* weapon, const ::Config::Skill& con);
	virtual void use(bool down,bool up);
};



void w_crescent_h_init();
