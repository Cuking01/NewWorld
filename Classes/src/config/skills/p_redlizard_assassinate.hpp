#pragma once

namespace P_Redlizard_Assassinate
{

struct MS:Move_State
{
	Bone*uarm,*larm,*body;
	s2 cnt;
	Vector atk_pos;
	Dir atk_dir;
	MS(Scene*scene,People*people);
	virtual void load();
	virtual void run();
	virtual void unload();
};

struct Sk:Skill
{
	MS ms;
	s2 last_use;
	Sk(Scene*scene,People*people,Weapon*weapon,const ::Config::Skill&con);
	virtual void use(bool down,bool up);
	virtual bool can_use(bool down,bool up);
};

};

void p_redlizard_assassinate_init();

