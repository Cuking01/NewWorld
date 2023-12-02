#pragma once

struct Skill
{
	std::wstring name;
	std::function<::Scene::Skill*(const Skill&con,::Scene::Scene*scene,::Scene::People*people,::Scene::Weapon*weapon)> creator;
};

std::map<std::string,Skill> skill_table;

void skill_init();
::Scene::Skill* create_skill(std::string key,::Scene::Scene*scene,::Scene::People*people,::Scene::Weapon*weapon);


namespace Skills
{
	using ::Scene::Scene;
	using ::Scene::People;
	using ::Scene::Weapon;
	using ::Scene::Skill;
	using ::Scene::Move_State;
	using ::Scene::Bone;
	using ::Scene::Damage;
	using ::Scene::Armature;
	using ::Scene::Dir;
	
	#include "skills/w_test_attack.hpp"
	#include "skills/w_crescent_attack.hpp"
	#include "skills/w_crescent_h.hpp"
	#include "skills/w_crescent_u.hpp"
	#include "skills/w_crescent_i.hpp"
	#include "skills/w_crescent_o.hpp"
	
	#include "skills/w_baroque_attack.hpp"
	#include "skills/w_baroque_h.hpp"
	#include "skills/w_baroque_u.hpp"
	#include "skills/w_baroque_i.hpp"
	#include "skills/w_baroque_o.hpp"

	#include "skills/w_sword_attack.hpp"
	#include "skills/w_sword_strike.hpp"
	#include "skills/w_sword_u.hpp"
	#include "skills/w_sword_i.hpp"

	#include"skills/p_main_dash.hpp"
	#include"skills/p_redlizard_assassinate.hpp"
	#include"skills/p_robotboss_attack.hpp"
	#include"skills/p_bear_attack.hpp"
	#include"skills/p_robot2_attack.hpp"
};
