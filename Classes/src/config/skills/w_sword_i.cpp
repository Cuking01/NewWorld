#pragma once

W_Sword_I_E_MS::W_Sword_I_E_MS(Scene* scene, People* people) :
	Move_State(scene, people)
{
	cnt = 0;
}

void W_Sword_I_E_MS::run()
{
	cnt++;
	if (cnt > mx)
	{
		people->erase_effect(people->handle);
		return;
	}
	people->displace({14,0});
	
	auto enemy = people->find_enemy({ {-50,-100},{50,100} });
	for (auto p : enemy)
	{
		if (enemy_set.find(p) == enemy_set.end())
		{
			people->attack({ p }, Damage(people->ATK() * 1));
			enemy_set.insert(p);
		}
	}

}


W_Sword_I_MS::W_Sword_I_MS(Scene* scene, People* people) :
	Move_State(scene, people, 100)
{}

void W_Sword_I_MS::load()
{
	cnt = 0;
	uarm = &people->armature["front_upper_arm"].bone;
	larm = &people->armature["front_upper_arm"]["front_lower_arm"].bone;
	wp = &people->armature["front_upper_arm"]["front_lower_arm"]["sword"].bone;
	body = &people->armature.bone;
	buarm = &people->armature["back_upper_arm"].bone;
	blarm = &people->armature["back_upper_arm"]["back_lower_arm"].bone;
	fuleg = &people->armature["front_upper_leg"].bone;
	flleg = &people->armature["front_upper_leg"]["front_lower_leg"].bone;
	buleg = &people->armature["back_upper_leg"].bone;
	blleg = &people->armature["back_upper_leg"]["back_lower_leg"].bone;
	p1 = &people->armature["front_upper_arm"]["front_lower_arm"]["sword"]["i1"].bone;
}

void W_Sword_I_MS::run()
{
	cnt++;
	if (cnt <= 20)
	{
		body->rotation += 1.5;
		fuleg->rotation -= 1.5;
		flleg->rotation += 1;
		buleg->rotation -= 3.5;
		blleg->rotation += 3.5;
		blarm->rotation -= 4.5;
		uarm->rotation += 2;
		wp->rotation += 9;

	}
	if (cnt > 20 && cnt <= 70)
	{
		p1->visible = true;
		p1->opacity = 5*(cnt-20)+5;
	}
	if (cnt == 90)
	{
		p1->visible = false;
	}
	if (cnt >= 90 && cnt <= 150)
	{
		body->rotation -= 1;
		fuleg->rotation += 1;
		flleg->rotation -= 0.67;
		buleg->rotation += 2.33;
		blleg->rotation -= 2.33;
		blarm->rotation += 3;
		uarm->rotation -= 2.8;
		larm->rotation -= 1.47;
		wp->rotation -= 6;
	}

	if (cnt == 120) {
		auto idx = people->create_effect<W_Sword_I_E_MS>({ .bone = {.file_name = "weapon/sword/8",.anchor = {0.55,0.5},.pos = {people->pos.x + 0  ,people->pos.y  },.zorder = 100,.scale = {0.5,0.5}} });
		(static_cast<W_Sword_I_E_MS*>(((People*)idx)->default_ms))->mx = 1;
	}
	if (cnt == 121) {
		auto idx = people->create_effect<W_Sword_I_E_MS>({ .bone = {.file_name = "weapon/sword/7",.anchor = {0.55,0.5},.pos = {people->pos.x + 0  ,people->pos.y  },.zorder = 100,.scale = {0.5,0.5}} });
		(static_cast<W_Sword_I_E_MS*>(((People*)idx)->default_ms))->mx = 1;
	}
	if (cnt == 122) {
		auto idx = people->create_effect<W_Sword_I_E_MS>({ .bone = {.file_name = "weapon/sword/6",.anchor = {0.55,0.5},.pos = {people->pos.x + 0  ,people->pos.y  },.zorder = 100,.scale = {0.5,0.5}} });
		(static_cast<W_Sword_I_E_MS*>(((People*)idx)->default_ms))->mx = 1;
	}
	if (cnt == 123) {
		auto idx = people->create_effect<W_Sword_I_E_MS>({ .bone = {.file_name = "weapon/sword/5",.anchor = {0.55,0.5},.pos = {people->pos.x + 0  ,people->pos.y  },.zorder = 100,.scale = {0.5,0.5}} });
		(static_cast<W_Sword_I_E_MS*>(((People*)idx)->default_ms))->mx = 1;
	}
	if (cnt == 124) {
		auto idx = people->create_effect<W_Sword_I_E_MS>({ .bone = {.file_name = "weapon/sword/4",.anchor = {0.55,0.5},.pos = {people->pos.x + 0  ,people->pos.y  },.zorder = 100,.scale = {0.5,0.5}} });
		(static_cast<W_Sword_I_E_MS*>(((People*)idx)->default_ms))->mx = 1;
	}
	if (cnt == 125) {
		auto idx = people->create_effect<W_Sword_I_E_MS>({ .bone = {.file_name = "weapon/sword/3",.anchor = {0.55,0.5},.pos = {people->pos.x + 0  ,people->pos.y  },.zorder = 100,.scale = {0.5,0.5}} });
		(static_cast<W_Sword_I_E_MS*>(((People*)idx)->default_ms))->mx = 1;
	}
	if (cnt == 126) {
		auto idx = people->create_effect<W_Sword_I_E_MS>({ .bone = {.file_name = "weapon/sword/2",.anchor = {0.55,0.5},.pos = {people->pos.x + 0  ,people->pos.y},.zorder = 100,.scale = {0.5,0.5}} });
		(static_cast<W_Sword_I_E_MS*>(((People*)idx)->default_ms))->mx = 1;
	}
	if (cnt == 127) {
		auto idx = people->create_effect<W_Sword_I_E_MS>({ .bone = {.file_name = "weapon/sword/1",.anchor = {0.55,0.5},.pos = {people->pos.x + 0  ,people->pos.y},.zorder = 100,.scale = {0.5,0.5}} });
		(static_cast<W_Sword_I_E_MS*>(((People*)idx)->default_ms))->mx = 1;
	}
	if (cnt == 128) {
		auto idx = people->create_effect<W_Sword_I_E_MS>({ .bone = {.file_name = "weapon/sword/0",.anchor={0.55,0.5},.pos = {people->pos.x + 0  ,people->pos.y},.zorder = 100,.scale = {0.5,0.5}}});
		(static_cast<W_Sword_I_E_MS*>(((People*)idx)->default_ms))->mx = 250;
	}
	if (cnt == 135)
	{
		people->set_ms(people->default_ms);
	}
}

void W_Sword_I_MS::unload()
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
	p1->visible = false;
	cnt = 0;
}

W_Sword_I::W_Sword_I(Scene* scene, People* people, Weapon* weapon, const ::Config::Skill& con) :
	Skill(scene, people, weapon, con),
	ms(scene, people)
{}

void W_Sword_I::use(bool down, bool up)
{
	if (people->on_floor())people->set_ms(&ms);
}

bool W_Sword_I::can_use(bool down, bool up)
{
	return people->on_floor();
}

void w_sword_i_init()
{
	Config::Skill skill
	{
		.name = L"",
		.creator = [](const Config::Skill& con,Scene* scene,People* people,Weapon* weapon)->Skill*
		{
			return new W_Sword_I(scene,people,weapon,con);
		}
	};

	skill_table["w_sword_i"] = std::move(skill);
}