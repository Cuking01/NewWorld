#pragma once

W_Sword_Attack_MS::W_Sword_Attack_MS(Scene* scene, People* people) :
	Move_State(scene, people, 100)
{}

void W_Sword_Attack_MS::load()
{
	uarm = &people->armature["front_upper_arm"].bone;
	larm = &people->armature["front_upper_arm"]["front_lower_arm"].bone;
	wp = &people->armature["front_upper_arm"]["front_lower_arm"]["sword"].bone;
	body = &people->armature.bone;
	blarm = &people->armature["back_upper_arm"].bone;
	fuleg = &people->armature["front_upper_leg"].bone;
	flleg = &people->armature["front_upper_leg"]["front_lower_leg"].bone;
	buleg = &people->armature["back_upper_leg"].bone;
	blleg = &people->armature["back_upper_leg"]["back_lower_leg"].bone;

	people->v_y = 0;
	j = 0;
	cnt = 0;
	next_flag = 0;
	uarm->rotation = -45;
	larm->rotation = -45;
	wp->rotation = 0;
	wp->scale = { 1,1 };
}

void W_Sword_Attack_MS::run()
{
	cnt++;

	auto j1 = [this]()
		{
			
			if (cnt <= 20)
			{
				uarm->rotation += 3;
				larm->rotation += 2.5;
			}

			if (cnt == 10)
			{
				people->find_and_attack({ {50,-100},{150,100} }, Damage(people->ATK() * 1.0), 200, { 50,0 }, 25, 50);
			}

			if (cnt == 40)
			{
				if (next_flag)
					j = 1, cnt = 0, next_flag = 0, people->v_y = 0, wp->scale = { 1,1 };
				else
					people->set_ms(people->default_ms);
			}
		};

	auto j2 = [this]()
		{
			if (cnt <= 20)
			{
				uarm->rotation -= 3;
				larm->rotation -= 2.5;
			}

			if (cnt == 10)
			{
				people->find_and_attack({ {50,-100},{150,100} }, Damage(people->ATK() * 1.2), 200, { 50,0 }, 25, 50);
			}

			if (cnt == 40)
			{
				if (next_flag)
					j = 2, cnt = 0, next_flag = 0, people->v_y = 0;
				else
					people->set_ms(people->default_ms);
			}
		};

	auto j3 = [this]()
		{
			if (cnt <= 20)
			{
				uarm->rotation += 3;
				larm->rotation += 2.5;
			}

			if (cnt == 10)
			{
				people->find_and_attack({ {50,-100},{200,100} }, Damage(people->ATK() * 1.5), 200, { 50,0 }, 25, 50);
			}

			if (cnt == 40)
			{
				people->set_ms(people->default_ms);
			}
		};

	if (j == 0)j1();
	else if (j == 1)j2();
	else j3();
}

void W_Sword_Attack_MS::unload()
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
}

void W_Sword_Attack_MS::use_skill(s2 id, bool down, bool up)
{
	if (id == people_skill_num + 0)
	{
		if (j == 0)
		{
			next_flag = 1;

		}
		else if (j == 1)
		{
			next_flag = 1;
		}
	}
	else Move_State::use_skill(id, down, up);
}

W_Sword_Attack_Air_MS::W_Sword_Attack_Air_MS(Scene* scene, People* people) :
	Move_State(scene, people, 100)
{}

void W_Sword_Attack_Air_MS::load()
{
	uarm = &people->armature["front_upper_arm"].bone;
	larm = &people->armature["front_upper_arm"]["front_lower_arm"].bone;
	wp = &people->armature["front_upper_arm"]["front_lower_arm"]["sword"].bone;
	body = &people->armature.bone;
	blarm = &people->armature["back_upper_arm"].bone;
	fuleg = &people->armature["front_upper_leg"].bone;
	flleg = &people->armature["front_upper_leg"]["front_lower_leg"].bone;
	buleg = &people->armature["back_upper_leg"].bone;
	blleg = &people->armature["back_upper_leg"]["back_lower_leg"].bone;

	people->v_y = 0;
	j = 0;
	cnt = 0;
	next_flag = 0;
	uarm->rotation = -45;
	larm->rotation = -45;
	wp->rotation = 0;
	wp->scale = { 1,1 };
}

