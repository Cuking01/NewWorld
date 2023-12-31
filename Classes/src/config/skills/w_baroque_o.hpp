#pragma once
/*==================================����ȭ=============================================*/
struct W_Baroque_O_MS :Move_State
{
	s2 cnt;

	Bone* fuarm, * flarm, * buarm, * blarm, * fwp, * bwp, * body, * fuleg,
		* flleg, * buleg, * blleg, * h, * light, * o1, * o2, * o3, * o4, * o5, * o6,
		* o7, * o8, * o9, * o10, * o11;

	W_Baroque_O_MS(Scene* scene, People* people);

	virtual void load();
	virtual void run();
	virtual void unload();

};

struct W_Baroque_O :Skill
{
	W_Baroque_O_MS ms;
	W_Baroque_O(Scene* scene, People* people, Weapon* weapon, const ::Config::Skill& con);
	virtual void use(bool down, bool up);
	virtual bool can_use(bool down, bool up);
};

void w_baroque_o_init();
