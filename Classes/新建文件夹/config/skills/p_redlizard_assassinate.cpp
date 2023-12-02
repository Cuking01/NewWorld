#pragma once

namespace P_Redlizard_Assassinate
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
	if(cnt<=40)
	{
		uarm->rotation-=1;
		larm->rotation-=3.5;
		people->armature.set_opacity(255-cnt*3.15);
	}
	else if(cnt<=80)
	{
		people->armature.set_opacity(255-cnt*3.15);
	}
	if(cnt==80)
	{
		atk_dir=scene->main->dir;
		atk_pos=scene->main->pos;
		people->armature.set_opacity(0);
		body->rotation=120;
	}
	if(cnt==130)
	{
		people->pos=atk_pos;
		people->dir=atk_dir;
		people->displace({-300,70});
		people->armature.set_opacity(255);

		people->cant_be_attack--;
	}
	if(cnt>=130&&cnt<=140)
	{
		people->displace({10,5});
	}
	if(cnt==138)
	{
		people->find_and_attack({{50,-50},{200,50}},Damage(people->ATK()*2));
	}
	if(cnt==141)
	{
		people->set_ms(people->default_ms);
	}
}

void MS::unload()
{
	body->rotation=0;
	uarm->rotation=0;
	larm->rotation=0;
	people->armature.set_opacity(255);

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
	return people->on_floor()&&scene->time-last_use>=600-people->level*10;
}

};

void p_redlizard_assassinate_init()
{
	Config::Skill skill
	{
		.name=L"",
		.creator = [](const Config::Skill& con,Scene* scene,People* people,Weapon* weapon)->Skill*
		{
			return new P_Redlizard_Assassinate::Sk(scene,people,weapon,con);
		}
	};

	skill_table["p_redrizard_assassinate"] = std::move(skill);
}

