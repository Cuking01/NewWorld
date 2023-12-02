#pragma once
/*==================================ÐÇÂä(Ð±ÏòÏÂ)=============================================*/
struct W_Baroque_U_MS :Move_State
{
	s2 cnt;

	Bone* fuarm, * flarm, * buarm, * blarm, * fwp, * bwp, * body, * fuleg,
		* flleg, * buleg, * blleg, * h, * u[5];

	W_Baroque_U_MS(Scene* scene, People* people);
	std::set<People*> s;
	virtual void load();
	virtual void run();
	virtual void unload();

};

struct W_Baroque_U :Skill
{
	W_Baroque_U_MS ms;
	W_Baroque_U(Scene* scene, People* people, Weapon* weapon, const ::Config::Skill& con);
	virtual void use(bool down, bool up);
	virtual bool can_use(bool down, bool up);
};

void w_baroque_u_init();
