#pragma once

struct Weapon
{
	std::wstring name;
	std::string skill[weapon_skill_num];
	::Scene::Armature armature;
	std::function<::Scene::Weapon*(const Weapon&con,::Scene::Scene*scene,::Scene::People*people)> creator;
};

inline std::map<std::string,Weapon> weapon_table;

void weapon_init();
::Scene::Weapon* create_weapon(std::string key,::Scene::Scene*scene,::Scene::People*people);

namespace Weapons
{
	using ::Scene::Scene;
	using ::Scene::People;
	using ::Scene::Weapon;
	using ::Scene::Armature;
	
	#include"weapons/test.hpp"
	#include"weapons/baroque.hpp"
	#include"weapons/crescent.hpp"
	#include"weapons/sword.hpp"
};


