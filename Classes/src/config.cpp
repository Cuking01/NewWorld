#pragma once

namespace Config
{
	#include "config/attribute.cpp"
	#include "config/attributes.cpp"
	#include "config/move_state.cpp"
	#include "config/skill.cpp"
	#include "config/weapon.cpp"
	#include "config/people.cpp"
	#include "config/scene.cpp"

	void init()
	{
		ms_init();
		skill_init();
		weapon_init();
		people_init();
		scene_init();
	}
};
