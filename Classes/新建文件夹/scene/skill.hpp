#pragma once

struct Skill
{
	Scene*scene;
	People*people;
	Weapon*weapon;
	std::wstring name;
	Skill(Scene*scene,People*people,Weapon*weapon,const ::Config::Skill&con);
	virtual ~Skill()=default;
	virtual void init();
	virtual void use(bool down,bool up)=0;
	virtual bool can_use(bool down,bool up);
	virtual f3 get_interrupt_strength(bool down,bool up);
};
