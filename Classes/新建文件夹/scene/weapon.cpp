#pragma once

Weapon::Weapon(const ::Config::Weapon&con,Scene*scene,People*people):
	scene(scene),
	people(people),
	name(con.name)
{
	int i=0;
	for(auto&p:skill)
		p=::Config::create_skill(con.skill[i++],scene,people,this);
}

Weapon::~Weapon()
{
	for(auto p:skill)
		delete p;
}

void Weapon::init(){}
void Weapon::load(){}
void Weapon::unload(){}

