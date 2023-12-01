#pragma once

Event::Event(Event_T t):type(t){}

namespace Events
{
	#include"event/move.cpp"
	#include"event/jump.cpp"
	#include"event/use_skill.cpp"
	#include"event/be_attack.cpp"
	#include"event/switch_weapon.cpp"

};