void W_Sword_Attack_Air_MS::run()
{
	cnt++;
	auto enermies = people->find_enemy({ {50,-100},{150,100} });
	if (!enermies.size())
	{
		people->set_ms(people->default_ms);
	}
	auto j1 = [this]()
		{
			people->v_y = 0;
			if (cnt <= 10)
			{
				uarm->rotation += 6;
				larm->rotation += 5;
			}

			if (cnt == 10)
			{
				people->find_and_attack({ {50,-100},{150,100} }, Damage(people->ATK() * 1.0), 200, { 0,200 }, 25, 50);
			}

			if (cnt == 40)
			{
				if (next_flag)
					j = 1, cnt = 0, next_flag = 0, people->v_y = 0, wp->scale = { 1,1 };
				else
					people->set_ms(people->default_ms);
			}
		};

	auto j2 = [this]()
		{
			people->v_y = 0;
			if (cnt <= 10)
			{
				uarm->rotation -= 6;
				larm->rotation -= 5;
			}

			if (cnt == 10)
			{
				people->find_and_attack({ {50,-100},{150,100} }, Damage(people->ATK() * 1.2), 200, { 0,200 }, 25, 50);
			}

			if (cnt == 40)
			{
				if (next_flag)
					j = 2, cnt = 0, next_flag = 0, people->v_y = 0;
				else
					people->set_ms(people->default_ms);
			}
		};

	auto j3 = [this]()
		{
			people->v_y = 0;
			if (cnt <= 10)
			{
				uarm->rotation += 6;
				larm->rotation += 5;
			}

			if (cnt == 10)
			{
				people->find_and_attack({ {50,-100},{200,100} }, Damage(people->ATK() * 1.5), 200, { 0,200 }, 25, 50);
			}

			if (cnt == 40)
			{
				if (next_flag)
					j = 3, cnt = 0, next_flag = 0, people->v_y = 0;
				else
					people->set_ms(people->default_ms);
			}
		};

	auto j4 = [this]()
		{
			people->v_y = 0;
			if (cnt <= 10)
			{
				uarm->rotation -= 6;
				larm->rotation -= 5;
			}

			if (cnt == 10)
			{
				people->find_and_attack({ {50,-100},{200,100} }, Damage(people->ATK() * 1.5), 200, { 500,2000 }, 25, 50);
			}

			if (cnt == 40)
			{
				people->set_ms(people->default_ms);
			}
		};

	if (j == 0)j1();
	else if (j == 1)j2();
	else if (j == 2)j3();
	else j4();
}

void W_Sword_Attack_Air_MS::unload()
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
}

void W_Sword_Attack_Air_MS::use_skill(s2 id, bool down, bool up)
{
	if (id == people_skill_num + 0)
	{
		if (j == 0)
		{
			next_flag = 1;

		}
		else if (j == 1)
		{
			next_flag = 1;
		}
		else if (j == 2)
		{
			next_flag = 1;
		}
	}
	else Move_State::use_skill(id, down, up);
}
/*===============================================================================*/
W_Sword_Attack::W_Sword_Attack(Scene* scene, People* people, Weapon* weapon, const ::Config::Skill& con) :
	Skill(scene, people, weapon, con),
	ms(scene, people),ms_air(scene, people)
{}

void W_Sword_Attack::use(bool down, bool up)
{
	if (people->on_floor())
	{
		people->set_ms(&ms);
	}
	else
	{
		people->set_ms(&ms_air);
	}
}

void w_sword_attack_init()
{
	Config::Skill skill
	{
		.name = L"",
		.creator = [](const Config::Skill& con,Scene* scene,People* people,Weapon* weapon)->Skill*
		{
			return new W_Sword_Attack(scene,people,weapon,con);
		}
	};

	skill_table["w_sword_attack"] = std::move(skill);
}
