#pragma once

struct People
{
	std::wstring name;
	Attributes attributes;

	s2 阵营;
	bool fly=false;
	s2 freeze_protection_trigger_cnt=-1;
	
	::Scene::Bounding_Box box;
	::Scene::Armature armature;

	std::string skill[people_skill_num];
	std::string weapons[people_weapon_num];
	std::string default_ms;
	
	std::function<void(::Scene::People*people)> initor;
};

inline std::map<std::string,People> people_table;

void people_init();
::Scene::People* create_people(std::string key,::Scene::Scene*scene,s2 level);

namespace Peoples
{
	using Armature=::Scene::Armature;

	#include "peoples/effect.hpp"
	#include "peoples/main.hpp"
	#include "peoples/target.hpp"
	#include "peoples/redlizard.hpp"
	#include "peoples/bear.hpp"
	#include "peoples/priest.hpp"
	#include "peoples/robot2.hpp"
	#include "peoples/robotboss.hpp"
	#include "peoples/soldier_spear.hpp"
	#include "peoples/wildboar.hpp"
};

