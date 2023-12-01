#pragma once

::Scene::Weapon* create_weapon(std::string key,::Scene::Scene*scene,::Scene::People*people)
{
	auto it=weapon_table.find(key);
	if(it!=weapon_table.end())
		return it->second.creator(it->second,scene,people);
	return nullptr;
}

namespace Weapons
{
	using ::Scene::Scene;
	using ::Scene::People;
	using ::Scene::Weapon;
	using ::Scene::Armature;
	
	#include "weapons/test.cpp"
	#include "weapons/baroque.cpp"
	#include "weapons/crescent.cpp"
	#include "weapons/sword.cpp"
};

void weapon_init()
{
	Weapons::test_init();
	Weapons::baroque_init();
	Weapons::crescent_init();
	Weapons::sword_init();
}
