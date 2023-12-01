#pragma once


struct Sword:Weapon
{
	Sword(const Config::Weapon& con, Scene* scene, People* people);
	virtual void load();
	virtual void unload();
};

void sword_init();