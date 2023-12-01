#pragma once

struct W_Test_Attack_MS:Move_State
{
	s2 j;
	s2 cnt;
	s2 next_flag;   //预输入下一次普攻的标记。

	Bone*arm,*wp;

	W_Test_Attack_MS(Scene*scene,People*people);

	virtual void load();
	virtual void run();
	virtual void unload();

	virtual void use_skill(s2 id,bool down,bool up);

};

struct W_Test_Attack:Skill
{
	W_Test_Attack_MS ms;
	W_Test_Attack(Scene*scene,People*people,Weapon*weapon,const ::Config::Skill&con);
	virtual void use(bool down,bool up);
};



void w_test_attack_init();
