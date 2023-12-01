#pragma once


struct Baroque :Weapon
{
	Baroque(const Config::Weapon& con, Scene* scene, People* people);
	virtual void load();
	virtual void unload();
};

void baroque_init();



