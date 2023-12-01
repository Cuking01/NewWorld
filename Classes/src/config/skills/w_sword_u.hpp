#pragma once

struct W_Sword_U_MS :Move_State {
	s2 cnt;

	Bone* uarm, * larm, * wp, * body, * blarm, * fuleg, * flleg, * buleg, * blleg;
	Bone* p1, * p2, * p3;
	W_Sword_U_MS(Scene* scene, People* people);

	virtual void load();
	virtual void run();
	virtual void unload();
};

struct W_Sword_UW_MS :Move_State {
	s2 cnt;

	Bone* uarm, * larm, * wp, * body, * blarm, * fuleg, * flleg, * buleg, * blleg;
	Bone* p1, * p2, * p3;
	W_Sword_UW_MS(Scene* scene, People* people);

	virtual void load();
	virtual void run();
	virtual void unload();
};


struct W_Sword_US_MS :Move_State {
	s2 cnt;

	Bone* uarm, * larm, * wp, * body, * blarm, * fuleg, * flleg, * buleg, * blleg;
	Bone* p1, * p2, * p3;
	W_Sword_US_MS(Scene* scene, People* people);

	virtual void load();
	virtual void run();
	virtual void unload();
};

struct W_Sword_U :Skill {
	W_Sword_U_MS ms;
	W_Sword_UW_MS ms_uw;
	W_Sword_US_MS ms_us;
	W_Sword_U(Scene* scene, People* people, Weapon* weapon, const ::Config::Skill& con);
	virtual void use(bool down, bool up);
	virtual bool can_use(bool down, bool up);
};

void w_sword_u_init();