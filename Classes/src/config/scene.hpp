#pragma once

struct Scene
{
	std::string background_file;
	std::string prospect_file;
	std::string bgm_file;
	
	f3 prospect_scale;

	std::string main;
	std::vector<std::string> peoples;
	std::function<void(::Scene::Scene*scene)> initor;
};

inline std::map<std::string,Scene> scene_table;

void scene_init();

::Scene::Scene* create_scene(std::string key,s2 level);


namespace Scenes
{
	using namespace ::Scene;
	#include"scenes/test.hpp"
	#include"scenes/chapter10.hpp"
	#include"scenes/chapter11.hpp"
	#include"scenes/chapter20.hpp"
	#include"scenes/chapter21.hpp"
	#include"scenes/empty.hpp"
};
