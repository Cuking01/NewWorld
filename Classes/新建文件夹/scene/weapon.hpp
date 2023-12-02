#pragma once

struct Weapon
{
	Scene*scene;
	People*people;
	std::wstring name;
	Skill*skill[weapon_skill_num];
	Weapon(const ::Config::Weapon&con,Scene*scene,People*people);
	virtual ~Weapon();
	virtual void init();
	virtual void load();
	virtual void unload();
};
