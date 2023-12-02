#pragma once

::Scene::Skill* create_skill(std::string key,::Scene::Scene*scene,::Scene::People*people,::Scene::Weapon*weapon)
{
	auto it=skill_table.find(key);
	if(it!=skill_table.end())
		return it->second.creator(it->second,scene,people,weapon);
	return nullptr;
}

namespace Skills
{
	using ::Scene::People;
	using ::Scene::Weapon;
	using ::Scene::Skill;
	using ::Scene::Move_State;
	using ::Scene::Scene;
	using ::Scene::Bone;
	using ::Scene::Damage;
	using ::Scene::Armature;
	using ::Scene::Dir;
	
	#include "skills/w_test_attack.cpp"
	#include "skills/w_crescent_attack.cpp"
	#include "skills/w_crescent_h.cpp"
	#include "skills/w_crescent_u.cpp"
	#include "skills/w_crescent_i.cpp"
	#include "skills/w_crescent_o.cpp"

	#include "skills/w_baroque_attack.cpp"
	#include "skills/w_baroque_h.cpp"
	#include "skills/w_baroque_u.cpp"
	#include "skills/w_baroque_i.cpp"
	#include "skills/w_baroque_o.cpp"

	#include "skills/w_sword_attack.cpp"
	#include "skills/w_sword_strike.cpp"
	#include "skills/w_sword_u.cpp"
	#include "skills/w_sword_i.cpp"

	#include"skills/p_main_dash.cpp"
	#include"skills/p_redlizard_assassinate.cpp"
	#include"skills/p_robotboss_attack.cpp"
	#include"skills/p_bear_attack.cpp"
	#include"skills/p_robot2_attack.cpp"
};

void skill_init()
{
	Skills::w_test_attack_init();
	Skills::w_crescent_attack_init();
	Skills::w_crescent_h_init();
	Skills::w_crescent_u_init();
	Skills::w_crescent_i_init();
	Skills::w_crescent_o_init();

	Skills::w_baroque_attack_init();
	Skills::w_baroque_h_init();
	Skills::w_baroque_u_init();
	Skills::w_baroque_i_init();
	Skills::w_baroque_o_init();

	Skills::w_sword_attack_init();
	Skills::w_sword_strike_init();
	Skills::w_sword_u_init();
	Skills::w_sword_i_init();

	Skills::p_main_dash_init();

	Skills::p_redlizard_assassinate_init();
	Skills::p_robotboss_attack_init();
	Skills::p_bear_attack_init();
	Skills::p_robot2_attack_init();
}
