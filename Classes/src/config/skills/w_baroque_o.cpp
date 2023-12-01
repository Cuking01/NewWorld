#pragma once
/*==================================ÉýÁúÈ­=============================================*/
W_Baroque_O_MS::W_Baroque_O_MS(Scene* scene, People* people) :
	Move_State(scene, people, 100)
{
}


void W_Baroque_O_MS::load()
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
	people->v_y = 0;
	cnt = 0;
}

void W_Baroque_O_MS::run()
{
	cnt++;

	if (cnt <= 10) {
		fuarm->rotation += 4.5;
		body->rotation += 1.5;
		h->rotation += 4;
	}

	if (cnt > 10 && cnt <= 20) {
		fuarm->rotation -= 10;
		body->rotation -= 2;
	}

	if (cnt > 20 && cnt <= 30) {
		fuarm->rotation -= 4;
		flarm->rotation += 3;
		fuleg->rotation -= 5;
		flleg->rotation += 8;
		h->rotation -= 7;
	}

	if (cnt == 25) {
		people->find_and_attack({ {50,-100},{200,100} }, Damage(people->ATK() * 1.5), 200, { 30,800 }, 25, 50);
		scene->shake(50);
		people->displace({ 12, 0 });
		people->v_y = 0;
	}

	if (cnt > 35 && cnt <= 45) {
		fuarm->rotation += 9.5;
		flarm->rotation -= 3;
		body->rotation += 0.5;
		fuleg->rotation += 5;
		flleg->rotation -= 8;
		h->rotation += 3;
	}

	if (cnt == 45) {
		people->set_ms(people->default_ms);
	}
}

void W_Baroque_O_MS::unload()
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
	cnt = 0;
}
/*==================================O=============================================*/
W_Baroque_O::W_Baroque_O(Scene* scene, People* people, Weapon* weapon, const ::Config::Skill& con) :
	Skill(scene, people, weapon, con),
	ms(scene, people)
{}

void W_Baroque_O::use(bool down, bool up)
{
	people->set_ms(&ms);
}

bool W_Baroque_O::can_use(bool down, bool up)
{
	if (people->on_floor() && up) {
		return true;
	}
	else return false;
}

void w_baroque_o_init()
{
	Config::Skill skill
	{
		.name = L"",
		.creator = [](const Config::Skill& con,Scene* scene,People* people,Weapon* weapon)->Skill*
		{
			return new W_Baroque_O(scene,people,weapon,con);
		}
	};

	skill_table["w_baroque_o"] = std::move(skill);
}
