#pragma once

enum class Event_T:u2
{
	Move,
	Jump,
	Use_Skill,
	Be_Attack,
	Switch_Weapon
};

struct Event
{
	Event_T type;
	Event(Event_T t);
	virtual void apply(People*people)=0;
};

namespace Events
{
	#include"event/move.hpp"
	#include"event/jump.hpp"
	#include"event/use_skill.hpp"
	#include"event/be_attack.hpp"
	#include"event/switch_weapon.hpp"

};
