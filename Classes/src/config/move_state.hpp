#pragma once

struct Move_State
{
	std::function<::Scene::Move_State*(::Scene::Scene*scene,::Scene::People*people)> creator;
};

inline std::map<std::string,Move_State> ms_table;

void ms_init();
::Scene::Move_State*create_ms(std::string key,::Scene::Scene*scene,::Scene::People*people);

namespace Move_States
{
	using ::Scene::Scene;
	using ::Scene::People;
	using ::Scene::Move_State;
	using ::Scene::AI_MS;

	#include"move_states/target_default.hpp"
	#include"move_states/redlizard_default.hpp"
};
