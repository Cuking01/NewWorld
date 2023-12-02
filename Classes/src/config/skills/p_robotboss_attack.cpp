#pragma once

namespace P_Robotboss_Attack
{

MS::MS(Scene*scene,People*people):
	Move_State(scene,people,100)
{}

void MS::load()
{
	uarm=&people->armature["front_upper_arm"].bone;
	larm=&people->armature["front_upper_arm"]["front_lower_arm"].bone;
	body=&people->armature.bone;
	cnt=0;
	people->cant_be_attack++;
}

void MS::run()
{
	cnt++;
	
	if (cnt < 70)
	{
		uarm->rotation = -40;
		people->displace({ 21,0});
		if(cnt&1)people->find_and_attack({ {50,-50},{200,50} }, Damage(people->ATK() * 1.5));
	}
	
	
	if (cnt == 70)
	{
		people->cant_be_attack--;
		people->set_ms(people->default_ms);
	}
}

void MS::unload()
{
	body->rotation=0;
	uarm->rotation=0;
	larm->rotation=0;
}

Sk::Sk(Scene*scene,People*people,Weapon*weapon,const ::Config::Skill&con):
	Skill(scene,people,weapon,con),
	ms(scene,people),
	last_use(-(s2)(scene->rnd()%500))
{}


void Sk::use(bool down,bool up)
{
	last_use=scene->time;
	people->set_ms(&ms);
}

bool Sk::can_use(bool down,bool up)
{
	return people->on_floor()&&scene->time-last_use>=500;
}

};

void p_robotboss_attack_init()
{
	Config::Skill skill
	{
		.name=L"",
		.creator = [](const Config::Skill& con,Scene* scene,People* people,Weapon* weapon)->Skill*
		{
			return new P_Robotboss_Attack::Sk(scene,people,weapon,con);
		}
	};

	skill_table["p_robotboss_attack"] = std::move(skill);
}

