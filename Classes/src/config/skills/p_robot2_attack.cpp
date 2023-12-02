#pragma once

namespace P_Robot2_Attack
{

MS::MS(Scene*scene,People*people):
	Move_State(scene,people,100)
{}

void MS::load()
{
	cnt=0;
	body=&people->armature.bone;
}

void MS::run()
{
	cnt++;
	if(cnt<=50){
		body->rotation++;
	}else if(cnt<=70){
		people->displace({20,0});
		if(cnt%5==0)people->find_and_attack({ {50,-50},{200,50} }, Damage(people->ATK() * 1.2));
	}else if(cnt<=80){
		people->displace({12,0});
		if(cnt%5==0)people->find_and_attack({ {50,-50},{200,50} }, Damage(people->ATK() * 0.8));
	}else{
		people->set_ms(people->default_ms);
	}
}

void MS::unload()
{
	body->rotation=0;
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
void p_robot2_attack_init()
{
	Config::Skill skill
	{
		.name=L"",
		.creator = [](const Config::Skill& con,Scene* scene,People* people,Weapon* weapon)->Skill*
		{
			return new P_Robot2_Attack::Sk(scene,people,weapon,con);
		}
	};

	skill_table["p_robot2_attack"] = std::move(skill);
}

