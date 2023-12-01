#pragma once

::Scene::People* create_people(std::string key,::Scene::Scene*scene,s2 level)
{
	auto it=people_table.find(key);
	if(it==people_table.end())return nullptr;

	auto*p=new ::Scene::People(scene,it->second,level);
	return p;
}

namespace Peoples
{
	#include "peoples/effect.cpp"
	#include "peoples/main.cpp"
	#include "peoples/target.cpp"
	#include "peoples/redlizard.cpp"
	#include "peoples/bear.cpp"
	#include "peoples/priest.cpp"
	#include "peoples/robot2.cpp"
	#include "peoples/robotboss.cpp"
	#include "peoples/soldier_spear.cpp"
	#include "peoples/wildboar.cpp"
};


void people_init()
{
	Peoples::effect_init();
	Peoples::main_init();
	Peoples::target_init();
	Peoples::redlizard_init();
	Peoples::bear_init();
	Peoples::priest_init();
	Peoples::robot2_init();
	Peoples::robotboss_init();
	Peoples::soldier_spear_init();
	Peoples::wildboar_init();
	//..
}