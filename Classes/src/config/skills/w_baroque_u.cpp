#pragma once
/*==================================ÐÇÂä(Ð±ÏòÏÂ)=============================================*/
W_Baroque_U_MS::W_Baroque_U_MS(Scene* scene, People* people) :
	Move_State(scene, people, 100)
{
}


void W_Baroque_U_MS::load()
{
	fuarm = &people->armature["front_upper_arm"].bone;
	flarm = &people->armature["front_upper_arm"]["front_lower_arm"].bone;
	buarm = &people->armature["back_upper_arm"].bone;
	blarm = &people->armature["back_upper_arm"]["back_lower_arm"].bone;
	fwp = &people->armature["front_upper_arm"]["front_lower_arm"]["baroque_front"].bone;
	bwp = &people->armature["back_upper_arm"]["back_lower_arm"]["baroque_back"].bone;
	body = &people->armature.bone;
	fuleg = &people->armature["front_upper_leg"].bone;
	flleg = &people->armature["front_upper_leg"]["front_lower_leg"].bone;
	buleg = &people->armature["back_upper_leg"].bone;
	blleg = &people->armature["back_upper_leg"]["back_lower_leg"].bone;
	h = &people->armature["head"].bone;

	u[0] = &people->armature["front_upper_leg"]["front_lower_leg"]["u1"].bone;
	u[1] = &people->armature["front_upper_leg"]["front_lower_leg"]["u2"].bone;
	u[2] = &people->armature["front_upper_leg"]["front_lower_leg"]["u3"].bone;
	u[3] = &people->armature["front_upper_leg"]["front_lower_leg"]["u4"].bone;
	u[4] = &people->armature["front_upper_leg"]["front_lower_leg"]["u5"].bone;

	for (int i = 0; i < 5; i++) u[i]->rotation = 55;

	people->v_y = 0;
	cnt = 0;
	s.clear();
}

void W_Baroque_U_MS::run()
{
	cnt++;
	if (cnt <= 5) {
		people->displace({ 0, 30 });
	}
	if (cnt <= 10) {
		fuarm->rotation -= 4.5;
		flarm->rotation += 4;
		body->rotation -= 6;
		h->rotation += 4;
		fuleg->rotation -= 9;
		buleg->rotation -= 4;
		flleg->rotation += 15;
		blleg->rotation += 15;
		people->v_y = 0;
	}

	if (cnt > 15 && cnt <= 20) {
		fuarm->rotation -= 15;
		buarm->rotation -= 15;
		fuleg->rotation += 9;
		flleg->rotation -= 15;
	}

	if (cnt == 20) {
		fuleg->rotation = 0;
		flleg->rotation = 0;
		buleg->rotation = 40;
		blleg->rotation = 90;
		u[0]->visible = true;
	}
	

	if (cnt >= 30) {
		if (cnt % 2 == 0) u[cnt / 2 % 5]->visible = false;
		u[(cnt / 2 + 1) % 5]->visible = true;
		people->displace({10, -10});
		if (cnt & 1) people->find_and_attack({ {50,-100},{200,100} }, Damage(people->ATK() * 1.5), 200, { 50,0 }, 25, 50);
		auto tmp = people->find_enemy({ { 50,-100 }, { 200,100 } });
		for (auto v : tmp) {
			if (s.find(v) == s.end()) {
				people->attack({ v }, Damage(people->ATK() * 1.5), 200, { 50,0 }, 25, 50);
				s.insert(v);
			}
		}
		if (people->on_floor()){
		//if (cnt == 1000) {
			people->set_ms(people->default_ms);
		}
	}
}

void W_Baroque_U_MS::unload()
{
	h->rotation = 0;
	body->rotation = 0;
	fuarm->rotation = -45;
	flarm->rotation = -90;
	buarm->rotation = 0;
	blarm->rotation = -90;
	fuleg->rotation = 0;
	flleg->rotation = 0;
	buleg->rotation = 0;
	blleg->rotation = 0;
	for (int i = 0; i < 5; i++) u[i]->visible = false;
	cnt = 0;
}

W_Baroque_U::W_Baroque_U(Scene* scene, People* people, Weapon* weapon, const ::Config::Skill& con) :
	Skill(scene, people, weapon, con),
	ms(scene, people)
{}

void W_Baroque_U::use(bool down, bool up)
{
	people->set_ms(&ms); 
}

bool W_Baroque_U::can_use(bool down, bool up)
{
	if (!people->on_floor()) {
		return true;
	}
	else return false;
}

void w_baroque_u_init()
{
	Config::Skill skill
	{
		.name = L"",
		.creator = [](const Config::Skill& con,Scene* scene,People* people,Weapon* weapon)->Skill*
		{
			return new W_Baroque_U(scene,people,weapon,con);
		}
	};

	skill_table["w_baroque_u"] = std::move(skill);
}
