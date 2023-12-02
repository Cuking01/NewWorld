#pragma once

namespace P_Bear_Attack
{

MS::MS(Scene*scene,People*people):
	Move_State(scene,people,100)
{}

void MS::load()
{
	atk11=&people->armature["atk11"];
	atk12=&people->armature["atk12"];
	cnt=0;
	people->cant_be_attack++;
}

void MS::run()
{
	cnt++;
	people->armature.set_opacity(0);
	if(cnt<=30){
		(atk11->bone).visible=true;
		atk11->set_opacity(255);
		people->displace({6,20});
	}else if(cnt<=60){
		(atk11->bone).visible=false;
		(atk12->bone).visible=true;
		atk12->set_opacity(255);

		people->displace({7,-40});
		if(cnt==45||cnt==55)people->find_and_attack({ {50,-50},{200,50} }, Damage(people->ATK() * 2.5));
		if(cnt==50)scene->shake(30);
		if(cnt==50)people->cant_be_attack--;
	}else{
		people->set_ms(people->default_ms);
	}
}

void MS::unload()
{
	people->armature.set_opacity(255);
	(atk11->bone).visible=false;
	(atk12->bone).visible=false;
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
void p_bear_attack_init()
{
	Config::Skill skill
	{
		.name=L"",
		.creator = [](const Config::Skill& con,Scene* scene,People* people,Weapon* weapon)->Skill*
		{
			return new P_Bear_Attack::Sk(scene,people,weapon,con);
		}
	};

	skill_table["p_bear_attack"] = std::move(skill);
}

