#pragma once

struct W_Crescent_AE1_MS :Move_State
{
	s2 cnt,mx;
	std::set<People*> enemy_set;
	W_Crescent_AE1_MS(Scene* scene, People* people);

	virtual void run();
};
struct W_Crescent_Attack_MS :Move_State
{
	s2 j;
	s2 cnt;
	s2 next_flag;

	Armature *atk11,*atk12,*atk13,*atk14,*atk15,*atk16,
			*atk21,*atk22,*atk23,*atk24,*atk25,*atk26,*atk27,
			*atk31,*atk32,*atk33,*atk34,*atk35,*atk36;
	Bone *uarm,*larm,*wp,*body,*blarm,*fuleg,*flleg,*buleg,*blleg;

	W_Crescent_Attack_MS(Scene* scene, People* people);

	virtual void load();
	virtual void run();
	virtual void unload();

	virtual void use_skill(s2 id,bool down,bool up);

};

struct W_Crescent_Attack :Skill
{
	W_Crescent_Attack_MS ms;
	W_Crescent_Attack(Scene* scene, People* people, Weapon* weapon, const ::Config::Skill& con);
	virtual void use(bool down,bool up);
};



void w_crescent_attack_init();
