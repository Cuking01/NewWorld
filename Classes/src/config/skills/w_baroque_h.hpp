#pragma once
/*==================================ÉÏ¹´È­=============================================*/
struct W_Baroque_H_MS :Move_State
{
	s2 cnt;

	Bone* fuarm, * flarm, * buarm, * blarm, * fwp, * bwp, * body, * fuleg, * flleg, * buleg, * blleg, * h;

	W_Baroque_H_MS(Scene* scene, People* people);

	virtual void load();
	virtual void run();
	virtual void unload();

};

/*==================================ÏòÏÂ=============================================*/
struct W_Baroque_HS_MS :Move_State
{
	s2 cnt;

	Bone* fuarm, * flarm, * buarm, * blarm, * fwp, * bwp, * body, * fuleg, * flleg, * buleg, * blleg, * h;

	W_Baroque_HS_MS(Scene* scene, People* people);

	virtual void load();
	virtual void run();
	virtual void unload();

};


struct W_Baroque_H :Skill
{
	W_Baroque_H_MS ms;
	W_Baroque_HS_MS ms_hs;
	W_Baroque_H(Scene* scene, People* people, Weapon* weapon, const ::Config::Skill& con);
	virtual void use(bool down, bool up);
	virtual bool can_use(bool down, bool up);
};

void w_baroque_h_init();
