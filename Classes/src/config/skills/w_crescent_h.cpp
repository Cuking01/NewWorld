#pragma once

W_Crescent_H_MS::W_Crescent_H_MS(Scene*scene,People*people):
	Move_State(scene, people, 100)
{}

void W_Crescent_H_MS::load()
{
	cnt=0;
	uarm = &people->armature["front_upper_arm"].bone;
	larm = &people->armature["front_upper_arm"]["front_lower_arm"].bone;
	wp = &people->armature["front_upper_arm"]["front_lower_arm"]["crescent"].bone;
	body =&people->armature.bone;
	blarm =&people->armature["back_upper_arm"].bone;
	fuleg=&people->armature["front_upper_leg"].bone;
	flleg=&people->armature["front_upper_leg"]["front_lower_leg"].bone;
	buleg=&people->armature["back_upper_leg"].bone;
	blleg=&people->armature["back_upper_leg"]["back_lower_leg"].bone;
	p1=&people->armature["front_upper_arm"]["front_lower_arm"]["crescent"]["1"].bone;
	p2=&people->armature["front_upper_arm"]["front_lower_arm"]["crescent"]["2"].bone;
}

void W_Crescent_H_MS::run()
{
	cnt++;
	if(cnt<=6)
	{
		uarm->rotation+=5;
		p1->rotation-=5;
		p2->rotation-=5;
	}
	if(cnt==10)
	{
		p1->visible=true;
	}
	if(cnt==15)
	{
		people->find_and_attack({{10,-100},{500,100}},Damage(people->ATK()*3));
		people->displace({500,0});
		p1->visible=false;
		p2->visible=true;
	}
	if(cnt==18)
	{
		p2->visible=false;
		p1->visible=true;
	}

	if(cnt==23)
	{
		p1->visible=false;
	}
	if(cnt==40)
		people->set_ms(people->default_ms);
}

void W_Crescent_H_MS::unload()
{
	uarm->rotation = 0;
	larm->rotation = 0;
	wp->rotation = 0;
	wp->scale = { 1,1 };
	body->rotation = 0;
	blarm->rotation = 0;
	fuleg->rotation =0;
	flleg->rotation =0;
	buleg->rotation =0;
	blleg->rotation =0;
	p2->visible=false;
	p1->visible=false;
	p1->rotation=0;
	p2->rotation=0;
}

W_Crescent_H::W_Crescent_H(Scene* scene, People* people, Weapon* weapon, const ::Config::Skill& con):
	Skill(scene, people, weapon, con),
	ms(scene, people)
{}

void W_Crescent_H::use(bool down,bool up)
{
	people->set_ms(&ms);
}

void w_crescent_h_init()
{
	Config::Skill skill
	{
		.name = L"",
		.creator = [](const Config::Skill& con,Scene* scene,People* people,Weapon* weapon)->Skill*
		{
			return new W_Crescent_H(scene,people,weapon,con);
		}
	};

	skill_table["w_crescent_h"] = std::move(skill);
}


