#pragma once

struct P_Main_Down_Flash_MS:Move_State
{
	s2 cnt;
	Bone*body;
	P_Main_Down_Flash_MS(Scene*scene,People*people);

	virtual void load();
	virtual void run();
	virtual void unload();

	virtual void jump(f3);
};

struct P_Main_Dash_MS:Move_State
{
	s2 cnt;

	Bone*body,*fuleg,*flleg,*buleg,*blleg;

	P_Main_Dash_MS(Scene*scene,People*people);

	virtual void load();
	virtual void run();
	virtual void unload();
};

struct P_Main_Dash :Skill
{
	P_Main_Dash_MS dash;
	P_Main_Down_Flash_MS down_flash;
	s2 air_dash_cnt;
	P_Main_Dash(Scene* scene, People* people, Weapon* weapon, const ::Config::Skill& con);

	virtual void use(bool down, bool up);
	virtual bool can_use(bool down, bool up);

};

void p_main_dash_init();

