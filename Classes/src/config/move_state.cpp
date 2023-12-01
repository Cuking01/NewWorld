#pragma once

::Scene::Move_State*create_ms(std::string key,::Scene::Scene*scene,::Scene::People*people)
{
	auto it=ms_table.find(key);
	if(it!=ms_table.end())
		return it->second.creator(scene,people);
	return nullptr;
}

namespace Move_States
{
	using ::Scene::Scene;
	using ::Scene::People;
	using ::Scene::Move_State;
	using ::Scene::AI_MS;
	
	#include"move_states/target_default.cpp"
	#include"move_states/redlizard_default.cpp"
};


void ms_init()
{
	ms_table["general"]=
	{
		[](::Scene::Scene*scene,::Scene::People*people)->::Scene::Move_State*
		{
			return new ::Scene::Move_States::General(scene,people);
		}
	};

	ms_table["death"]=
	{
		[](::Scene::Scene*scene,::Scene::People*people)->::Scene::Move_State*
		{
			return new ::Scene::Move_States::Death(scene,people);
		}
	};

	ms_table["jumping"]=
	{
		[](::Scene::Scene*scene,::Scene::People*people)->::Scene::Move_State*
		{
			return new ::Scene::Move_States::Jumping(scene,people);
		}
	};

	ms_table["freeze"]=
	{
		[](::Scene::Scene*scene,::Scene::People*people)->::Scene::Move_State*
		{
			return new ::Scene::Move_States::Freeze(scene,people);
		}
	};

	Move_States::target_default_init();
	Move_States::redlizard_default_init();
}
