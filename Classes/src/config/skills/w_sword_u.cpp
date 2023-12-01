#pragma once

W_Sword_U_MS::W_Sword_U_MS(Scene* scene, People* people) :
	Move_State(scene, people, 100)
{}

void W_Sword_U_MS::load()
{
	cnt = 0;
	uarm = &people->armature["front_upper_arm"].bone;
	larm = &people->armature["front_upper_arm"]["front_lower_arm"].bone;
	wp = &people->armature["front_upper_arm"]["front_lower_arm"]["sword"].bone;
	body = &people->armature.bone;
	blarm = &people->armature["back_upper_arm"].bone;
	fuleg = &people->armature["front_upper_leg"].bone;
	flleg = &people->armature["front_upper_leg"]["front_lower_leg"].bone;
	buleg = &people->armature["back_upper_leg"].bone;
	blleg = &people->armature["back_upper_leg"]["back_lower_leg"].bone;
	uarm->rotation = 20;
	larm->rotation = 15;
	wp->rotation = 10;
}

void W_Sword_U_MS::run()
{
	cnt++;

	if (cnt <= 10)
	{
		uarm->rotation -= 4;
		larm->rotation -= 3;
		wp->rotation -= 2;
	}
	if (cnt == 8)
	{
		people->find_and_attack({ {50,-100},{200,100} }, Damage(people->ATK() * 1.5), 200, { 500,1800 }, 25, 50);
	}
	
	if(cnt==20)
	{
		people->set_ms(people->default_ms);
	}
}

void W_Sword_U_MS::unload()
{
	uarm->rotation = 0;
	larm->rotation = 0;
	wp->rotation = 0;
	wp->scale = { 1,1 };
	body->rotation = 0;
	blarm->rotation = 0;
	fuleg->rotation = 0;
	flleg->rotation = 0;
	buleg->rotation = 0;
	blleg->rotation = 0;
	cnt = 0;
}

W_Sword_UW_MS::W_Sword_UW_MS(Scene* scene, People* people) :
	Move_State(scene, people, 100)
{}

void W_Sword_UW_MS::load()
{
	cnt = 0;
	uarm = &people->armature["front_upper_arm"].bone;
	larm = &people->armature["front_upper_arm"]["front_lower_arm"].bone;
	wp = &people->armature["front_upper_arm"]["front_lower_arm"]["sword"].bone;
	body = &people->armature.bone;
	blarm = &people->armature["back_upper_arm"].bone;
	fuleg = &people->armature["front_upper_leg"].bone;
	flleg = &people->armature["front_upper_leg"]["front_lower_leg"].bone;
	buleg = &people->armature["back_upper_leg"].bone;
	blleg = &people->armature["back_upper_leg"]["back_lower_leg"].bone;
}

void W_Sword_UW_MS::run()
{
	cnt++;


	if (cnt <= 10)
	{
		uarm->rotation -= 4;
		larm->rotation -= 3;
		wp->rotation -= 2;
	}
	if (cnt == 8)
	{
		people->find_and_attack({ {50,-100},{200,100} }, Damage(people->ATK() * 1.5), 200, { 500,1800 }, 25, 50);
	}
	if (cnt >= 8 && cnt < 20)
	{
		people->displace({10,30});
		people->v_y = 0;
	}
	if (cnt >= 20 && cnt < 30)
	{
		people->v_y = 0;
	}
	if(cnt==30)
	{
		people->set_ms(people->default_ms);
	}
}

void W_Sword_UW_MS::unload()
{
	uarm->rotation = 0;
	larm->rotation = 0;
	wp->rotation = 0;
	wp->scale = { 1,1 };
	body->rotation = 0;
	blarm->rotation = 0;
	fuleg->rotation = 0;
	flleg->rotation = 0;
	buleg->rotation = 0;
	blleg->rotation = 0;
	cnt = 0;
}

W_Sword_US_MS::W_Sword_US_MS(Scene* scene, People* people) :
	Move_State(scene, people, 100)
{}

void W_Sword_US_MS::load()
{
	cnt = 0;
	uarm = &people->armature["front_upper_arm"].bone;
	larm = &people->armature["front_upper_arm"]["front_lower_arm"].bone;
	wp = &people->armature["front_upper_arm"]["front_lower_arm"]["sword"].bone;
	body = &people->armature.bone;
	blarm = &people->armature["back_upper_arm"].bone;
	fuleg = &people->armature["front_upper_leg"].bone;
	flleg = &people->armature["front_upper_leg"]["front_lower_leg"].bone;
	buleg = &people->armature["back_upper_leg"].bone;
	blleg = &people->armature["back_upper_leg"]["back_lower_leg"].bone;
	uarm->rotation = -40;
	larm -> rotation = -30;
	wp->rotation = -20;
}

void W_Sword_US_MS::run()
{
	cnt++;
	if (cnt <= 15)
	{
		people->v_y = 0;
		
	}
	else
	{
		if (!people->on_floor())
		{
			if (cnt <= 20)
			{
				uarm->rotation += 8;
				larm->rotation += 6;
				wp->rotation += 4;
			}
			people->displace({ 10, -15 });
			people->v_y = 0;
		}

		else
		{
			people->find_and_attack({ {-50,-100},{550,100} }, Damage(people->ATK() * 1), 200, { 70,200 }, 25, 50);
			people->set_ms(people->default_ms);
		}
	}
	
}

void W_Sword_US_MS::unload()
{
	uarm->rotation = 0;
	larm->rotation = 0;
	wp->rotation = 0;
	wp->scale = { 1,1 };
	body->rotation = 0;
	blarm->rotation = 0;
	fuleg->rotation = 0;
	flleg->rotation = 0;
	buleg->rotation = 0;
	blleg->rotation = 0;
	cnt = 0;
}

W_Sword_U::W_Sword_U(Scene* scene, People* people, Weapon* weapon, const ::Config::Skill& con) :
	Skill(scene, people, weapon, con),
	ms(scene, people), ms_us(scene, people), ms_uw(scene, people)
{}

void W_Sword_U::use(bool down, bool up) {
	if (!people->on_floor()) 
	{
		if (down) 
		{
			people->set_ms(&ms_us);
		}
	}
	else 
	{
		if (up)people->set_ms(&ms_uw);
		else people->set_ms(&ms);
	}
}

bool W_Sword_U::can_use(bool down, bool up)
{
	if (!people->on_floor()) 
	{
		if (down) 
		{
			return true;
		}
		else 
		{
			return false;
		}
	}
	else 
	{
		return true;
	}
}

void w_sword_u_init()
{
	Config::Skill skill
	{
		.name = L"",
		.creator = [](const Config::Skill& con,Scene* scene,People* people,Weapon* weapon)->Skill*
		{
			return new W_Sword_U(scene,people,weapon,con);
		}
	};

	skill_table["w_sword_u"] = std::move(skill);
}