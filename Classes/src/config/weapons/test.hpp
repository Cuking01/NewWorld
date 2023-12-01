#pragma once


struct Test:Weapon
{
	Test(const Config::Weapon&con,Scene*scene,People*people);
	virtual void load();
	virtual void unload();
};

void test_init();
