#pragma once


struct Crescent :Weapon
{
	Crescent(const Config::Weapon& con, Scene* scene, People* people);
	virtual void load();
	virtual void unload();
};

void crescent_init();