#pragma once
struct W_Crescent_IE_MS :Move_State{
	s2 cnt,mx;
	std::set<People*> enemy_set;
	W_Crescent_IE_MS(Scene* scene, People* people);

	virtual void run();
};
struct W_Crescent_I_MS :Move_State{
	s2 cnt;
	Armature *atk21,*atk22,*atk23,*atk24,*atk25,*atk26,*atk27;
	W_Crescent_I_MS(Scene* scene, People* people);

	virtual void load();
	virtual void run();
	virtual void unload();
};

struct W_Crescent_I :Skill{
	W_Crescent_I_MS ms;
	W_Crescent_I(Scene* scene, People* people, Weapon* weapon, const ::Config::Skill& con);
	virtual void use(bool down,bool up);
	virtual bool can_use(bool down,bool up);
};

void w_crescent_i_init();