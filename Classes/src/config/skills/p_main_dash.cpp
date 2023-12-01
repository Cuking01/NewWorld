#pragma once

P_Main_Down_Flash_MS::P_Main_Down_Flash_MS(Scene*scene,People*people):
	Move_State(scene,people,1000)
{}

void P_Main_Down_Flash_MS::load()
{
	cnt=0;
	body=&people->armature.bone;
	people->cant_be_attack++;
	body->visible=false;
}

void P_Main_Down_Flash_MS::run()
{
	cnt++;
	if(cnt<=5)
	{
		
		//body->opacity=std::max(255-cnt*60,0);
	}
	else if(cnt<=7)
	{

	}
	else if(cnt==8)
	{
		people->displace({0,-1e5});
		people->v_y=0;
	}
	else if(cnt<=13)
	{
		
		//body->opacity=15+(cnt-9)*60;
	}

	if(cnt==13)
		people->set_ms(people->default_ms);
	

}

void P_Main_Down_Flash_MS::unload()
{
	body->visible=true;
	body->opacity=255;
	people->cant_be_attack--;
}

void P_Main_Down_Flash_MS::jump(f3)
{
	//do nothing.
}

P_Main_Dash_MS::P_Main_Dash_MS(Scene*scene,People*people):
	Move_State(scene,people,1000)
{}

void P_Main_Dash_MS::load()
{
	cnt=0;
	people->cant_be_attack++;
	body=&people->armature.bone;
	fuleg=&people->armature["front_upper_leg"].bone;
	flleg=&people->armature["front_upper_leg"]["front_lower_leg"].bone;
	buleg=&people->armature["back_upper_leg"].bone;
	blleg=&people->armature["back_upper_leg"]["back_lower_leg"].bone;
}

void P_Main_Dash_MS::run()
{
	cnt++;
	if(cnt<=16)
	{
		if(cnt<=4)
			body->rotation+=3;
		people->displace({40,0});
		people->v_y=0;
	}
	else if(cnt<=20)
	{
		body->rotation-=3;
	}
	if(cnt==22)
		people->set_ms(people->default_ms);
}

void P_Main_Dash_MS::unload()
{
	people->cant_be_attack--;
	body->rotation=0;
	fuleg->rotation=0;
	flleg->rotation=0;
	buleg->rotation=0;
	blleg->rotation=0;
}


P_Main_Dash::P_Main_Dash(Scene*scene,People*people,Weapon*weapon,const ::Config::Skill&con):
	Skill(scene,people,weapon,con),
	dash(scene,people),
	down_flash(scene,people),
	air_dash_cnt(0)
{
	auto refresh_cnt=[this]()
	{
		air_dash_cnt=0;
	};

	people->when_back_to_floor.add(scene->gen_id(),{refresh_cnt});
	people->when_jc.add(scene->gen_id(),{refresh_cnt});
}

void P_Main_Dash::use(bool down,bool up)
{
	if(down&&!people->on_floor())
		people->set_ms(&down_flash);
	else if(!down)
	{
		if(!people->on_floor())air_dash_cnt++;
		people->set_ms(&dash);
	}
}

bool P_Main_Dash::can_use(bool down,bool up)
{
	if(down)
	{
		return !people->on_floor();
	}
	else
	{
		return air_dash_cnt==0;
	}
}

void p_main_dash_init()
{
	Config::Skill skill
	{
		.name = L"",
		.creator = [](const Config::Skill& con,Scene* scene,People* people,Weapon* weapon)->Skill*
		{
			return new P_Main_Dash(scene,people,weapon,con);
		}
	};

	skill_table["p_main_dash"] = std::move(skill);
}
