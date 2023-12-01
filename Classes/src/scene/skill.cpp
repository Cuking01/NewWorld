#pragma once

Skill::Skill(Scene*scene,People*people,Weapon*weapon,const ::Config::Skill&con):
	scene(scene),
	people(people),
	weapon(weapon),
	name(con.name)
{}

void Skill::init(){}
bool Skill::can_use(bool down,bool up){return true;}
f3 Skill::get_interrupt_strength(bool down,bool up){return 1;}
