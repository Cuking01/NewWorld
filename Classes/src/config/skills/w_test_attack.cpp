#pragma once

W_Test_Attack_MS::W_Test_Attack_MS(Scene*scene,People*people):
	Move_State(scene,people,100)
{}


void W_Test_Attack_MS::load()
{
	arm=&people->armature["front_upper_arm"].bone;
	wp=&people->armature["front_upper_arm"]["test"].bone;

	people->v_y=0;
	j=0;
	cnt=0;
	next_flag=0;
	arm->rotation=0;
	wp->rotation=75;
	wp->scale={1,-1};
}

void W_Test_Attack_MS::run()
{
	cnt++;

	//一段攻击
	auto j1=[this]()
	{
		if(cnt<=10)
			arm->rotation-=12;

		if(cnt==8)
		{
			people->find_and_attack({{50,-100},{150,100}},Damage(people->ATK()*1.0),200,{300,0},0,100);
		}

		if(cnt==40)
		{
			if(next_flag)
				j=1,cnt=0,next_flag=0,people->v_y=0,wp->scale={1,1};
			else
				people->set_ms(people->default_ms);
		}
	};

	auto j2=[this]()
	{
		if(cnt<=10)
			arm->rotation+=12;

		if(cnt==8)
		{
			people->find_and_attack({{50,-100},{150,100}},Damage(people->ATK()*1.2),200,{300,0},0,100);
		}

		if(cnt==40)
		{
			if(next_flag)
				j=2,cnt=0,next_flag=0,people->v_y=0;
			else
				people->set_ms(people->default_ms);
		}
	};

	auto j3=[this]()
	{
		if(cnt<=10)
		{
			arm->rotation-=9;
			wp->rotation+=6;
		}

		if(cnt==8)
		{
			people->find_and_attack({{50,-100},{200,100}},Damage(people->ATK()*1.5),200,{300,0},0,100);
		}

		if(cnt==40)
		{
			people->set_ms(people->default_ms);
		}
	};

	if(j==0)j1();
	else if(j==1)j2();
	else j3();
}

void W_Test_Attack_MS::unload()
{
	arm->rotation=0;
	wp->rotation=0;
	wp->scale={1,1};
}

void W_Test_Attack_MS::use_skill(s2 id,bool down,bool up)
{
	//这里的id是全技能编号，人物技能从0到people_skill_num-1，武器技能编号从people_skill_num到people_skill_num+weapon_skill_num-1
	//所以people_skill_num+0就是第一个技能，默认为普通攻击。
	if(id==people_skill_num+0)
	{
		if(j==0)
		{
			next_flag=1;

		}
		else if(j==1)
		{
			next_flag=1;
		}
	}
	else Move_State::use_skill(id,down,up);
}


W_Test_Attack::W_Test_Attack(Scene*scene,People*people,Weapon*weapon,const ::Config::Skill&con):
	Skill(scene,people,weapon,con),
	ms(scene,people)
{}

void W_Test_Attack::use(bool down,bool up)
{
	people->set_ms(&ms);
}

void w_test_attack_init()
{
	Config::Skill skill
	{
		.name=L"",
		.creator=[](const Config::Skill&con,Scene*scene,People*people,Weapon*weapon)->Skill*
		{
			return new W_Test_Attack(scene,people,weapon,con);
		}
	};

	skill_table["w_test_attack"]=std::move(skill);
}
