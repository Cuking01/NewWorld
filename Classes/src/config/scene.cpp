#pragma once

::Scene::Scene* create_scene(std::string key,s2 enmey_level)
{
	auto it=scene_table.find(std::move(key));
	if(it==scene_table.end())return nullptr;

	auto*p=new ::Scene::Scene;

	p->background_file=it->second.background_file;
	p->prospect_file=it->second.prospect_file;
	p->bgm_file=it->second.bgm_file;
	p->prospect_scale=it->second.prospect_scale;
	p->create_people(it->second.main,0);

	for(auto people_key:it->second.peoples)
		p->create_people(std::move(people_key),enmey_level);

	it->second.initor(p);

	return p;
}

namespace Scenes
{
	using namespace ::Scene;
	#include "scenes/test.cpp"
	#include "scenes/chapter10.cpp"
	#include "scenes/chapter11.cpp"
};

void scene_init()
{
	Scenes::test_init();
	Scenes::chapter10_init();
	Scenes::chapter11_init();
	//...
}

